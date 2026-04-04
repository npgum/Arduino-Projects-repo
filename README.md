# dotinoproject

Arduino Home & Automation Projects — practical, well-documented projects with complete wiring diagrams and a 63-sensor reference catalog.

---

## Quick Links

- **[Sensor Reference (Obsidian)](../npg/Projects/dotinoproject/Sensors/)** — Internal wiki vault

---

## Projects

### Beginner Tutorials

| Project | Sensors Used | Difficulty |
|---------|-------------|------------|
| [LED Blink](projects/led_blink.ino) | None | ⭐ |
| [Temperature Sensor](projects/temperature_sensor.ino) | DHT11 | ⭐ |
| [Servo Motor Control](projects/servo_motor_control.ino) | SG90 Micro Servo | ⭐⭐ |
| [LCD Display](projects/lcd_display.ino) | 16x2 LCD HD44780 | ⭐⭐ |
| [Ultrasonic Distance](projects/ultrasonic_distance.ino) | HC-SR04 | ⭐⭐ |

### Home Automation

| Project | Sensors Used | Difficulty |
|---------|-------------|------------|
| [Smart Plant Watering](projects/smart_plant_watering.ino) | Soil Moisture, 5V Relay | ⭐⭐⭐ |
| [Motion-Activated Light](projects/motion_activated_light.ino) | PIR HC-SR501, LDR, Relay | ⭐⭐⭐ |
| [Auto-Dimming Night Light](projects/auto_dimming_night_light.ino) | LDR, PWM LED | ⭐⭐ |

### Monitoring & Display

| Project | Sensors Used | Difficulty |
|---------|-------------|------------|
| [Home Thermostat Display](projects/home_thermostat_display.ino) | DHT11/DHT22, I2C LCD, Buzzer | ⭐⭐⭐ |
| [Air Quality Monitor](projects/air_quality_monitor.ino) | MQ-135, I2C LCD | ⭐⭐⭐ |
| [Water Level Monitor](projects/water_level_monitor.ino) | HC-SR04, I2C LCD, Buzzer | ⭐⭐⭐ |

### Advanced

| Project | Sensors Used | Difficulty |
|---------|-------------|------------|
| [Home Environment Dashboard](projects/home_environment_dashboard.ino) | DHT11, MQ-135, LDR, HC-SR04, PIR, Soil Moisture, I2C LCD | ⭐⭐⭐⭐⭐ |

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
- DHT11 or DHT22
- HC-SR04 ultrasonic distance sensor
- MQ-135 air quality sensor
- PIR HC-SR501 motion sensor
- Soil Moisture (capacitive)
- LDR + 10k resistor

**Displays & Feedback:**
- 16x2 LCD with I2C
- LEDs (red, green, yellow, blue) + 220ohm resistors
- Active buzzer
- Push buttons

**Actuators:**
- 5V Relay Module
- Mini water pump (3-6V)
- Micro Servo SG90
- Potentiometer (10k)

**Estimated cost:** ~$15-25 for a starter kit covering all projects.

---



### 🌡️ Temperature & Humidity (10)

| Sensor | Description | GitHub Library | Arduino Library |
|--------|-------------|----------------|-----------------|
| DHT11 | Low-cost digital temperature (0-50C) and humidity (20-80%) sensor. Slow but reliable. Max read every 2s. | [Source](https://github.com/adafruit/DHT-sensor-library) | DHT sensor library by Adafruit |
| DHT22/AM2302 | Higher accuracy temperature (-40 to 80C, +/-0.5C) and humidity (0-100%, +/-2%) than DHT11. | [Source](https://github.com/adafruit/DHT-sensor-library) | DHT sensor library by Adafruit |
| DS18B20 | Digital waterproof temperature sensor (-55 to 125C). OneWire protocol, multiple sensors on single pin. | [Source](https://github.com/PaulStoffregen/OneWire) | OneWire + DallasTemperature |
| BME280 | High-accuracy temperature, humidity, and barometric pressure sensor via I2C/SPI. Also estimates altitude. | [Source](https://github.com/adafruit/Adafruit_BME280_Library) | Adafruit BME280 Library + Adafruit Unified Sensor |
| BMP280 | Barometric pressure and temperature sensor. Cheaper than BME280 (no humidity). I2C/SPI. | [Source](https://github.com/adafruit/Adafruit_BMP280_Library) | Adafruit BMP280 Library |
| LM35 | Analog temperature sensor with linear output. 10mV per degree Celsius. Range: -55 to 150C. | [Source](https://github.com/DFRobot/DFRobot_LM35) | Built into Arduino (analogRead) |
| MAX6675 | Thermocouple amplifier for K-type thermocouples. Measures up to 1024C. SPI interface. | [Source](https://github.com/adafruit/MAX6675-library) | Adafruit MAX6675 Library |
| BMP180 | Older barometric pressure sensor (replaced by BMP280). I2C interface. Temperature + pressure. | [Source](https://github.com/adafruit/Adafruit_BMP085_Unified) | Adafruit BMP085 Unified |
| HTU21D | High precision temp/humidity sensor (+-0.3C, +-2% RH). I2C. Better than DHT11. | [Source](https://github.com/sparkfun/HTU21D_Breakout) | SparkFun HTU21D |
| SHT31 | Industrial-grade temp/humidity sensor (+-0.3C, +-2% RH). I2C. Heater element for dew removal. | [Source](https://github.com/adafruit/Adafruit_SHT31) | Adafruit SHT31 |

### 💨 Gas & Air Quality (8)

| Sensor | Description | GitHub Library | Arduino Library |
|--------|-------------|----------------|-----------------|
| MQ-2 | Detects LPG, propane, hydrogen, methane, alcohol, and smoke. Widely used for gas leak detection. | [Source](https://github.com/emc2314/mq2-gas-sensor) | MQUnifiedsensor or custom analog |
| MQ-7 | Carbon monoxide (CO) detection. Requires heating cycle for accurate readings. | [Source](https://github.com/emc2314/mq-sensor-lib) | MQ-7 Arduino Library |
| MQ-135 | General air quality sensor. Detects NH3, NOx, alcohol, benzene, smoke, and CO2. Indoor air monitoring. | [Source](https://github.com/GeorgK/MQ135) | MQ135 Library |
| SGP30 | Multi-pixel gas sensor measuring TVOC and CO2 equivalent via I2C. More accurate than MQ series. | [Source](https://github.com/adafruit/Adafruit_SGP30) | Adafruit SGP30 Library |
| Dust Sensor (GP2Y1010AU0F) | Optical dust/particulate sensor. Measures PM2.5/PM10 concentration. Analog output. | [Source](https://github.com/dfch/GP2Y1010AU0F-Dust-Sensor-Library) | Custom analog reading |
| SDS011 | Professional PM2.5/PM10 laser dust sensor. UART interface. More accurate than GP2Y. | [Source](https://github.com/ricki-z/SDS011) | SDS011 Luftdaten Library |
| MQ-131 (Ozone) | Ozone (O3) detection. Low concentration: 10-1000ppb. High concentration: 1-300ppm. | [Source](https://github.com/GeorgK/MQ-Sensors) | MQSensor Library |
| MQ-4 (Methane/Natural Gas) | Natural gas (methane/CH4) and CNG detection. Fast response time. | [Source](https://github.com/emc2314/mq-sensor-lib) | MQ Sensor Library |

### 📏 Distance & Ranging (2)

| Sensor | Description | GitHub Library | Arduino Library |
|--------|-------------|----------------|-----------------|
| HC-SR04 | Ultrasonic distance sensor. Measures 2-400cm with +/-3mm accuracy. Trig/echo interface. | [Source](https://github.com/LouisD95/HCSR04) | HCSR04 or NewPing |
| VL53L0X | Time-of-flight laser ranging sensor. 2m max range. I2C interface. Much more accurate than ultrasonic. | [Source](https://github.com/pololu/vl53l0x-arduino) | Pololu VL53L0X Arduino |

### 🏃 Motion & Orientation (5)

| Sensor | Description | GitHub Library | Arduino Library |
|--------|-------------|----------------|-----------------|
| PIR HC-SR501 | Passive infrared motion sensor. 3-7m range, 110 degree field of view. 30-60s calibration on startup. | [Source](https://github.com/adafruit/Adafruit_PIR_Sensor) | Built into Arduino (digitalRead) |
| RCWL-0516 | Microwave Doppler radar motion sensor. 5-7m range. Works through walls, unlike PIR. | [Source](https://github.com/digistump/Rcwl0516) | RCWL0516 Library |
| APDS-9960 | RGB color, ambient light, proximity, and gesture sensing via I2C. Hand swipe left/right/up/down. | [Source](https://github.com/sparkfun/SparkFun_APDS-9960_Sensor_Arduino_Library) | SparkFun APDS9960 Library |
| Tilt Sensor (Ball Switch) | Simple ball-in-cylinder tilt switch. Digital output only (open/closed). Low cost orientation detection. | [Source](https://github.com/adafruit/Tilt_Sensor) | Built into Arduino (digitalRead) |
| Vibration Sensor (SW-420) | Vibration/impact detection module. Digital output with adjustable threshold potentiometer. | [Source](https://github.com/adafruit/Vibration_Sensor) | Built into Arduino (digitalRead) |

### 🌱 Soil & Water (7)

| Sensor | Description | GitHub Library | Arduino Library |
|--------|-------------|----------------|-----------------|
| Soil Moisture (Capacitive) | Capacitive soil moisture sensor. Corrosion-resistant. Analog output (lower value = more moisture). | [Source](https://github.com/ArminJo/Capacitive-Soil-Moisture-Sensor-Library) | Capacitive Soil Moisture Library |
| Soil Moisture (Resistive) | Cheap resistive soil moisture sensor. Corrodes quickly (weeks). Higher value = more moisture. | [Source](https://github.com/adafruit/Adafruit_Capacitive_Soil_Moisture) | Built into Arduino (analogRead) |
| Rain Sensor (FC-37) | Rain/water drop detection. Analog output (wetness level) + digital threshold output. | [Source](https://github.com/adafruit/Adafruit_Rain_Sensor) | Built into Arduino (analogRead) |
| LDR (Photoresistor) | Light-dependent resistor. Voltage divider with 10k resistor. Higher value = more light (typically). | [Source](https://github.com/adafruit/Adafruit_LDR) | Built into Arduino (analogRead) |
| Water Level Sensor | Analog water level sensor. Measures water depth by resistance. Drop shape pad. | [Source](https://github.com/adafruit/Adafruit_Water_Level_Sensor) | Built into Arduino (analogRead) |
| Flow Sensor (YF-S201) | Water flow rate sensor. Hall effect based. Measures 1-30 L/min. Digital pulse output. | [Source](https://github.com/miguel5612/Arduino_water_flow_meter) | Custom (pulse counting) |
| PH Sensor (Gravity Analog) | Analog pH meter for water quality testing. 0-14 pH range. BNC connector. | [Source](https://github.com/DFRobot/DFRobot_PH) | DFRobot PH Library |

### 💡 Light & Vision (4)

| Sensor | Description | GitHub Library | Arduino Library |
|--------|-------------|----------------|-----------------|
| BH1750 | Digital ambient light sensor. Measures lux (1-65535). I2C interface. Much more accurate than LDR. | [Source](https://github.com/claws/BH1750) | BH1750 Library |
| TCS3200/TCS34725 | RGB color light-to-frequency converter. Detects actual colors, not just brightness. | [Source](https://github.com/adafruit/Adafruit_TCS34725) | Adafruit TCS34725 |
| UV Sensor (VEML6070/ML8511) | Measures UV-A/UV-B radiation. I2C or analog output. Sun exposure monitoring. | [Source](https://github.com/adafruit/Adafruit_VEML6070) | Adafruit VEML6070 |
| IR Flame Sensor | Detects infrared light from flames (760-1100nm). Digital + analog output. | [Source](https://github.com/adafruit/Flame_Sensor) | Built into Arduino (analogRead) |

### 🧭 IMU & Compass (4)

| Sensor | Description | GitHub Library | Arduino Library |
|--------|-------------|----------------|-----------------|
| MPU6050 | 6-axis IMU: 3-axis accelerometer + 3-axis gyroscope. I2C interface. Built-in temp sensor. | [Source](https://github.com/Tockn/MPU6050_tockn) | MPU6050_tockn or Adafruit MPU6050 |
| MPU9250 | 9-axis: 3-axis accel + gyro + magnetometer. I2C/SPI. More motion axes for precise orientation. | [Source](https://github.com/sparkfun/SparkFun_MPU-9250-DMP_Arduino_Library) | SparkFun MPU-9250 DMP Arduino |
| ADXL345 | Digital 3-axis accelerometer. I2C/SPI. High resolution (13-bit). Tap/double-tap detection. | [Source](https://github.com/adafruit/Adafruit_ADXL345) | Adafruit ADXL345 |
| HMC5883L | Digital 3-axis compass module. I2C interface. Used for heading/direction sensing. | [Source](https://github.com/adafruit/Adafruit_HMC5883_Unified) | Adafruit HMC5883 Unified |

### 📺 Displays (4)

| Sensor | Description | GitHub Library | Arduino Library |
|--------|-------------|----------------|-----------------|
| 16x2 LCD (HD44780) | 16 characters x 2 rows character LCD. Two wiring modes: parallel (6 pins) or I2C module (2 pins). | [Source](https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library) | LiquidCrystal (built-in) or LiquidCrystal_I2C |
| OLED 0.96" SSD1306 | 128x64 pixel OLED display. I2C interface. Bright, high contrast, low power. | [Source](https://github.com/adafruit/Adafruit_SSD1306) | Adafruit SSD1306 + Adafruit GFX |
| Nokia 5110 LCD | 84x48 pixel monochrome LCD. SPI interface. Cheap, large-ish screen. | [Source](https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library) | Adafruit PCD8544 Nokia 5110 |
| MAX7219 LED Dot Matrix | 8x8 LED dot matrix module (daisy-chainable). SPI communication. Can chain many modules. | [Source](https://github.com/markruys/arduino-Max72xxPanel) | Adafruit MAX7219 or MD_Parola |

### ⚡ Motors, Drivers & Relays (4)

| Sensor | Description | GitHub Library | Arduino Library |
|--------|-------------|----------------|-----------------|
| 5V Relay Module | Electromechanical relay. Single or 4-channel. Active-low trigger. Switches AC/DC loads up to 10A. | [Source](https://github.com/adafruit/Adafruit-Relay-Board) | Built into Arduino (digitalWrite) |
| SG90 Micro Servo | 9g micro servo motor. 180 degree rotation. 4.8V operating. Internal gear. | [Source](https://github.com/RoboticsBrno/ServoESP32) | Servo.h (built-in) |
| L298N Motor Driver | Dual H-bridge motor driver. Controls 2 DC motors or 1 stepper. Up to 2A per channel. | [Source](https://github.com/gioblu/PJON) | Built into Arduino (digitalWrite/analogWrite) |
| L293D Motor Shield | Arduino shield for driving 2 stepper motors or 4 DC motors. Up to 600mA per channel. | [Source](https://github.com/adafruit/Adafruit_Motor_Shield_library) | Adafruit Motor Shield Library |

### 📡 Communication & IR (5)

| Sensor | Description | GitHub Library | Arduino Library |
|--------|-------------|----------------|-----------------|
| HC-05/HC-06 Bluetooth | Bluetooth 2.0 serial module. HC-05 supports master+slave, HC-06 slave only. 9600 baud. | [Source](https://github.com/felias-fogg/BluetoothSerial) | SoftwareSerial + AT commands |
| nRF24L01 | 2.4GHz wireless transceiver. 1km+ range with antenna version. SPI interface. Multiple nodes. | [Source](https://github.com/nRF24/RF24) | RF24 Library |
| ESP8266 (WiFi) | ESP-01/ESP-12 WiFi module. Can also run standalone programs. Connect Arduino to internet. | [Source](https://github.com/ekstrand/ESP8266wifi) | ESP8266WiFi or SoftwareSerial AT mode |
| LoRa SX1278/SX1276 | Long-range (up to 10km) low-power wireless. 433MHz/868MHz/915MHz. SPI interface. | [Source](https://github.com/sandeepmistry/arduino-LoRa) | arduino-LoRa by Sandeep Mistry |
| IR Receiver/LED TSOP38238 | 38kHz IR receiver module. Decode from TV remotes, AC remotes. Digital output. | [Source](https://github.com/crankyoldgit/IRremoteESP8266) | IRremote or IRemoteESP8266 |

### 🔊 Sound & Audio (3)

| Sensor | Description | GitHub Library | Arduino Library |
|--------|-------------|----------------|-----------------|
| Sound Sensor (KY-037/KY-038) | Sound detection module. Analog (volume level) + digital (threshold trigger) output. | [Source](https://github.com/adafruit/Adafruit_Sound_Sensor) | Built into Arduino (analogRead/digitalRead) |
| DFPlayer Mini MP3 | Mini MP3 player module. Plays MP3/WAV from micro SD card or USB. Serial control. | [Source](https://github.com/DFRobot/DFRobotDFPlayerMini) | DFRobotDFPlayerMini |
| MAX98357A I2S Amplifier | 3W mono Class D amplifier with I2S input. Direct digital audio from I2S pins. | [Source](https://github.com/adafruit/Adafruit_MAX98357) | Adafruit_MAX98357 |

### 🔒 Security & Biometrics (3)

| Sensor | Description | GitHub Library | Arduino Library |
|--------|-------------|----------------|-----------------|
| RFID RC522 | 13.56MHz RFID/NFC reader. Reads Mifare cards and tags. SPI interface. Great for access control. | [Source](https://github.com/miguelbalboa/rfid) | MFRC522 Library |
| Fingerprint Sensor (R503) | Optical fingerprint sensor with onboard processing. UART or USB interface. Stores up to 3000 prints. | [Source](https://github.com/adafruit/Adafruit-Fingerprint-Sensor-Library) | Adafruit Fingerprint |
| PN532 NFC/RFID | NFC reader/writer. Supports I2C, SPI, HSU modes. Reads NFC tags, emulates cards. | [Source](https://github.com/adafruit/Adafruit-PN532) | Adafruit PN532 |

### ⏱️ Measurement & Timing (4)

| Sensor | Description | GitHub Library | Arduino Library |
|--------|-------------|----------------|-----------------|
| ACS712 | Hall-effect based AC/DC current sensor. Available in 5A, 20A, 30A variants. Analog output. | [Source](https://github.com/RobertTW/ACS712-Arduino-Library) | ACS712 Current Sensor Library |
| ZMPT101B | AC voltage sensor module. Measures 220V/110V AC mains voltage safely. Analog output. | [Source](https://github.com/limagiran/zmpt101b-arduino) | ZMPT101B Library |
| DS3231 RTC | High precision real-time clock with temperature compensation. I2C. Built-in battery backup. | [Source](https://github.com/adafruit/RTClib) | RTClib by Adafruit |
| HX711 Load Cell | 24-bit ADC for load cells. Weighing scale bridge sensor. Very high resolution. | [Source](https://github.com/bogde/HX711) | HX711 Arduino Library by bogde |


---

### Quick Install Guide
1. **Arduino IDE**: Sketch → Include Library → Manage Libraries
2. **Search**: Type the library name from the table
3. **Install**: Click the Install button
4. **Verify**: File → Examples → [Library] → [Example Sketch]

### Notes
- All sensors tested with Arduino Uno R3 compatibility
- I2C sensors use: SDA=A4, SCL=A5 (Uno)
- Check voltage requirements (3.3V vs 5V)
- Gas sensors need 24-48h warmup for calibration

---

## Project Structure

```
dotinoproject/
├── README.md
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
4. Add new sensors to the Sensors Reference section above

---

## License

MIT
