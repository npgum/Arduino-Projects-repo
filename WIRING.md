# Wiring Reference

Pin maps for every project, taken directly from the sketch headers and `const int`
pin definitions. **Every connection below is verified against the code** — if you
change a pin in the sketch, change it here too.

> ⚠️ **Before you power anything:** Arduino Uno I/O pins are 3.3–5 V logic and
> ~20 mA per pin (40 mA absolute max). Never drive a pump, relay coil, motor or
> LED strip straight from a pin — use a relay module, MOSFET or transistor driver,
> and give inductive loads a flyback diode. Use an external supply for anything
> that draws more than a few hundred mA.

## Common I2C wiring (Uno / Nano)

Used by every project with an I2C LCD (`LiquidCrystal_I2C`).

| LCD module | Arduino Uno/Nano |
|---|---|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

Default I2C address is `0x27`. If the display stays blank, run an I2C scanner
sketch — many modules ship as `0x3F`, which needs one line changed:
`LiquidCrystal_I2C lcd(0x3F, 16, 2);`

---

## Beginner

### led_blink.ino
No external parts. Uses the on-board LED on `LED_BUILTIN` (pin 13 on Uno).

### temperature_sensor.ino
| DHT11 | Arduino |
|---|---|
| VCC | 5V |
| DATA | Pin 2 |
| GND | GND |

Add a 10 kΩ pull-up between DATA and VCC if you are using the bare 4-pin sensor
rather than a breakout board.

### servo_motor_control.ino
| Part | Arduino |
|---|---|
| Servo signal (orange) | Pin 9 |
| Servo VCC (red) | 5V |
| Servo GND (brown) | GND |
| Potentiometer wiper (middle leg) | A0 |
| Potentiometer ends | 5V and GND |

Power the servo from a separate 5 V supply if it twitches or the board resets —
an SG90 stall current will brown out the Uno's regulator.

### lcd_display.ino
Parallel (non-I2C) HD44780 in 4-bit mode. `LiquidCrystal lcd(12, 11, 5, 4, 3, 2);`

| LCD pin | Name | Arduino |
|---|---|---|
| 1 | VSS | GND |
| 2 | VDD | 5V |
| 3 | V0 | 10 kΩ pot wiper (contrast) |
| 4 | RS | Pin 12 |
| 5 | RW | GND |
| 6 | E | Pin 11 |
| 11 | D4 | Pin 5 |
| 12 | D5 | Pin 4 |
| 13 | D6 | Pin 3 |
| 14 | D7 | Pin 2 |
| 15 | A (backlight +) | 5V via 220 Ω |
| 16 | K (backlight −) | GND |

### ultrasonic_distance.ino
| HC-SR04 | Arduino |
|---|---|
| VCC | 5V |
| TRIG | Pin 9 |
| ECHO | Pin 10 |
| GND | GND |

Note: the HC-SR04 ECHO pin outputs 5 V. It is safe on a 5 V Uno but **needs a
voltage divider on a 3.3 V board** (ESP32, STM32).

---

## Home Automation

### smart_plant_watering.ino
| Part | Arduino |
|---|---|
| Soil moisture AOUT | A0 |
| Soil moisture VCC / GND | 5V / GND |
| Relay module IN | Pin 8 |
| Relay module VCC / GND | 5V / GND |
| Green LED (+220 Ω) | Pin 11 |
| Red LED (+220 Ω) | Pin 10 |
| Push button | Pin 7 → GND (uses `INPUT_PULLUP`) |

Pump connects to the relay's **COM/NO** terminals with its own supply.
Relay logic here is **active-LOW** (`LOW` = pump on), which suits most blue
opto-isolated relay boards.

### motion_activated_light.ino
| Part | Arduino |
|---|---|
| PIR HC-SR501 OUT | Pin 2 |
| PIR VCC / GND | 5V / GND |
| LDR divider midpoint | A0 |
| Relay module IN | Pin 8 |
| Status LED (+220 Ω) | Pin 13 |

LDR divider: `5V → LDR → A0 → 10 kΩ → GND`.

### auto_dimming_night_light.ino
| Part | Arduino |
|---|---|
| LDR divider midpoint | A0 |
| LED cathode (PWM) | Pin 9 |
| Push button | Pin 7 → GND (uses `INPUT_PULLUP`) |

LED anode goes to 5 V through a 150 Ω resistor per LED. For a strip, drive it
with a TIP120/MOSFET: base via 1 kΩ from pin 9, emitter to GND, strip ground to
collector, strip positive to a 12 V supply.

**Thresholds are inverted for this circuit.** Because the LED is wired to 5 V and
switched on the low side, a *higher* LDR reading means brighter ambient light.
`DARK_LEVEL` (150) is the reading where the room is fully dark and `LIGHT_LEVEL`
(500) is where it is bright enough to switch off — so a dark room reads a *low*
number. Calibrate by watching the serial output in your actual room.

---

## Monitoring & Display

### home_thermostat_display.ino
| Part | Arduino |
|---|---|
| DHT DATA | Pin 2 |
| I2C LCD | A4 / A5 (see above) |
| Blue LED (+220 Ω) | Pin 9 |
| Red LED (+220 Ω) | Pin 10 |
| Yellow LED (+220 Ω) | Pin 11 |
| Buzzer + | Pin 6 |

### air_quality_monitor.ino
| Part | Arduino |
|---|---|
| MQ-135 AOUT | A0 |
| I2C LCD | A4 / A5 |
| Green LED (+220 Ω) | Pin 9 |
| Yellow LED (+220 Ω) | Pin 10 |
| Red LED (+220 Ω) | Pin 11 |

The MQ-135 needs a **24-hour burn-in** before its readings mean anything, and it
draws ~150 mA — that is why it gets hot. Do not power it from a pin.

### water_level_monitor.ino
| Part | Arduino |
|---|---|
| HC-SR04 TRIG | Pin 5 |
| HC-SR04 ECHO | Pin 6 |
| I2C LCD | A4 / A5 |
| Buzzer + | Pin 8 |
| Green LED (+220 Ω) | Pin 9 |
| Yellow LED (+220 Ω) | Pin 10 |
| Red LED (+220 Ω) | Pin 11 |

Tank geometry is set in the sketch: `SENSOR_TO_FULL = 10.0` cm,
`SENSOR_TO_EMPTY = 80.0` cm, `MAX_CAPACITY_L = 1000.0`. Measure your own tank —
these defaults are a 70 cm span holding 1000 L, which is a large tank.

---

## Advanced

### home_environment_dashboard.ino
| Part | Arduino |
|---|---|
| DHT11 DATA | Pin 2 |
| MQ-135 AOUT | A0 |
| LDR divider midpoint | A1 |
| Soil moisture AOUT | A2 |
| PIR OUT | Pin 3 |
| HC-SR04 TRIG | Pin 5 |
| HC-SR04 ECHO | Pin 6 |
| Push button (view cycle) | Pin 7 → GND (`INPUT_PULLUP`) |
| I2C LCD | A4 / A5 |
| Status LED | Pin 13 |

Uses **two separate analog LDR circuits** on A0/A1 depending on the project —
check which sketch you flashed before trusting the readings.

Note the analog pin budget: A0–A2 are used for sensors, A4/A5 for I2C. A3 is the
only free analog input on an Uno.

---

## Power budget cheat sheet

| Load | Typical draw | Drive it with |
|---|---|---|
| LED (single) | 20 mA | Pin + 220 Ω resistor |
| 5 V relay module | 70–80 mA | Pin is fine for the signal; coil from 5 V rail |
| SG90 servo | 100 mA idle, 700 mA stall | Separate 5 V supply |
| MG996R servo | 500 mA idle, 2.5 A stall | Separate 5 V supply, thick wires |
| MQ-135 | ~150 mA | 5 V rail |
| Mini water pump | 200–500 mA | Relay + external supply |
| LED strip (1 m) | 1–2 A | MOSFET + external 12 V supply |

**Total available from the Uno 5 V pin:** roughly 400 mA when powered by USB,
and you should stay well under that. If your project has a servo *and* an MQ-135,
it needs its own supply.
