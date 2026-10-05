# Bill of Materials (BOM) — 12.8V 100Ah LiFePO4 DIY Power Station

This document contains the complete, itemized Bill of Materials (BOM) required to construct the **12.8V 100Ah LiFePO4 DIY Power Station**.

---

## 1. Core Battery & Management System

| Ref | Item Description | Detailed Technical Specifications | Qty | Recommended Make / Model | Sourcing Options | Est. Price (USD / INR) | Critical Notes |
|:---:|---|---|:---:|---|---|:---:|---|
| **BAT-01** | LiFePO4 Battery Pack (12.8V 100Ah) | 4S LFP chemistry, 1280Wh capacity, internal 50A/100A BMS, M8 female/male copper threaded terminals, built-in low/high voltage and thermal cutoffs. | 1 | Eco-Worthy 12V 100Ah / Redodo / Ampere Time / Indian EV LFP Pack | Amazon, Robu.in, local battery distributors | $200 - $240 / ₹15,500 - ₹19,000 | Look for Grade-A prismatic cells with welded busbars inside an ABS casing. Ensure internal BMS supports at least 50A continuous discharge. |
| **BAT-02** | Dedicated LiFePO4 Smart Charger | 14.6V DC output (CC/CV charging profile), 10A to 20A charging current, Anderson SB50 or alligator clip output, active fan cooling. | 1 | 14.6V 10A/20A LiFePO4 Charger | Amazon, Robu.in, AliExpress | $32 - $48 / ₹2,400 - ₹3,600 | **Do NOT** use a standard lead-acid charger. Lead-acid chargers apply desulfation pulses and incorrect float voltages that degrade LiFePO4 cells. |

---

## 2. Inverter & AC Distribution Subsystem

| Ref | Item Description | Detailed Technical Specifications | Qty | Recommended Make / Model | Sourcing Options | Est. Price (USD / INR) | Critical Notes |
|:---:|---|---|:---:|---|---|:---:|---|
| **INV-01** | 300W Pure Sine Wave Inverter | 12V DC input (10.5V - 15.5V), 230V AC ±5% 50Hz output, 300W continuous / 600W peak surge, Pure Sine Wave (<3% THD), idle current < 0.45A, thermal fan. | 1 | Bestek 300W Pure Sine / Luminous / Su-Kam / Generic Pure Sine 300W | Amazon, Electronics stores | $40 - $55 / ₹3,200 - ₹4,400 | Must be **Pure Sine Wave** to safely power laptop adapters, monitors, and sensitive audio/lab equipment without buzzing or overheating. |
| **INV-02** | 40A DC Resettable Circuit Breaker | 12V-48V DC rated, 40A thermal-magnetic trip, manual push-to-trip lever (serves as power switch), surface mount, M6 studs. | 1 | Kuject / Generic 40A Car Audio DC Breaker | Amazon, Robu.in, AliExpress | $7 - $10 / ₹550 - ₹800 | Allows instant manual shutoff of the inverter so its standby idle power (~5.5W) does not drain the battery when only DC loads are needed. |
| **INV-03** | 230V AC Universal Panel Socket | 3-Pin universal socket with earth pin, rated 10A 250V AC, panel snap-in or screw mount. | 1 | Legrand / Anchor / Generic panel mount AC socket | Hardware / Electrical shops | $2 - $4 / ₹150 - ₹300 | Connect the Earth pin securely to the inverter's chassis ground terminal. |

---

## 3. DC Fast-Charging & DC-DC Subsystems

| Ref | Item Description | Detailed Technical Specifications | Qty | Recommended Make / Model | Sourcing Options | Est. Price (USD / INR) | Critical Notes |
|:---:|---|---|:---:|---|---|:---:|---|
| **DC-01** | IP2368 100W Bidirectional Buck-Boost Module | Injoinic IP2368 chipset, 10V–28V DC input, USB Type-C output delivering PD 3.0 / PPS (5V/3A, 9V/3A, 12V/3A, 15V/3A, 20V/5A - max 100W). High efficiency synchronous buck-boost. | 1 | IP2368 100W Module with pre-installed CNC aluminum heatsink | Robu.in, AliExpress, Amazon | $16 - $24 / ₹1,250 - ₹1,900 | Essential for HP EliteBook 840 (demands 20V via USB-PD). Standard buck modules cannot produce 20V from a 12V source. Affix thermal pad to the underside. |
| **DC-02** | SW3518S Dual Fast-Charge PCB | Southchip SW3518S controller, 6V–35V DC input, Dual outputs (1x Type-C + 1x Type-A), supports PD3.0, QC4.0+, SCP (22.5W), AFC, VOOC, FCP. | 1 | SW3518S Dual-Port Board (Aluminum casing or bare board) | Robu.in, AliExpress, Amazon | $6 - $10 / ₹480 - ₹800 | Perfect for fast-charging Android & iPhones without requiring bulky AC chargers. |
| **DC-03** | 12V Automatic DC-DC Buck-Boost Module | Wide input (9V-30V), regulated fixed 12.0V output, 3A–5A continuous rating, low output ripple (<50mV). | 1 | LTC3780 Mini / XL6009 Auto Buck-Boost with onboard trimmer | Robu.in, Amazon, AliExpress | $5 - $8 / ₹380 - ₹650 | Keeps the Wi-Fi router line locked at 12.0V regardless of whether the battery is at 14.6V (bulk charge) or 11.5V (discharged). |
| **DC-04** | 12V Automotive Cigarette Socket | Marine-grade 12V socket, rated 10A-15A, splash-proof rubber cover, nickel-plated contacts. | 1 | Marine Grade 12V Power Outlet | Amazon, Car accessories store | $3 - $5 / ₹250 - ₹400 | For running 12V camp gear, portable car tire inflators, or auxiliary 12V camping lights. |
| **DC-05** | DC 5.5 x 2.1mm Panel Mount Jacks | 5.5mm OD x 2.1mm ID female threaded DC chassis socket, rated 5A 30V DC, metal body or nylon. | 2 | 5.5x2.1mm DC Power Jack Panel Mount | Robu.in, Amazon | $2 - $3 / ₹150 - ₹250 | Router power output port. Standard center-positive pin configuration. |

---

## 4. Circuit Protection, Switching & Monitoring

| Ref | Item Description | Detailed Technical Specifications | Qty | Recommended Make / Model | Sourcing Options | Est. Price (USD / INR) | Critical Notes |
|:---:|---|---|:---:|---|---|:---:|---|
| **PRT-01** | Master Battery Isolator Switch | Heavy-duty rotary disconnect switch, rated 100A–275A continuous, 48V DC max, removable key or knob, M8 terminal studs. | 1 | Blue Sea Systems m-Series (6006) / Generic Marine Isolator | Amazon, Robu.in, Marine stores | $10 - $16 / ₹800 - ₹1,300 | Disconnects the entire power station during transport or extended storage. Eliminates all standby parasitic draws. |
| **PRT-02** | Master Fuse Holder & Fuse | MIDI / MRBF terminal fuse block, rated 58V DC, ceramic high-interrupting rating fuse (50A). | 1 | Blue Sea 5191 / Littelfuse MIDI Fuse Block + 50A MIDI Fuse | Amazon, Auto electrical distributor | $8 - $14 / ₹600 - ₹1,100 | Mount directly onto or within 18cm of the battery (+) terminal. Protects the main 6 AWG trunk line. |
| **PRT-03** | 6-Way DC Blade Fuse Block | 6-circuit ATC/ATO fuse block with integrated negative busbar, red blown-fuse indicator LEDs, transparent clip-on cover, max 30A per circuit, 100A total. | 1 | Blue Sea ST Blade 6-way / generic car fuse box | Amazon, Robu.in, AliExpress | $12 - $18 / ₹950 - ₹1,450 | Centralizes all branch fuses. Blown-fuse LEDs make troubleshooting instant without a multimeter. |
| **PRT-04** | ATC/ATO Blade Fuse Pack | Fast-acting blade fuses: 2A (x2), 3A (x2), 5A (x2), 7.5A (x2), 10A (x2), 15A (x2), 20A (x2). | 1 set | Littelfuse / Bussmann Blade Fuse Kit | Hardware / Auto parts store | $4 - $6 / ₹280 - ₹450 | High-quality zinc alloy fuses with clear color coding. |
| **MON-01**| Battery Monitor with Current Shunt | Precision Coulomb-counter, 50A or 100A external shunt, displays Voltage (V), Current (A), Power (W), Cumulative Capacity (Ah), State of Charge (%), and remaining runtime. | 1 | TF03K / Junctek / PZEM-015 / AiLi 100A Battery Monitor | Robu.in, AliExpress, Amazon | $18 - $28 / ₹1,400 - ₹2,200 | Voltage-only meters are useless on LiFePO4 due to its ultra-flat discharge curve. A current shunt is required for accurate % SoC tracking. |

---

## 5. Wiring, Lugs & Interconnect Hardware

| Ref | Item Description | Detailed Technical Specifications | Qty | Recommended Make / Model | Sourcing Options | Est. Price (USD / INR) | Critical Notes |
|:---:|---|---|:---:|---|---|:---:|---|
| **WIR-01** | 6 AWG (16 mm²) Silicone Wire | Ultra-flexible high-strand tinned copper conductor, 200°C rated silicone insulation. 1 meter Red + 1 meter Black. | 2m | 6 AWG Flexible Silicone Cable | Robu.in, Amazon, RC hobby stores | $8 - $12 / ₹650 - ₹950 | Trunk line between Battery (+/-), Master Fuse, Isolator Switch, and Negative Busbar. |
| **WIR-02** | 8 AWG (10 mm²) Silicone Wire | High-strand tinned copper, 200°C silicone insulation. 1 meter Red + 1 meter Black. | 2m | 8 AWG Silicone Wire | Robu.in, Amazon | $6 - $9 / ₹450 - ₹700 | Feeds the 300W Inverter and 6-Way Fuse Block from the main switch/busbar. |
| **WIR-03** | 14 AWG (2.5 mm²) Silicone Wire | High-strand tinned copper, rated for 15A continuous. 2 meters Red + 2 meters Black. | 4m | 14 AWG Silicone Wire | Robu.in, Amazon | $5 - $7 / ₹380 - ₹550 | Internal wiring for IP2368 100W module and 12V cigarette lighter socket. |
| **WIR-04** | 18 AWG (0.75 mm²) Wire | Flexible stranded wire for low-current branches (Wi-Fi router, shunt power, panel LEDs). | 5m | 18 AWG Stranded Copper Wire | Hardware / Electronics shop | $3 - $5 / ₹220 - ₹350 | Wiring for SW3518S module, router line, and display meter power. |
| **CON-01** | Heavy-Duty Copper Cable Lugs | Tinned electrolytic copper ring lugs: SC16-8 (for 6 AWG to M8 battery/switch studs), SC16-6 (M6), SC10-6 (8 AWG to M6 inverter/fuse block studs). | 1 pk (10 pcs) | SC series tinned copper crimp lugs | Robu.in, Amazon, Electrical shops | $6 - $9 / ₹450 - ₹700 | Never solder high-current battery lugs; use a mechanical hex crimper or heavy hammer crimper. |
| **CON-02** | Anderson SB50 Power Connector | 50A rated bipolar genderless connector with silver-plated copper contacts, Gray housing, fits 6-10 AWG wire. | 2 sets | Genuine Anderson Power Products SB50 / generic | Robu.in, Amazon | $6 - $10 / ₹450 - ₹750 | Primary charging input port on the exterior panel for connecting AC charger or Solar MPPT. |
| **CON-03** | DC 5.5 x 2.1mm Patch Cables | Molded 5.5x2.1mm male-to-male DC power cable, 18 AWG pure copper, 1 meter length. | 2 | High-current DC barrel jumper cable | Amazon, Robu.in | $4 - $6 / ₹300 - ₹450 | Connects the power station router output jack directly to your home Wi-Fi router. |
| **CON-04** | Insulated Spade / Fork Terminals | Blue (14-16 AWG) and Red (18-22 AWG) crimp terminals for fuse block screw terminals. | 1 box | Assorted insulated crimp terminal kit | Amazon, Hardware shops | $4 - $6 / ₹300 - ₹450 | Clean connection to the fuse block screws. |

---

## 6. Enclosure, Thermal & Mounting Hardware

| Ref | Item Description | Detailed Technical Specifications | Qty | Recommended Make / Model | Sourcing Options | Est. Price (USD / INR) | Critical Notes |
|:---:|---|---|:---:|---|---|:---:|---|
| **ENC-01** | Portable Equipment Case | Heavy-duty tactical ABS tool box or military-style ammo can / Pelican-style case with carry handle. Min internal dimensions: 350 x 220 x 240 mm. | 1 | Tactical ABS Ammo Can / DeWalt TSTAK / DIY Baltic Birch Box | Amazon, Hardware stores | $22 - $38 / ₹1,700 - ₹3,000 | Must accommodate the 12V 100Ah battery footprint (typically ~260 x 168 x 215 mm) plus top/side clearance for modules. |
| **ENC-02** | Thermal Management / Fan (Optional) | 60mm or 80mm 12V DC silent brushless fan (fluid bearing) + metal finger guard. | 1 | Noctua / Sunon / Generic 12V 80mm fan | Amazon, Computer hardware | $4 - $8 / ₹300 - ₹600 | Recommended if continuously running the IP2368 at 100W or the Inverter at 300W in an enclosed box. |
| **MSC-01** | Dual-Wall Adhesive Heatshrink | 3:1 polyolefin heatshrink tubing with hot-melt glue lining (Assorted 6mm, 9mm, 12mm, 18mm). | 1 pk | Marine-grade adhesive heat shrink | Amazon, Robu.in | $5 - $8 / ₹380 - ₹600 | Seals and reinforces all crimped cable lug collars against moisture and mechanical vibration. |
| **MSC-02** | Standoffs & Fasteners Kit | M3 brass/nylon PCB standoffs, M4 stainless steel bolts, nuts, and washers. | 1 kit | M3 & M4 hardware assortment | Robu.in, Amazon | $5 - $7 / ₹350 - ₹550 | For secure mounting of the IP2368, SW3518, buck-boost converter, and fuse block to an acrylic/wood sub-chassis. |
| **MSC-03** | Sub-Chassis Mounting Plate | 3mm to 4mm clear Acrylic or Bakelite or 6mm Baltic Birch plywood sheet (approx 300 x 200 mm). | 1 | Acrylic / Bakelite baseplate sheet | Local plastics/carpentry supplier | $4 - $6 / ₹300 - ₹450 | Non-conductive mounting plate to isolate electronics from the battery casing. |

---

## 7. Cost Summary & Budget Breakdown

| Subsystem | Estimated USD ($) | Estimated INR (₹) |
|---|:---:|:---:|
| **1. Core Battery & Smart Charger** | $232 - $288 | ₹17,900 - ₹22,600 |
| **2. 300W AC Inverter & AC Outlet** | $49 - $69 | ₹3,900 - ₹5,500 |
| **3. DC Buck-Boost, Fast-Charge & 12V Regulators** | $32 - $50 | ₹2,510 - ₹4,000 |
| **4. Circuit Protection, Switching & Shunt Monitor** | $52 - $82 | ₹4,030 - ₹6,400 |
| **5. Wiring, Lugs, Anderson Plugs & Connectors** | $32 - $48 | ₹2,470 - ₹3,750 |
| **6. Enclosure, Hardware, Standoffs & Heatshrink** | $40 - $67 | ₹3,030 - ₹5,200 |
| **TOTAL PROJECT ESTIMATE** | **$437 - $604** | **₹33,840 - ₹47,450** |

*(Note: Budget assumes sourcing individual modules at retail DIY prices. Builders with existing tools, wire, or chargers can construct this unit for significantly less.)*

---

## 8. Recommended Tools Checklist

Before beginning assembly, verify you have access to:
- [ ] **Digital Multimeter (DMM)** with continuity beeper and DC voltage measurement
- [ ] **Heavy-Duty Hexagonal Cable Lug Crimper** (e.g., HX-50B or hydraulic crimper) for 6 AWG & 8 AWG lugs
- [ ] **Ratcheting Wire Crimper** for red/blue insulated fork & spade terminals
- [ ] **Wire Strippers & Heavy Cable Cutters**
- [ ] **Heat Gun** (or mini torch) for activating dual-wall adhesive heatshrink
- [ ] **Soldering Iron (60W+) & Rosin-Core Solder** (for DC barrel jacks and PCB pin headers)
- [ ] **Step Drill Bit (Unibit)** (up to 32mm) for cutting clean panel holes in the enclosure for the socket, switch, and USB ports
- [ ] **Threadlocker (Loctite Blue 242)** to prevent battery and isolator switch nuts from vibrating loose
