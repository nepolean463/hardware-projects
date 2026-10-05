# Safety, Commissioning & Maintenance Guide — 12.8V 100Ah LiFePO4 Power Station

---

## 1. LiFePO4 Chemistry Safety Profile

Lithium Iron Phosphate ($LiFePO_4$) is widely recognized as one of the safest lithium battery chemistries commercially available:

- **Thermal Stability**: Thermal runaway in LiFePO4 does not initiate until temperatures exceed **$270^\circ\text{C} \text{ (}518^\circ\text{F}\text{)}$**, compared to $150^\circ\text{C} - 210^\circ\text{C}$ for standard cobalt-based Lithium-ion ($NMC/LCO$).
- **No Oxygen Release**: The strong covalent bonding of phosphate ($PO_4$) polyanions prevents the release of oxygen during mechanical abuse or overcharging, virtually eliminating spontaneous combustion risks.
- **Cycle Life**: 3,500 to 5,000 cycles at 80% Depth-of-Discharge (DoD), retaining $>80\%$ original capacity after 8–10 years of typical daily cycle usage.

> [!CAUTION]
> **Sub-Zero Charging Prohibition**: Never charge a LiFePO4 battery when the internal cell temperature is below **$0^\circ\text{C} \text{ (}32^\circ\text{F}\text{)}$**. Sub-zero charging causes irreversible lithium metal plating on the graphite anode, inducing internal micro-shorts and permanent capacity destruction. Discharging below freezing (down to $-20^\circ\text{C}$) is safe, but charging is strictly forbidden unless the pack features internal heating pads.

---

## 2. Pre-Commissioning "Zero-Smoke" Protocol

Before inserting any fuses or attaching expensive laptops, execute this step-by-step verification protocol using an accurate Digital Multimeter (DMM):

### Phase 1: Cold Mechanical & Impedance Inspection (System OFF)
1. **Pull All Fuses**: Remove all blade fuses from the 6-way fuse block. Set the 40A inverter breaker to **TRIPPED / OFF**. Rotate the main battery isolator switch to **OFF**.
2. **Lug Pull Test**: Grasp every crimped ring terminal and pull firmly with ~15–20 kg of force. If any conductor shifts inside the barrel, re-crimp immediately with the correct die size.
3. **Continuity & Short-Circuit Check**:
   - Set DMM to Continuity Mode (Beeper).
   - Place Red probe on the Fuse Block Positive Busbar and Black probe on the Negative Busbar.
   - **Expected Result**: Multimeter must remain silent (Open Circuit / $\text{M}\Omega$ resistance). If it beeps, locate and rectify the dead short before proceeding!
   - Test between the Inverter Line-side (+) and (-). Resistance should register high ($>100\text{k}\Omega$).

### Phase 2: High-Current Primary Bus Energization
1. **Install Master 50A Fuse**: Fasten the 50A MIDI/MRBF fuse on the battery (+) post. Tighten terminal nuts to $8.5\text{ N}\cdot\text{m}$.
2. **Voltage Check at Isolator Input**:
   - Measure DC Voltage between Isolator Switch Input Stud and Battery Negative Post.
   - **Expected Reading**: Between $12.8V$ and $13.4V$.
3. **Turn Isolator Switch ON**:
   - Measure DC Voltage at the Fuse Block Positive Busbar to Negative Busbar.
   - **Expected Reading**: Identical to battery voltage ($12.8V - 13.4V$).
   - Verify that the Current Shunt display lights up and indicates $0.00\text{A}$ current draw (idle meter draw $<30\text{mA}$).

### Phase 3: Individual Branch Circuit Verification
Insert branch fuses one by one, verifying operation sequentially:

#### Test 1: 12V Router Line
- Insert **3A Blade Fuse** into Slot 3.
- Measure DC Voltage on the 5.5x2.1mm DC barrel connector with DMM test probes:
  - Center pin: Positive (+)
  - Outer barrel: Negative (-)
  - **Expected Reading**: $12.00V \pm 0.10V$.
- Connect dummy load (e.g., 12V 21W automotive bulb or 10-ohm power resistor) for 3 minutes. Verify stable voltage and check module temperature with fingertips.

#### Test 2: SW3518S Fast-Charge Module
- Insert **7.5A Blade Fuse** into Slot 2.
- Verify module onboard LED illuminates.
- Plug in a USB power meter and test smartphone. Verify negotiation into fast-charge mode (9V/2A or 12V/1.5A).

#### Test 3: IP2368 100W USB-PD Module (Crucial Test)
- Insert **15A Blade Fuse** into Slot 1.
- Connect a USB-C Power Delivery Analyzer / Trigger or an inexpensive test power bank.
- Verify 5V default broadcast.
- Plug into the HP EliteBook 840. Check Windows battery tray icon: verify it indicates **"Plugged in, charging"** without warnings.
- Check the battery monitor display: current draw should read approximately **$3.0\text{A} - 5.5\text{A}$** depending on laptop battery state.

#### Test 4: 300W AC Inverter
- Ensure all inverter AC output loads are disconnected.
- Reset/Engage the **40A DC Breaker**.
- Turn on the Inverter rocker switch.
- Verify green "Normal / Power" LED lights up (no red fault LED or continuous audible beeper).
- Set DMM to **AC Voltage Mode** ($750V \text{ AC}$).
- Probe the AC socket:
  - Line to Neutral: **$230V \pm 10V \text{ AC}$**.
  - Neutral to Earth: **$< 2V \text{ AC}$**.
- Plug in a 60W incandescent lamp or 40W soldering iron. Verify smooth, buzz-free operation.

---

## 3. Battery Shunt Monitor Calibration (TF03K / PZEM-015)

Voltage-based fuel gauges are inaccurate for LiFePO4 batteries because the voltage remains nearly flat (between 13.1V and 13.3V) for over 70% of the discharge cycle. A precision current shunt measuring milliamp-seconds (Coulomb counting) is mandatory:

```text
       LiFePO4 Discharge Curve (Very Flat Voltage vs SoC)
  14.6V ┌─                               (Bulk Charge Peak)
        │ ╲
  13.4V │   ┌────────────────────────┐   (Resting 100%)
  13.2V │   │                        │
  13.0V │   │   WORKING PLATEAU      │   (75% of usable energy)
  12.8V │   │   (Voltage flat!)      │
  12.0V │   │                        │
  11.5V │   └────────────────────────┘   (Knee point / ~15% left)
  10.0V └───                          ╲_ (BMS Low Voltage Cutoff)
        0%             50%            100%
```

### Initial Calibration Steps:
1. Connect the power station to the 14.6V AC smart charger via the Anderson SB50 port.
2. Allow the charger to run until the charger LED switches from Red (Charging) to Green (Float/Finished).
3. The battery voltage should reach $\approx 14.4V - 14.6V$ and current should drop below $1.0\text{A}$.
4. On the display unit, enter programming mode:
   - Set **Battery Rated Capacity**: `100.0 Ah`.
   - Set **High Voltage Alarm**: `14.4 V`.
   - Set **Low Voltage Alarm**: `11.5 V`.
5. Hold the **100% / Reset** button for 3 seconds until the display shows $100\%$ and $100.0\text{Ah}$.

---

## 4. Maintenance & Storage Best Practices

| Interval | Inspection Task | Acceptable Metric | Corrective Action |
|---|---|---|---|
| **Monthly** | Visual inspection of terminals & fuse blocks | No discoloration, oxidation, or heat deformation | Clean contacts with isopropyl alcohol; replace discolored terminals |
| **Quarterly** | Terminal torque verification | M8: 8.5 N·m; M6: 5.0 N·m | Re-torque loose fasteners to prevent contact resistance |
| **Biannual** | Capacity benchmark test | Discharge at constant ~15A to 11.5V; verify $>85\text{Ah}$ | Rebalance pack with a prolonged 14.6V slow charge |
| **Long-Term Storage** | Storing unused for $> 2$ months | State of Charge between **50% and 60%** ($13.2V$) | Discharge to 50% SoC; switch Master Disconnect **OFF** |

> [!TIP]
> **Storage Rule**: Never store a LiFePO4 battery at 100% SoC for prolonged periods in warm environments (>30°C), and never store it completely empty (0% SoC). Storing at 50–60% SoC in a cool room minimizes calendar aging.
