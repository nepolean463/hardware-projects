/*
  ESP32 LiFePO4 BMS voltage monitor with optional inverter control outputs.

  IMPORTANT SAFETY NOTES
  - This is a Modbus RTU/RS-485 example, not a universal BMS driver. Verify your
    BMS protocol, register address, function (input/holding), baud/parity, and
    scaling from its manual before use. The defaults below are placeholders.
  - Relay control is DISABLED by default. Keep it disabled until the register
    mapping, thresholds, relay polarity, and inverter interface are verified.
  - Use isolated, appropriately rated contactors/relay modules and only switch
    the inverter's documented low-voltage remote-control/dry-contact inputs.
    Do not use an ESP32 or small relay board to interrupt battery or AC power.
  - Keep the BMS's own protections enabled. This voltage logic is not a
    substitute for cell-level over/under-voltage, overcurrent, temperature,
    fusing, emergency-stop, and inverter protections.

  Libraries: ModbusMaster (install via Arduino Library Manager)
  Board: ESP32 Arduino core
*/

#include <Arduino.h>
#include <ModbusMaster.h>

// -------- Hardware configuration (check your ESP32 board pinout) --------
static constexpr int RS485_RX_PIN = 16;
static constexpr int RS485_TX_PIN = 17;
static constexpr int RS485_DE_RE_PIN = 4;  // tie DE and /RE together on many transceivers
static constexpr int CHARGE_RELAY_PIN = 25;
static constexpr int INVERTER_RELAY_PIN = 26;

// Set this to LOW for an active-low relay module, HIGH for active-high.
static constexpr uint8_t RELAY_ACTIVE_LEVEL = HIGH;
static constexpr uint8_t RELAY_INACTIVE_LEVEL =
    (RELAY_ACTIVE_LEVEL == HIGH) ? LOW : HIGH;

// -------- BMS Modbus configuration: MUST be verified for your BMS --------
static constexpr uint32_t BMS_BAUD = 9600;
static constexpr uint8_t BMS_SLAVE_ID = 1;
static constexpr uint8_t BMS_SERIAL_CONFIG = SERIAL_8N1; // Change if manual specifies otherwise.

// Set the correct register address from your BMS manual. 0xFFFF intentionally
// means "not configured"; this sketch will not operate relays in that state.
static constexpr uint16_t PACK_VOLTAGE_REGISTER = 0xFFFF;
static constexpr bool PACK_VOLTAGE_IS_INPUT_REGISTER = true; // false = holding register
// Example only: raw 5200 * 0.01 = 52.00 V. Check the BMS manual.
static constexpr float PACK_VOLTAGE_VOLTS_PER_COUNT = 0.01f;

// -------- Relay control configuration --------
// Leave false until all settings and hardware have been verified.
static constexpr bool ENABLE_RELAY_CONTROL = false;

// Configure for your battery/inverter manufacturer and system design.
// Zero/invalid or overlapping thresholds prevent relay operation.
static constexpr float CHARGE_ENABLE_BELOW_V = 0.0f;
static constexpr float CHARGE_DISABLE_ABOVE_V = 0.0f;
static constexpr float INVERTER_ENABLE_ABOVE_V = 0.0f;
static constexpr float INVERTER_DISABLE_BELOW_V = 0.0f;

static constexpr uint32_t POLL_INTERVAL_MS = 1000;
static constexpr uint32_t MAX_DATA_AGE_MS = 3000;

HardwareSerial BmsSerial(2);
ModbusMaster bms;

bool chargeEnabled = false;
bool inverterEnabled = false;
bool haveGoodReading = false;
float packVoltageV = NAN;
uint32_t lastGoodReadingMs = 0;
uint32_t lastPollMs = 0;

void preTransmission() {
  digitalWrite(RS485_DE_RE_PIN, HIGH);
}

void postTransmission() {
  digitalWrite(RS485_DE_RE_PIN, LOW);
}

void setRelay(int pin, bool enabled) {
  digitalWrite(pin, enabled ? RELAY_ACTIVE_LEVEL : RELAY_INACTIVE_LEVEL);
}

void allOutputsOff() {
  chargeEnabled = false;
  inverterEnabled = false;
  setRelay(CHARGE_RELAY_PIN, false);
  setRelay(INVERTER_RELAY_PIN, false);
}

bool thresholdsAreValid() {
  return CHARGE_ENABLE_BELOW_V > 0.0f &&
         CHARGE_DISABLE_ABOVE_V > CHARGE_ENABLE_BELOW_V &&
         INVERTER_DISABLE_BELOW_V > 0.0f &&
         INVERTER_ENABLE_ABOVE_V > INVERTER_DISABLE_BELOW_V;
}

bool readPackVoltage(float &voltageV) {
  if (PACK_VOLTAGE_REGISTER == 0xFFFF ||
      PACK_VOLTAGE_VOLTS_PER_COUNT <= 0.0f) {
    return false;
  }

  uint8_t result;
  if (PACK_VOLTAGE_IS_INPUT_REGISTER) {
    result = bms.readInputRegisters(PACK_VOLTAGE_REGISTER, 1);
  } else {
    result = bms.readHoldingRegisters(PACK_VOLTAGE_REGISTER, 1);
  }
  if (result != bms.ku8MBSuccess) {
    Serial.printf("BMS Modbus read failed (code 0x%02X)\n", result);
    return false;
  }

  const uint16_t raw = bms.getResponseBuffer(0);
  voltageV = static_cast<float>(raw) * PACK_VOLTAGE_VOLTS_PER_COUNT;
  return isfinite(voltageV) && voltageV > 0.0f;
}

void updateRelays(float voltageV) {
  if (!ENABLE_RELAY_CONTROL || !thresholdsAreValid()) {
    allOutputsOff();
    return;
  }

  // Hysteresis prevents rapid relay chatter near a threshold.
  if (!chargeEnabled && voltageV <= CHARGE_ENABLE_BELOW_V) {
    chargeEnabled = true;
  } else if (chargeEnabled && voltageV >= CHARGE_DISABLE_ABOVE_V) {
    chargeEnabled = false;
  }

  if (!inverterEnabled && voltageV >= INVERTER_ENABLE_ABOVE_V) {
    inverterEnabled = true;
  } else if (inverterEnabled && voltageV <= INVERTER_DISABLE_BELOW_V) {
    inverterEnabled = false;
  }

  setRelay(CHARGE_RELAY_PIN, chargeEnabled);
  setRelay(INVERTER_RELAY_PIN, inverterEnabled);
}

void setup() {
  // Set output latches to the inactive level before enabling output mode.
  digitalWrite(CHARGE_RELAY_PIN, RELAY_INACTIVE_LEVEL);
  digitalWrite(INVERTER_RELAY_PIN, RELAY_INACTIVE_LEVEL);
  pinMode(CHARGE_RELAY_PIN, OUTPUT);
  pinMode(INVERTER_RELAY_PIN, OUTPUT);
  allOutputsOff();

  pinMode(RS485_DE_RE_PIN, OUTPUT);
  digitalWrite(RS485_DE_RE_PIN, LOW); // receive mode

  Serial.begin(115200);
  BmsSerial.begin(BMS_BAUD, BMS_SERIAL_CONFIG, RS485_RX_PIN, RS485_TX_PIN);
  bms.begin(BMS_SLAVE_ID, BmsSerial);
  bms.preTransmission(preTransmission);
  bms.postTransmission(postTransmission);

  Serial.println("ESP32 BMS monitor started; relay control defaults to OFF.");
  if (PACK_VOLTAGE_REGISTER == 0xFFFF) {
    Serial.println("Configure PACK_VOLTAGE_REGISTER from the BMS manual.");
  }
  if (ENABLE_RELAY_CONTROL && !thresholdsAreValid()) {
    Serial.println("Invalid voltage thresholds; relay control will remain OFF.");
  }
}

void loop() {
  const uint32_t now = millis();

  if (static_cast<uint32_t>(now - lastPollMs) >= POLL_INTERVAL_MS) {
    lastPollMs = now;
    float newVoltageV;
    if (readPackVoltage(newVoltageV)) {
      packVoltageV = newVoltageV;
      lastGoodReadingMs = now;
      haveGoodReading = true;
      Serial.printf("Pack voltage: %.2f V\n", packVoltageV);
    } else {
      // Fail safe immediately on a communication/configuration/read error.
      haveGoodReading = false;
      allOutputsOff();
    }
  }

  const bool dataIsFresh = haveGoodReading &&
      static_cast<uint32_t>(now - lastGoodReadingMs) <= MAX_DATA_AGE_MS;
  if (!dataIsFresh) {
    allOutputsOff();
  } else {
    updateRelays(packVoltageV);
  }

  delay(10);
}
