# Project List

All 12 projects in this repo, with the hardware each one actually uses. Sensor and
board columns are derived from the sketch code and its `const int` pin definitions,
not from the README summaries.

**Verified build target:** `arduino:avr:uno`, core 1.8.8, arduino-cli 1.5.1.
Flash/SRAM figures come from a real compile (see the badge at the top of the README).

**Also in this file:** [Proposed Projects](#proposed-projects) — 14 unbuilt ideas
levelled for tugas and skripsi work, each with a difficulty rating.

| # | Title | Description | Board | Sensors / Modules | Actuators | Difficulty | Flash | SRAM |
|---|---|---|---|---|---|---|---|---|
| 1 | [LED Blink](projects/led_blink.ino) | Toggles the on-board LED every 1 s (1 s on, 1 s off). Baseline sketch for a fresh board. | Arduino Uno | — | On-board LED (pin 13) | ⭐ | 2% | 0% |
| 2 | [Temperature Sensor](projects/temperature_sensor.ino) | Reads temperature and prints it to the Serial Monitor every 2 s. | Arduino Uno | DHT11 (digital, pin 2) | — | ⭐ | 14% | 12% |
| 3 | [Servo Motor Control](projects/servo_motor_control.ino) | Potentiometer sets the servo angle; `map()` scales 0–1023 to 0–180°. | Arduino Uno | 10 kΩ potentiometer (A0) | SG90 micro servo (pin 9) | ⭐⭐ | 6% | 2% |
| 4 | [LCD Display](projects/lcd_display.ino) | Prints "Hello, World!" and a running seconds counter to a parallel LCD. | Arduino Uno | 16×2 HD44780 LCD, 4-bit parallel | — | ⭐⭐ | 5% | 2% |
| 5 | [Ultrasonic Distance](projects/ultrasonic_distance.ino) | Measures distance via ultrasonic pulse timing, in cm, over Serial. | Arduino Uno | HC-SR04 (trig 9, echo 10) | — | ⭐⭐ | 11% | 10% |
| 6 | [Smart Plant Watering](projects/smart_plant_watering.ino) | Waters when soil reads dry, with green/red status LEDs and a manual override button. Averages 5 ADC reads per check. | Arduino Uno | Soil moisture (A0), push button (pin 7) | 5 V relay (pin 8), mini pump, 2 LEDs | ⭐⭐⭐ | 10% | 19% |
| 7 | [Motion-Activated Light](projects/motion_activated_light.ino) | Turns a lamp on at motion, only when dark, and off 30 s after the last trigger. | Arduino Uno | PIR HC-SR501 (pin 2), LDR + 10 kΩ (A0) | 5 V relay (pin 8), status LED (13) | ⭐⭐⭐ | 9% | 17% |
| 8 | [Auto-Dimming Night Light](projects/auto_dimming_night_light.ino) | Fades an LED smoothly with ambient light; off in daylight, full brightness when dark. Button toggles manual mode. | Arduino Uno | LDR + 10 kΩ (A0), push button (pin 7) | LED via PWM (pin 9), optional TIP120 | ⭐⭐ | 10% | 17% |
| 9 | [Home Thermostat Display](projects/home_thermostat_display.ino) | Shows temp/humidity on an I2C LCD and lights a colour-coded LED, with a buzzer when too hot. | Arduino Uno | DHT11 (pin 2), I2C LCD 0x27 (A4/A5) | 3 LEDs, piezo buzzer (pin 6) | ⭐⭐⭐ | 28% | 35% |
| 10 | [Air Quality Monitor](projects/air_quality_monitor.ino) | Reads an MQ-135 and classifies air as good / moderate / poor, with a traffic-light LED set. Averages 10 reads. | Arduino Uno | MQ-135 (A0), I2C LCD 0x27 (A4/A5) | 3 LEDs | ⭐⭐⭐ | 16% | 33% |
| 11 | [Water Level Monitor](projects/water_level_monitor.ino) | Ultrasonic sensor aimed down a tank gives level % and litres, with low/critical alarms. | Arduino Uno | HC-SR04 (trig 5, echo 6), I2C LCD 0x27 (A4/A5) | Buzzer (pin 8), 3 LEDs | ⭐⭐⭐ | 25% | 34% |
| 12 | [Home Environment Dashboard](projects/home_environment_dashboard.ino) | Six sensors on one board, cycling four LCD views by button press, with full Serial logging. | Arduino Uno | DHT11 (2), MQ-135 (A0), LDR (A1), soil moisture (A2), PIR (3), HC-SR04 (5/6), I2C LCD (A4/A5) | Status LED (13) | ⭐⭐⭐⭐⭐ | 36% | 48% |

## Notes

- **Every project currently targets Arduino Uno** (`arduino:avr:uno`). The repo's
  README catalog lists ESP32, ESP8266, STM32, Teensy and others as *compatible
  boards* for reference, but no sketch here has been ported to or tested on them.
- **Wiring for every project is in [WIRING.md](WIRING.md)**, including the power
  budget warning about not driving relays, pumps or servos straight from an I/O pin.
- **Pin conflicts to watch** when combining projects: A0 is the LDR in one sketch
  and the MQ-135 in another; A4/A5 are reserved for I2C on every LCD project, which
  leaves A3 as the only free analog pin on the dashboard build.
- **Nothing here has been tested on physical hardware** — the figures above prove
  the sketches compile and fit on an Uno, not that the sensors behave in a real
  room. Thresholds in the soil, light and air-quality sketches are placeholders
  that expect calibration against your own environment.

---

# Proposed Projects

**Status: backlog. None of these are built.** No sketch, no wiring, no verified
compile — unlike the 12 above. The difficulty ratings here are engineering
judgements, not measurements, because nothing has been built yet.

## Why these, and not more sensor demos

The 12 projects above are single-sensor demos. They compile and they work, but each
one is a *praktikum* exercise — the kind of thing a dosen has already seen many
times over. For **tugas** and **skripsi**, that is not enough.

What makes a project defensible at sidang is not how many sensors it has. It is
whether the student can write a real method chapter (bab 3) about *how* it works,
not just *what* it displays. Every idea below is picked because it carries a
**built-in novelty claim** — a comparison, an optimisation, or a calibration — so
novelty does not have to be invented, it is the experimental design itself.

## Difficulty scale

| Rating | Meaning |
|---|---|
| ⭐⭐ | Straightforward build. Most of the effort is wiring and calibration. |
| ⭐⭐⭐ | Standard tugas akhir level. Needs solid code and a clean writeup. |
| ⭐⭐⭐⭐ | Real engineering. Requires understanding the method, not just the API. |
| ⭐⭐⭐⭐⭐ | Research-grade. The student must be able to defend the maths or the algorithm. |

Match the rating to the student, not to the price. An idea sold above a student's
level fails at sidang — see [constraints](#constraints-that-protect-the-work).

---

## Tugas Level

Shorter timeline, cheaper parts, lower margin. Each is still genuinely elektro
rather than a generic sensor readout, so it looks like engineering rather than a
copied tutorial.

| # | Project | Novelty claim (the bab 3 hook) | Key hardware | Difficulty |
|---|---|---|---|---|
| T1 | Earth Tester | Perbandingan metode **3-titik vs 2-titik** untuk tahanan tanah, with error analysis | Custom probe rig, ADC, OLED | ⭐⭐ |
| T2 | Lux Meter Terkalibrasi | Kalibrasi terhadap lux meter referensi, with a quantified error curve | BH1750, OLED | ⭐⭐ |
| T3 | Digital kWh Meter | Alat ukur mandiri, **dikalibrasi terhadap kWh meter PLN** — report measurable error % | PZEM-004T, SD card, RTC | ⭐⭐⭐ |
| T4 | Over-Current Relay (OCR) | Implementasi **kurva inverse time IEC 60255** di mikrokontroler — plot trip time vs fault current | ACS712, relay, load bank | ⭐⭐⭐ |

## Skripsi Level

The main tier. Ordered by difficulty, so the list reads as a progression. Every one
has a comparison or an optimisation built in — the experimental design supplies the
novelty, and the student supplies the defence.

| # | Project | Novelty claim | Key hardware | Difficulty |
|---|---|---|---|---|
| S1 | PID Motor DC: Ziegler-Nichols vs PSO | Classical tuning vs metaheuristic — compare settling time, overshoot, ITAE | Encoder motor, L298N | ⭐⭐⭐ |
| S2 | Fuzzy Logic Control (suhu atau irigasi) | Fuzzy Mamdani vs PID, or fuzzy vs threshold — the **rule base** is the contribution | DHT22 / soil sensor, heater or pump | ⭐⭐⭐ |
| S3 | Klasifikasi Kualitas Air: KNN vs Naive Bayes | Train on labelled samples to classify layak/minum/tidak | TDS, pH, turbidity sensors | ⭐⭐⭐ |
| S4 | **MPPT: Perturb & Observe vs Incremental Conductance** | Comparing two MPPT algorithms on one rig **is** the contribution — plot P-V curves against irradiance | Solar panel, buck converter, INA219, ESP32 | ⭐⭐⭐⭐ |
| S5 | Power Quality Analyzer | THD, sag/swell from high-rate sampling + FFT — needs real DSP understanding | ESP32, ZMPT101B, ACS712 | ⭐⭐⭐⭐ |
| S6 | **Predictive Maintenance: Vibrasi + FFT Envelope** | Detect bearing fault from vibration signature — "deteksi dini kerusakan" reads industrially serious | ADXL345 or MPU6050, motor rig | ⭐⭐⭐⭐⭐ |
| S7 | **NILM — Non-Intrusive Load Monitoring** | Disaggregate **which appliances** are running from one current sensor at the panel — signature extraction + classification | CT sensor, high-rate ADC, ESP32 | ⭐⭐⭐⭐⭐ |
| S8 | BMS — SOC Estimation + Cell Balancing | Kalman filter for state-of-charge, plus active/passive balancing | Cell stack, balancing FETs, shunt | ⭐⭐⭐⭐⭐ |
| S9 | BLDC Motor — Field Oriented Control | Clarke/Park transforms + PI loops on a three-phase inverter | 3-phase bridge, BLDC, gate drivers | ⭐⭐⭐⭐⭐ |
| S10 | Inverter SPWM Closed-Loop / Grid-Tie | Synchronisation to grid via PLL | H-bridge, LC filter, transformer | ⭐⭐⭐⭐⭐ |

> **S6–S10 are research-grade.** They are the most impressive and the most scarce,
> but they only work with a student who can explain the underlying maths. Selling one
> of these to a weak student is how a project fails at sidang.

## Constraints that protect the work

1. **Defensibility beats complexity.** If the student cannot explain the project,
   it fails at sidang — which is a refund, a bad review, or worse. Match the
   difficulty rating to the person, not to the price.
2. **Variation is not optional.** The same project sold twice at one campus gets
   both students flagged. Every proposal needs swappable axes: different algorithm,
   different sensor, different plant, different comparison. Build the *template*,
   not the artifact.
3. **Keep a per-campus ledger.** Never sell the same topic twice in one semester at
   the same faculty. This is the most common way this work goes wrong.
4. **Never fabricate data.** S3 (water quality) and S7 (NILM) need real labelled
   samples. Synthetic data collapses the moment a penguji asks to see the raw log.

## Suggested build order

1. **S4 (MPPT comparison)** — the volume seller. Clean method, cheap parts, high
   approval rate, and it extends the sensor-catalog approach already used here.
2. **S6 (vibration predictive maintenance)** — the differentiator. Scarce,
   impressive, and it justifies a higher tier than any monitoring project.
3. **S7 (NILM)** — the highest margin, but only once demand is validated.

Start with **T1–T4** to establish the cheaper tugas pipeline while S4 is being
developed — they are quick enough to build and test alongside it.

> Pricing is tracked separately from this repo. The difficulty ratings above are
> engineering judgements, not quoted prices.
