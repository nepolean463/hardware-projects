# Runtime & Efficiency Calculations — 12.8V 100Ah LiFePO4 Power Station

This document details the mathematical models, thermodynamic efficiency comparisons, and power budgets governing the power station design.

---

## 1. Battery Usable Energy Budget

### LiFePO4 Nominal Capacity
$$\text{Nominal Energy} (E_{\text{nom}}) = V_{\text{nom}} \times C_{\text{nom}} = 12.8\text{ V} \times 100\text{ Ah} = 1,280\text{ Wh}$$

Unlike lead-acid batteries governed by Peukert's Law ($k \approx 1.25$), where discharging at higher currents drastically reduces available capacity, LiFePO4 exhibits a Peukert exponent of **$k \approx 1.01 - 1.03$**. This means virtually all 100Ah is extractable regardless of whether discharge occurs at 5A or 40A.

### Practical Depth of Discharge (DoD)
To ensure the battery achieves **$>3,500\text{ cycles}$** before reaching 80% state of health, we set the operational discharge floor at **85% Depth-of-Discharge**:

$$E_{\text{usable}} = 1,280\text{ Wh} \times 0.85 = \mathbf{1,088\text{ Wh}}$$

---

## 2. Efficiency Comparison: Native DC vs. AC Inverter

The primary design principle of this DIY power station is **DC-native power delivery**. The mathematical justification is demonstrated below for powering an **HP EliteBook 840** laptop requiring an average of **35W DC** power:

```text
PATHWAY A: INVERTER CONVERSION (Inefficient)
[12.8V Battery] ────(η1 ≈ 88%)────> [300W Inverter (230V AC)] ────(η2 ≈ 85%)────> [HP 65W AC Adapter] ────> [Laptop (20V DC)]
      │                                                                                  │
  Battery DC                                                                         Final DC
  Total Efficiency: η_total = 0.88 * 0.85 = 74.8%
  Standby Idle Penalty: +5.5W constant inverter quiescent draw

PATHWAY B: NATIVE DC-DC BUCK-BOOST (Optimal)
[12.8V Battery] ────────────────────────(η ≈ 94%)────────────────────────> [IP2368 Module (20V PD)] ────> [Laptop (20V DC)]
  Total Efficiency: η_total = 94.0%
  Standby Quiescent Draw: < 0.15W
```

### Mathematical Comparison

#### Case 1: Powering via 230V AC Inverter
$$\text{Load Power} (P_{\text{load}}) = 35\text{ W}$$
$$\text{Adapter Efficiency} (\eta_{\text{adapter}}) = 0.85 \implies P_{\text{AC}} = \frac{35\text{ W}}{0.85} = 41.18\text{ W}$$
$$\text{Inverter Efficiency} (\eta_{\text{inv}}) = 0.88$$
$$\text{Inverter Idle Power} (P_{\text{idle}}) = 5.5\text{ W}$$
$$P_{\text{battery, AC}} = \frac{P_{\text{AC}}}{\eta_{\text{inv}}} + P_{\text{idle}} = \frac{41.18\text{ W}}{0.88} + 5.5\text{ W} = 46.80\text{ W} + 5.5\text{ W} = \mathbf{52.3\text{ W}}$$

$$\text{Runtime}_{\text{AC}} = \frac{E_{\text{usable}}}{P_{\text{battery, AC}}} = \frac{1,088\text{ Wh}}{52.3\text{ W}} \approx \mathbf{20.8\text{ Hours}}$$

#### Case 2: Powering via Native IP2368 DC-DC Buck-Boost
$$\text{Buck-Boost Efficiency} (\eta_{\text{DC}}) = 0.94$$
$$P_{\text{battery, DC}} = \frac{P_{\text{load}}}{\eta_{\text{DC}}} = \frac{35\text{ W}}{0.94} = \mathbf{37.23\text{ W}}$$

$$\text{Runtime}_{\text{DC}} = \frac{E_{\text{usable}}}{P_{\text{battery, DC}}} = \frac{1,088\text{ Wh}}{37.23\text{ W}} \approx \mathbf{29.2\text{ Hours}}$$

$$\text{Runtime Gain} = \frac{29.2 - 20.8}{20.8} \times 100\% = \mathbf{+40.4\%\text{ Increase in Runtime!}}$$

When the laptop is running on light tasks (e.g. reading docs, 18W draw), the inverter idle penalty dominates, and the DC-native pathway yields **$>65\%$ longer battery runtime**.

---

## 3. Wi-Fi Router Runtime Calculations

A typical dual-band Wi-Fi 6 router + Optical Network Terminal (ONT) consumes between **$10\text{W}$ and $14\text{W}$** (nominal average $12\text{W}$):

$$P_{\text{battery, router}} = \frac{12\text{ W}}{0.92\text{ (regulator efficiency)}} = 13.04\text{ W}$$

$$\text{Continuous Wi-Fi Runtime} = \frac{1,088\text{ Wh}}{13.04\text{ W}} = \mathbf{83.4\text{ Hours}} \approx \mathbf{3.5\text{ Days Continuous}}$$

During prolonged regional power outages, internet and home LAN connectivity can be sustained for half a week uninterrupted.

---

## 4. Combined Workstation Operating Profile

Simulating an intense 8-hour workday scenario:
- **HP EliteBook 840**: Active office work, video conferencing (35W continuous, 8 hours) $\rightarrow 280\text{ Wh}$
- **Wi-Fi Router & ONT**: 24-hour continuous operation (12W continuous, 24 hours) $\rightarrow 288\text{ Wh}$
- **2x Smartphones**: Full fast-charge cycles (2 x 18.5 Wh / 0.90) $\rightarrow 41\text{ Wh}$
- **LED Work Light**: 5W DC lamp for evening work (4 hours) $\rightarrow 20\text{ Wh}$
- **Total Daily Consumption**: $\mathbf{629\text{ Wh}}$

$$\text{Daily Battery Reserve Remaining} = 1,088\text{ Wh} - 629\text{ Wh} = 459\text{ Wh (42% capacity remaining)}$$

The 1280Wh system provides **nearly two full consecutive days** of total workstation autonomy without requiring any recharge.

---

## 5. Conductor Voltage Drop Calculations

Voltage drop across a direct current conductor is determined by Ohm's Law:

$$V_{\text{drop}} = 2 \times L \times I \times \frac{R}{1000}$$

Where:
- $L$ = one-way conductor length in meters.
- $I$ = maximum continuous current in Amperes.
- $R$ = conductor resistance in $\Omega / \text{km}$ at $20^\circ\text{C}$.

### Main Battery Trunk Line (6 AWG / 16 mm², 0.5m length, 50A peak current)
- $R_{\text{6 AWG}} \approx 1.30\text{ m}\Omega / \text{m}$
- $V_{\text{drop}} = 2 \times 0.5\text{ m} \times 50\text{ A} \times 0.00130\text{ }\Omega/\text{m} = \mathbf{0.065\text{ V}}$
- Percentage Drop at 12.8V:

$$\% V_{\text{drop}} = \frac{0.065\text{ V}}{12.8\text{ V}} \times 100\% = \mathbf{0.51\%} \quad (\text{Well within marine/military standard of } < 3\%)$$
