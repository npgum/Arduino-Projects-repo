# dotinoproject

Arduino Home & Automation Projects — practical, well-documented projects with complete wiring diagrams and a [63-sensor reference catalogue](docs/sensors.md).

---

## Quick Links

- **[Sensor Catalog](docs/sensors.md)** — 63 sensors with GitHub library links & Arduino library names
- **[Sensor Reference (Obsidian)](../npg/Projects/dotinoproject/Sensors/)** — Internal wiki vault

---

## Projects

### Beginner Tutorials

| Project | Sensors Used | Difficulty |
|---------|-------------|------------|
| [LED Blink](projects/led_blink.ino) | None | ⭐ |
| [Temperature Sensor](projects/temperature_sensor.ino) | [DHT11](https://github.com/adafruit/DHT-sensor-library) | ⭐ |
| [Servo Motor Control](projects/servo_motor_control.ino) | [SG90 Micro Servo](https://github.com/RoboticsBrno/ServoESP32) | ⭐⭐ |
| [LCD Display](projects/lcd_display.ino) | [16x2 LCD HD44780](https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library) | ⭐⭐ |
| [Ultrasonic Distance](projects/ultrasonic_distance.ino) | [HC-SR04](https://github.com/LouisD95/HCSR04) | ⭐⭐ |

### Home Automation

| Project | Sensors Used | Difficulty |
|---------|-------------|------------|
| [Smart Plant Watering](projects/smart_plant_watering.ino) | [Soil Moisture](https://github.com/ArminJo/Capacitive-Soil-Moisture-Sensor-Library), [5V Relay](https://github.com/adafruit/Adafruit-Relay-Board) | ⭐⭐⭐ |
| [Motion-Activated Light](projects/motion_activated_light.ino) | [PIR HC-SR501](https://github.com/adafruit/Adafruit_PIR_Sensor), [LDR](https://github.com/adafruit/Adafruit_LDR), Relay | ⭐⭐⭐ |
| [Auto-Dimming Night Light](projects/auto_dimming_night_light.ino) | [LDR](https://github.com/adafruit/Adafruit_LDR), PWM LED | ⭐⭐ |

### Monitoring & Display

| Project | Sensors Used | Difficulty |
|---------|-------------|------------|
| [Home Thermostat Display](projects/home_thermostat_display.ino) | [DHT11/DHT22](https://github.com/adafruit/DHT-sensor-library), [I2C LCD](https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library), Buzzer | ⭐⭐⭐ |
| [Air Quality Monitor](projects/air_quality_monitor.ino) | [MQ-135](https://github.com/GeorgK/MQ135), [I2C LCD](https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library) | ⭐⭐⭐ |
| [Water Level Monitor](projects/water_level_monitor.ino) | [HC-SR04](https://github.com/LouisD95/HCSR04), [I2C LCD](https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library), Buzzer | ⭐⭐⭐ |

### Advanced

| Project | Sensors Used | Difficulty |
|---------|-------------|------------|
| [Home Environment Dashboard](projects/home_environment_dashboard.ino) | [DHT11](https://github.com/adafruit/DHT-sensor-library), [MQ-135](https://github.com/GeorgK/MQ135), [LDR](https://github.com/adafruit/Adafruit_LDR), [HC-SR04](https://github.com/LouisD95/HCSR04), [PIR](https://github.com/adafruit/Adafruit_PIR_Sensor), [Soil Moisture](https://github.com/ArminJo/Capacitive-Soil-Moisture-Sensor-Library), [I2C LCD](https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library) | ⭐⭐⭐⭐⭐ |

---

## Required Libraries

Install via Arduino IDE → **Sketch → Include Library → Manage Libraries**

| Library | Author | Used By |
|---------|--------|---------|
| **DHT sensor library** | Adafruit | All DHT11/DHT22 projects |
| **LiquidCrystal I2C** | Frank de Brabander | All LCD projects |
| **Servo** | Arduino (built-in) | Servo projects |

---

## Hardware Shopping List

**Core:**
- Arduino Uno R3 (or compatible)
- Breadboard + jumper wires
- USB cable (Type A to Type B)

**Sensors:**
- [DHT11](https://github.com/adafruit/DHT-sensor-library) or [DHT22](https://github.com/adafruit/DHT-sensor-library)
- [HC-SR04](https://github.com/LouisD95/HCSR04) ultrasonic distance sensor
- [MQ-135](https://github.com/GeorgK/MQ135) air quality sensor
- [PIR HC-SR501](https://github.com/adafruit/Adafruit_PIR_Sensor) motion sensor
- [Soil Moisture (capacitive)](https://github.com/ArminJo/Capacitive-Soil-Moisture-Sensor-Library)
- [LDR](https://github.com/adafruit/Adafruit_LDR) + 10k resistor

**Displays & Feedback:**
- [16x2 LCD with I2C](https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library)
- LEDs (red, green, yellow, blue) + 220ohm resistors
- Active buzzer
- Push buttons

**Actuators:**
- [5V Relay Module](https://github.com/adafruit/Adafruit-Relay-Board)
- Mini water pump (3-6V)
- [Micro Servo SG90](https://github.com/RoboticsBrno/ServoESP32)
- Potentiometer (10k)

**Estimated cost:** ~$15-25 for a starter kit covering all projects.

---

## Browse All 63 Sensors

See the complete sensor reference with GitHub library links: **[docs/sensors.md](docs/sensors.md)**

Sensors currently used in projects: **10/63** — plenty of room to expand!

### Sensors Used in This Project
| Sensor | Category | GitHub |
|--------|----------|--------|
| DHT11/DHT22 | Temperature & Humidity | [Link](https://github.com/adafruit/DHT-sensor-library) |
| HC-SR04 | Ultrasonic Distance | [Link](https://github.com/LouisD95/HCSR04) |
| MQ-135 | Air Quality | [Link](https://github.com/GeorgK/MQ135) |
| PIR HC-SR501 | Motion Detection | [Link](https://github.com/adafruit/Adafruit_PIR_Sensor) |
| LDR | Light | [Link](https://github.com/adafruit/Adafruit_LDR) |
| Soil Moisture (Capacitive) | Soil | [Link](https://github.com/ArminJo/Capacitive-Soil-Moisture-Sensor-Library) |
| 16x2 LCD (I2C) | Display | [Link](https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library) |
| SG90 Servo | Motor | [Link](https://github.com/RoboticsBrno/ServoESP32) |
| 5V Relay | Switch | [Link](https://github.com/adafruit/Adafruit-Relay-Board) |
| Buzzer | Audio | (built-in, no library) |

---

## Project Structure

```
dotinoproject/
├── README.md
├── docs/
│   └── sensors.md          ← 63 sensors with GitHub links
└── projects/
    ├── Beginner:
    │   ├── led_blink.ino
    │   ├── temperature_sensor.ino
    │   ├── servo_motor_control.ino
    │   ├── lcd_display.ino
    │   └── ultrasonic_distance.ino
    ├── Home Automation:
    │   ├── smart_plant_watering.ino
    │   ├── motion_activated_light.ino
    │   └── auto_dimming_night_light.ino
    ├── Monitoring:
    │   ├── home_thermostat_display.ino
    │   ├── air_quality_monitor.ino
    │   └── water_level_monitor.ino
    └── Advanced:
        └── home_environment_dashboard.ino
```

---

## Contributing

1. Place `.ino` file in `projects/`
2. Include wiring diagram in header comments
3. Add row to appropriate README table
4. If using a new sensor, add to `docs/sensors.md`

---

## License

MIT
