# Wiring & Schematics Guide — 12.8V 100Ah LiFePO4 Power Station

This guide details the complete point-to-point electrical schematic, conductor sizing rules, crimping protocols, and terminal assignments.

---

## 1. Complete Point-to-Point Wiring Schedule

| Connection ID | From (Source Node) | To (Destination Node) | Wire Gauge | Color | Terminal Type (Source) | Terminal Type (Dest) | Inline Protection |
|:---:|---|---|:---:|:---:|:---:|:---:|:---:|
| **P-01** | Battery Positive Terminal | 50A Master Fuse Block | 6 AWG (16 mm²) | Red | SC16-8 Ring Lug (M8) | SC16-8 Ring Lug (M8) | 50A MIDI / MRBF Fuse |
| **P-02** | Master Fuse Output | Isolator Switch (Line In) | 6 AWG (16 mm²) | Red | SC16-8 Ring Lug (M8) | SC16-8 Ring Lug (M8) | Protected by 50A Master |
| **P-03** | Isolator Switch (Load Out) | 40A Inverter Breaker (Line) | 8 AWG (10 mm²) | Red | SC16-8 Ring Lug (M8) | SC10-6 Ring Lug (M6) | 40A DC Breaker |
| **P-04** | 40A Inverter Breaker (Load) | 300W Inverter DC Input (+) | 8 AWG (10 mm²) | Red | SC10-6 Ring Lug (M6) | M6 Ring Lug or Binding Post | Protected by 40A Breaker |
| **P-05** | Isolator Switch (Load Out) | 6-Way Fuse Block Positive Bus | 8 AWG (10 mm²) | Red | SC16-8 Ring Lug (M8) | SC10-6 Ring Lug (M6) | Protected by 50A Master |
| **P-06** | Fuse Block Branch 1 (15A) | IP2368 100W PD Module (IN+) | 14 AWG (2.5 mm²) | Red | Insulated Fork / Spade Terminal | Direct Solder / Screw Terminal | 15A Blade Fuse |
| **P-07** | Fuse Block Branch 2 (7.5A) | SW3518S Module (IN+) | 16 AWG (1.5 mm²) | Red | Insulated Fork / Spade Terminal | Direct Solder / Screw Terminal | 7.5A Blade Fuse |
| **P-08** | Fuse Block Branch 3 (3A) | 12V Buck-Boost Module (IN+) | 18 AWG (0.75 mm²) | Red | Insulated Fork / Spade Terminal | Screw Terminal | 3A Blade Fuse |
| **P-09** | 12V Buck-Boost Module (OUT+) | 5.5x2.1mm DC Barrel Jack (Center) | 18 AWG (0.75 mm²) | Red | Screw Terminal / Solder | Solder Eyelet (Center Pin) | Module Current Limit |
| **P-10** | Fuse Block Branch 4 (10A) | 12V Cigarette Socket (+) | 14 AWG (2.5 mm²) | Red | Insulated Fork / Spade Terminal | 6.3mm Female Quick Disconnect | 10A Blade Fuse |
| **P-11** | Fuse Block Branch 5 (2A) | Shunt Meter Power (V+) | 22 AWG (0.34 mm²) | Red | Insulated Fork / Spade Terminal | JST / Screw Terminal | 2A Blade Fuse |
| **P-12** | Isolator Switch (Load Out) | Anderson SB50 Charge Port (+) | 10 AWG (6.0 mm²) | Red | SC10-8 Ring Lug | SB50 Crimp Contact Pin | 25A In-line Fuse |
| **N-01** | Battery Negative Terminal | Current Shunt (`B-` Terminal) | 6 AWG (16 mm²) | Black | SC16-8 Ring Lug (M8) | SC16-8 Ring Lug (M8) | **DIRECT ONLY (No branching!)** |
| **N-02** | Current Shunt (`P-` Terminal) | Negative Busbar / Common Ground | 6 AWG (16 mm²) | Black | SC16-8 Ring Lug (M8) | SC16-8 Ring Lug (M8) | Shunt Return |
| **N-03** | Negative Busbar | 300W Inverter DC Input (-) | 8 AWG (10 mm²) | Black | SC10-6 Ring Lug (M6) | M6 Ring Lug or Binding Post | Inverter Ground Return |
| **N-04** | Negative Busbar | 6-Way Fuse Block Negative Bus | 8 AWG (10 mm²) | Black | SC10-6 Ring Lug (M6) | SC10-6 Ring Lug (M6) | DC Subsystem Return Bus |
| **N-05** | Fuse Block Negative Bus | IP2368 100W PD Module (IN-) | 14 AWG (2.5 mm²) | Black | Insulated Fork / Spade Terminal | Direct Solder / Screw Terminal | Branch Negative |
| **N-06** | Fuse Block Negative Bus | SW3518S Module (IN-) | 16 AWG (1.5 mm²) | Black | Insulated Fork / Spade Terminal | Direct Solder / Screw Terminal | Branch Negative |
| **N-07** | Fuse Block Negative Bus | 12V Buck-Boost Module (IN-) | 18 AWG (0.75 mm²) | Black | Insulated Fork / Spade Terminal | Screw Terminal | Branch Negative |
| **N-08** | 12V Buck-Boost Module (OUT-) | 5.5x2.1mm DC Barrel Jack (Ring) | 18 AWG (0.75 mm²) | Black | Screw Terminal / Solder | Solder Eyelet (Outer Ring) | Common Negative |
| **N-09** | Fuse Block Negative Bus | 12V Cigarette Socket (-) | 14 AWG (2.5 mm²) | Black | Insulated Fork / Spade Terminal | 6.3mm Female Quick Disconnect | Branch Negative |
| **N-10** | Negative Busbar | Anderson SB50 Charge Port (-) | 10 AWG (6.0 mm²) | Black | SC10-6 Ring Lug | SB50 Crimp Contact Pin | Charge Return |
| **G-01** | Inverter Chassis Ground Pin | Enclosure Internal Earthing / AC Ground | 14 AWG (2.5 mm²) | Green/Yellow | M4 Ring Lug | AC Socket Earth Pin (center) | Chassis Bonding |

---

## 2. High-Side vs Low-Side Protection Architecture

### Master Fuse Placement
The **50A MIDI / MRBF Master Fuse** is installed on the **Positive terminal** of the battery.
- Maximum cable length from battery post to fuse: **180 mm (7 inches)**.
- Function: Protects against catastrophic dead shorts in the main 6 AWG trunk line, switch contacts, or inverter input stages.

### Shunt Sampler Placement (Golden Rule)
The **Current Shunt** is placed on the **Low-Side (Negative)** line:
```text
[Battery B-] ────(6 AWG)────> [Shunt B-] ──[Manganin Resistor]──> [Shunt P-] ────(6 AWG)────> [Common Negative Busbar]
```
> [!CAUTION]
> **Zero Bypass Rule**: Absolutely **NO** negative returns may connect directly to the battery negative terminal `B-`. If an accessory ground bypasses the shunt and connects to `B-`, its current draw will **not** be recorded by the Coulomb counter, resulting in cumulative state-of-charge drift and false capacity readings.

---

## 3. High-Power DC-DC Buck-Boost Module (IP2368) Pinout & Thermal Care

The **IP2368** is a 4-switch synchronous buck-boost controller capable of delivering 100W (20V @ 5A) over USB Type-C:

```text
               +--------------------------------------+
               |          IP2368 100W MODULE          |
 [12V IN +] -->| VIN+                            VBUS |--> [USB Type-C Receptacle]
 [12V IN -] -->| VIN-                            GND  |--> [To Laptop]
               |                                      |
               |      [4x Power MOSFETs + Inductor]   |
               |      [Aluminum Heatsink on Top]      |
               +--------------------------------------+
```

### Essential Assembly Rules for IP2368:
1. **Input Wire Gauge**: Never use wire thinner than **14 AWG (2.5 mm²)** for the 12V input leads. At 100W output, when battery voltage drops to 11.5V, input current exceeds **9.2 Amps**. Undersized wires will cause excessive voltage sag, tripping the module's undervoltage lockout.
2. **Thermal Dissipation**: While the IP2368 has an impressive ~94% efficiency, at 100W sustained load it dissipates $\approx 6\text{ to }7\text{ Watts}$ of heat. Affix an anodized aluminum finned heatsink using high-thermal-conductivity silicone pads. If mounted inside an airtight enclosure, ensure proximity to ventilation slots or install a 60mm 12V exhaust fan.

---

## 4. Router 12V Line Voltage Regulation

Residential Wi-Fi routers and GPON Optical Network Terminals (ONT) are vulnerable to voltage spikes:

```text
[12.8V Battery] ──> [Fuse 3A] ──> [Auto Buck-Boost LTC3780/XL6009] ──(Fixed 12.0V)──> [5.5x2.1mm DC Plug]
                                         │
                                [Trimmed via 10k Pot]
```

### Calibration Procedure for Buck-Boost:
1. Connect module input to the 12V DC fuse block.
2. Leave output disconnected from the router.
3. Turn on the main battery switch.
4. Using a digital multimeter probes on `OUT+` and `OUT-`, adjust the precision multi-turn potentiometer until the multimeter reads **$12.05V \text{ DC}$**.
5. Seal the potentiometer screw with a dab of silicone sealant or hot glue to prevent vibration-induced drift.
6. Verify polarity on the 5.5x2.1mm barrel connector:
   - **Inner Center Pin: POSITIVE (+)**
   - **Outer Sleeve: NEGATIVE (-)**

---

## 5. Crimping & Assembly Standards

- **Hydraulic or Mechanical Hex Crimp**: All 6 AWG and 8 AWG copper tube lugs (SC series) must be crimped with a specialized hex die tool (e.g., HX-50B). Pliers, vise grips, or hammer strikes are prohibited as they leave internal air gaps causing resistive heating under load.
- **Dual-Wall Adhesive Heatshrink**: Every crimped lug collar must be insulated with 3:1 dual-wall heatshrink extending at least 15mm over the cable jacket and over the lug barrel.
- **Torque Specifications**:
  - M8 Battery Post Studs: **8.0 to 9.5 N·m (70 to 84 in-lb)**.
  - M8 Isolator Switch Studs: **8.0 N·m**.
  - M6 Inverter & Breaker Studs: **4.5 to 5.5 N·m (40 to 48 in-lb)**.
  - Fuse Block Screw Terminals: **1.5 N·m (13 in-lb)**.
