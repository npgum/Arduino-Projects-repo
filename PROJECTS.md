# Project List

All 12 projects in this repo, with the hardware each one actually uses. Sensor and
board columns are derived from the sketch code and its `const int` pin definitions,
not from the README summaries.

**Verified build target:** `arduino:avr:uno`, core 1.8.8, arduino-cli 1.5.1.
Flash/SRAM figures come from a real compile (see the badge at the top of the README).

| # | Title | Description | Board | Sensors / Modules | Actuators | Flash | SRAM |
|---|---|---|---|---|---|---|---|
| 1 | [LED Blink](projects/led_blink.ino) | Toggles the on-board LED every 1 s (1 s on, 1 s off). Baseline sketch for a fresh board. | Arduino Uno | — | On-board LED (pin 13) | 2% | 0% |
| 2 | [Temperature Sensor](projects/temperature_sensor.ino) | Reads temperature and prints it to the Serial Monitor every 2 s. | Arduino Uno | DHT11 (digital, pin 2) | — | 14% | 12% |
| 3 | [Servo Motor Control](projects/servo_motor_control.ino) | Potentiometer sets the servo angle; `map()` scales 0–1023 to 0–180°. | Arduino Uno | 10 kΩ potentiometer (A0) | SG90 micro servo (pin 9) | 6% | 2% |
| 4 | [LCD Display](projects/lcd_display.ino) | Prints "Hello, World!" and a running seconds counter to a parallel LCD. | Arduino Uno | 16×2 HD44780 LCD, 4-bit parallel | — | 5% | 2% |
| 5 | [Ultrasonic Distance](projects/ultrasonic_distance.ino) | Measures distance via ultrasonic pulse timing, in cm, over Serial. | Arduino Uno | HC-SR04 (trig 9, echo 10) | — | 11% | 10% |
| 6 | [Smart Plant Watering](projects/smart_plant_watering.ino) | Waters when soil reads dry, with green/red status LEDs and a manual override button. Averages 5 ADC reads per check. | Arduino Uno | Soil moisture (A0), push button (pin 7) | 5 V relay (pin 8), mini pump, 2 LEDs | 10% | 19% |
| 7 | [Motion-Activated Light](projects/motion_activated_light.ino) | Turns a lamp on at motion, only when dark, and off 30 s after the last trigger. | Arduino Uno | PIR HC-SR501 (pin 2), LDR + 10 kΩ (A0) | 5 V relay (pin 8), status LED (13) | 9% | 17% |
| 8 | [Auto-Dimming Night Light](projects/auto_dimming_night_light.ino) | Fades an LED smoothly with ambient light; off in daylight, full brightness when dark. Button toggles manual mode. | Arduino Uno | LDR + 10 kΩ (A0), push button (pin 7) | LED via PWM (pin 9), optional TIP120 | 10% | 17% |
| 9 | [Home Thermostat Display](projects/home_thermostat_display.ino) | Shows temp/humidity on an I2C LCD and lights a colour-coded LED, with a buzzer when too hot. | Arduino Uno | DHT11 (pin 2), I2C LCD 0x27 (A4/A5) | 3 LEDs, piezo buzzer (pin 6) | 28% | 35% |
| 10 | [Air Quality Monitor](projects/air_quality_monitor.ino) | Reads an MQ-135 and classifies air as good / moderate / poor, with a traffic-light LED set. Averages 10 reads. | Arduino Uno | MQ-135 (A0), I2C LCD 0x27 (A4/A5) | 3 LEDs | 16% | 33% |
| 11 | [Water Level Monitor](projects/water_level_monitor.ino) | Ultrasonic sensor aimed down a tank gives level % and litres, with low/critical alarms. | Arduino Uno | HC-SR04 (trig 5, echo 6), I2C LCD 0x27 (A4/A5) | Buzzer (pin 8), 3 LEDs | 25% | 34% |
| 12 | [Home Environment Dashboard](projects/home_environment_dashboard.ino) | Six sensors on one board, cycling four LCD views by button press, with full Serial logging. | Arduino Uno | DHT11 (2), MQ-135 (A0), LDR (A1), soil moisture (A2), PIR (3), HC-SR04 (5/6), I2C LCD (A4/A5) | Status LED (13) | 36% | 48% |

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
