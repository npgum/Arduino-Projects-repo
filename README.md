# dotinoproject

Arduino projects and sensor reference catalog.

We want to appreciate and recognize the **open-source library creators and makers** whose hard work made these projects possible.**To the makers who write the library, drivers, document the wiring, and share their knowledge.** Thank you.

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



## Sensors
---

### Quick Install Guide
1. **Arduino IDE**: Sketch → Include Library → Manage Libraries
2. **Search**: Type the library name from the table
3. **Install**: Click the Install button
4. **Verify**: File → Examples → [Library] → [Example Sketch]

### 🔧 Manual Library Installation

Use this when a library isn't available in the Arduino Library Manager, or when you need a specific version from GitHub.

**Step 1: Download the library**
- Visit the GitHub link from the sensor table above
- Click the green **Code** button → **Download ZIP**
- Or clone with: `git clone <repo-url>`

**Step 2: Install via Arduino IDE**
- Open Arduino IDE → Sketch → Include Library → **Add .ZIP Library**
- Select the downloaded ZIP file
- The IDE handles extraction and placement automatically

**Step 3: Install manually (folder method)**
- Extract the ZIP file
- Rename the folder to match the library name (no `-master` or `-main` suffix)
- Move it to your Arduino libraries folder:
  - **Linux**: `~/Arduino/libraries/`
  - **Windows**: `Documents\Arduino\libraries\`
  - **macOS**: `~/Documents/Arduino/libraries/`
- Restart the Arduino IDE

**Step 4: Handle dependencies**
- Some libraries require others (e.g., DHT needs **Adafruit Unified Sensor**, OLED needs **Adafruit GFX**)
- Install all dependencies listed alongside each sensor before compiling
- Use the Library Manager for dependencies when possible — it resolves transitive deps

**Step 5: Verify**
- Restart the IDE after installing
- Open File → Examples → [Library Name] → [Example]
- Compile a test sketch to confirm no missing headers

**Troubleshooting**
| Problem | Solution |
|---------|----------|
| `No such file or directory` error | Library folder name doesn't match the `#include` name — rename it |
| Multiple library versions found | Remove old versions from `~/Arduino/libraries/`, keep only one |
| ZIP library install fails | Ensure the ZIP contains a single top-level folder, not loose files |
| Library not showing in Examples menu | Restart the IDE, then check if the folder is in the correct libraries path |


### 🌡️ Temperature & Humidity (10)

| Sensor | Description | GitHub Library | Library |
|--------|-------------|----------------|-----------------|
| DHT11 | Low-cost digital temperature (0-50C) and humidity (20-80%) sensor. Slow but reliable. Max read every 2s. | [Source](https://github.com/adafruit/DHT-sensor-library) | DHT sensor library by Adafruit |
| DHT22/AM2302 | Higher accuracy temperature (-40 to 80C, +/-0.5C) and humidity (0-100%, +/-2%) than DHT11. | [Source](https://github.com/adafruit/DHT-sensor-library) | DHT sensor library by Adafruit |
| DS18B20 | Digital waterproof temperature sensor (-55 to 125C). OneWire protocol, multiple sensors on single pin. | [Source](https://github.com/PaulStoffregen/OneWire) | OneWire + DallasTemperature |
| BME280 | High-accuracy temperature, humidity, and barometric pressure sensor via I2C/SPI. Also estimates altitude. | [Source](https://github.com/adafruit/Adafruit_BME280_Library) | Adafruit BME280 Library + Adafruit Unified Sensor |
| BMP280 | Barometric pressure and temperature sensor. Cheaper than BME280 (no humidity). I2C/SPI. | [Source](https://github.com/adafruit/Adafruit_BMP280_Library) | Adafruit BMP280 Library |
| LM35 | Analog temperature sensor with linear output. 10mV per degree Celsius. Range: -55 to 150C. | [Source](https://github.com/Erriez/ErriezLM35) | Erriez LM35 |
| MAX6675 | Thermocouple amplifier for K-type thermocouples. Measures up to 1024C. SPI interface. | [Source](https://github.com/adafruit/MAX6675-library) | Adafruit MAX6675 Library |
| BMP180 | Older barometric pressure sensor (replaced by BMP280). I2C interface. Temperature + pressure. | [Source](https://github.com/adafruit/Adafruit_BMP085_Unified) | Adafruit BMP085 Unified |
| HTU21D | High precision temp/humidity sensor (+-0.3C, +-2% RH). I2C. Better than DHT11. | [Source](https://github.com/sparkfun/HTU21D_Breakout) | SparkFun HTU21D |
| SHT31 | Industrial-grade temp/humidity sensor (+-0.3C, +-2% RH). I2C. Heater element for dew removal. | [Source](https://github.com/adafruit/Adafruit_SHT31) | Adafruit SHT31 |

### 💨 Gas & Air Quality (8)

| Sensor | Description | GitHub Library | Library |
|--------|-------------|----------------|-----------------|
| MQ-2 | Detects LPG, propane, hydrogen, methane, alcohol, and smoke. Widely used for gas leak detection. | [Source](https://github.com/miguel5612/MQSensorsLib) | MQUnifiedsensor (MQSensorsLib) |
| MQ-7 | Carbon monoxide (CO) detection. Requires heating cycle for accurate readings. | [Source](https://github.com/miguel5612/MQSensorsLib) | MQUnifiedsensor (MQSensorsLib) |
| MQ-135 | General air quality sensor. Detects NH3, NOx, alcohol, benzene, smoke, and CO2. Indoor air monitoring. | [Source](https://github.com/Bobbo117/MQ135-Air-Quality-Sensor) | MQ135 Library |
| SGP30 | Multi-pixel gas sensor measuring TVOC and CO2 equivalent via I2C. More accurate than MQ series. | [Source](https://github.com/adafruit/Adafruit_SGP30) | Adafruit SGP30 Library |
| Dust Sensor (GP2Y1010AU0F) | Optical dust/particulate sensor. Measures PM2.5/PM10 concentration. Analog output. | [Source](https://github.com/mickey9801/GP2Y1010AU0F) | GP2Y1010AU0F Dust Sensor |
| SDS011 | Professional PM2.5/PM10 laser dust sensor. UART interface. More accurate than GP2Y. | [Source](https://github.com/ricki-z/SDS011) | SDS011 Luftdaten Library |
| MQ-131 (Ozone) | Ozone (O3) detection. Low concentration: 10-1000ppb. High concentration: 1-300ppm. | [Source](https://github.com/ostaquet/Arduino-MQ131-driver) | MQ131 Ozone Driver |
| MQ-4 (Methane/Natural Gas) | Natural gas (methane/CH4) and CNG detection. Fast response time. | [Source](https://github.com/miguel5612/MQSensorsLib) | MQUnifiedsensor (MQSensorsLib) |

***NOTE**: For MQ Series sensor you can use Unified [MQSensorsLib](https://github.com/miguel5612/MQSensorsLib) in MQ-4  

### 📏 Distance & Ranging (2)

| Sensor | Description | GitHub Library | Library |
|--------|-------------|----------------|-----------------|
| HC-SR04 | Ultrasonic distance sensor. Measures 2-400cm with +/-3mm accuracy. Trig/echo interface. | [Source](https://github.com/Martinsos/arduino-lib-hc-sr04) | HCSR04 or NewPing |
| VL53L0X | Time-of-flight laser ranging sensor. 2m max range. I2C interface. Much more accurate than ultrasonic. | [Source](https://github.com/pololu/vl53l0x-arduino) | Pololu VL53L0X Arduino |

### 🏃 Motion & Orientation (5)

| Sensor | Description | GitHub Library | Library |
|--------|-------------|----------------|-----------------|
| PIR HC-SR501 | Passive infrared motion sensor. 3-7m range, 110 degree field of view. 30-60s calibration on startup. | [Source](https://github.com/limorfru/Adafruit_PIR) | Built into Arduino (digitalRead) |
| RCWL-0516 | Microwave Doppler radar motion sensor. 5-7m range. Works through walls, unlike PIR. | [Source](https://github.com/jdesbonnet/RCWL-0516) | RCWL-0516 Arduino Library |
| APDS-9960 | RGB color, ambient light, proximity, and gesture sensing via I2C. Hand swipe left/right/up/down. | [Source](https://github.com/sparkfun/SparkFun_APDS-9960_Sensor_Arduino_Library) | SparkFun APDS9960 Library |
| Tilt Sensor (Ball Switch) | Simple ball-in-cylinder tilt switch. Digital output only (open/closed). Low cost orientation detection. | [Source](https://github.com/mprograms/Detect-Tilt-Arduino) | Built into Arduino (digitalRead) |
| Vibration Sensor (SW-420) | Vibration/impact detection module. Digital output with adjustable threshold potentiometer. | [Source](https://github.com/ArminJo/Arduino-SensorKit) | Built into Arduino (digitalRead) |

### 🌱 Soil & Water (6)

| Sensor | Description | GitHub Library | Library |
|--------|-------------|----------------|-----------------|
| Soil Moisture (Capacitive) | Capacitive soil moisture sensor. Corrosion-resistant. Analog output (lower value = more moisture). | [Source](https://github.com/ArminJo/Arduino-SensorKit) | Soil Moisture Sensor Library |
| Soil Moisture (Resistive) | Cheap resistive soil moisture sensor. Corrodes quickly (weeks). Higher value = more moisture. | [Source](https://github.com/adafruit/Adafruit_SensorLab) | Built into Arduino (analogRead) |
| Rain Sensor (FC-37) | Rain/water drop detection. Analog output (wetness level) + digital threshold output. | [Source](https://github.com/adafruit/Adafruit_SensorLab) | Built into Arduino (analogRead) |
| Water Level Sensor | Analog water level sensor. Measures water depth by resistance. Drop shape pad. | [Source](https://github.com/ArminJo/Arduino-SensorKit) | Built into Arduino (analogRead) |
| Flow Sensor (YF-S201) | Water flow rate sensor. Hall effect based. Measures 1-30 L/min. Digital pulse output. | [Source](https://github.com/adafruit/Adafruit_SensorLab) | Custom (pulse counting) |
| PH Sensor (Gravity Analog) | Analog pH meter for water quality testing. 0-14 pH range. BNC connector. | [Source](https://github.com/DFRobot/DFRobot_PH) | DFRobot PH Library |

### 💡 Light & Vision (5)

| Sensor | Description | GitHub Library | Library |
|--------|-------------|----------------|-----------------|
| LDR (Photoresistor) | Light-dependent resistor. Voltage divider with 10k resistor. Higher value = more light (typically). | [Source](https://github.com/adafruit/Adafruit_SensorLab) | Built into Arduino (analogRead) |
| BH1750 | Digital ambient light sensor. Measures lux (1-65535). I2C interface. Much more accurate than LDR. | [Source](https://github.com/claws/BH1750) | BH1750 Library |
| TCS3200/TCS34725 | RGB color light-to-frequency converter. Detects actual colors, not just brightness. | [Source](https://github.com/adafruit/Adafruit_TCS34725) | Adafruit TCS34725 |
| UV Sensor (VEML6070/ML8511) | Measures UV-A/UV-B radiation. I2C or analog output. Sun exposure monitoring. | [Source](https://github.com/adafruit/Adafruit_VEML6070) | Adafruit VEML6070 |
| IR Flame Sensor | Detects infrared light from flames (760-1100nm). Digital + analog output. | [Source](https://github.com/adafruit/Adafruit_SensorLab) | Built into Arduino (analogRead) |

### 🧭 IMU & Compass (4)

| Sensor | Description | GitHub Library | Library |
|--------|-------------|----------------|-----------------|
| MPU6050 | 6-axis IMU: 3-axis accelerometer + 3-axis gyroscope. I2C interface. Built-in temp sensor. | [Source](https://github.com/Tockn/MPU6050_tockn) | MPU6050_tockn or Adafruit MPU6050 |
| MPU9250 | 9-axis: 3-axis accel + gyro + magnetometer. I2C/SPI. More motion axes for precise orientation. | [Source](https://github.com/sparkfun/SparkFun_MPU-9250-DMP_Arduino_Library) | SparkFun MPU-9250 DMP Arduino |
| ADXL345 | Digital 3-axis accelerometer. I2C/SPI. High resolution (13-bit). Tap/double-tap detection. | [Source](https://github.com/adafruit/Adafruit_ADXL345) | Adafruit ADXL345 |
| HMC5883L | Digital 3-axis compass module. I2C interface. Used for heading/direction sensing. | [Source](https://github.com/adafruit/Adafruit_HMC5883_Unified) | Adafruit HMC5883 Unified |




### 🔒 Security & Biometrics (3)

| Sensor | Description | GitHub Library | Library |
|--------|-------------|----------------|-----------------|
| RFID RC522 | 13.56MHz RFID/NFC reader. Reads Mifare cards and tags. SPI interface. Great for access control. | [Source](https://github.com/miguelbalboa/rfid) | MFRC522 Library |
| Fingerprint Sensor (R503) | Optical fingerprint sensor with onboard processing. UART or USB interface. Stores up to 3000 prints. | [Source](https://github.com/adafruit/Adafruit-Fingerprint-Sensor-Library) | Adafruit Fingerprint |
| PN532 NFC/RFID | NFC reader/writer. Supports I2C, SPI, HSU modes. Reads NFC tags, emulates cards. | [Source](https://github.com/adafruit/Adafruit-PN532) | Adafruit PN532 |

### ⏱️ Measurement & Timing (4)

| Sensor | Description | GitHub Library | Library |
|--------|-------------|----------------|-----------------|
| ACS712 | Hall-effect based AC/DC current sensor. Available in 5A, 20A, 30A variants. Analog output. | [Source](https://github.com/RTW88/ACS712-Arduino-Library) | ACS712 Current Sensor |
| ZMPT101B | AC voltage sensor module. Measures 220V/110V AC mains voltage safely. Analog output. | [Source](https://github.com/limagiran/zmpt101b-arduino) | ZMPT101B Library |
| DS3231 RTC | High precision real-time clock with temperature compensation. I2C. Built-in battery backup. | [Source](https://github.com/adafruit/RTClib) | RTClib by Adafruit |
| HX711 Load Cell | 24-bit ADC for load cells. Weighing scale bridge sensor. Very high resolution. | [Source](https://github.com/bogde/HX711) | HX711 Library by bogde |


---

## 📺 Displays (4)

| Sensor | Description | GitHub Library | Library |
|--------|-------------|----------------|-----------------|
| 16x2 LCD (HD44780) | 16 characters x 2 rows character LCD. Two wiring modes: parallel (6 pins) or I2C module (2 pins). | [Source](https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library) | LiquidCrystal (built-in) or LiquidCrystal_I2C |
| OLED 0.96" SSD1306 | 128x64 pixel OLED display. I2C interface. Bright, high contrast, low power. | [Source](https://github.com/adafruit/Adafruit_SSD1306) | Adafruit SSD1306 + Adafruit GFX |
| Nokia 5110 LCD | 84x48 pixel monochrome LCD. SPI interface. Cheap, large-ish screen. | [Source](https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library) | Adafruit PCD8544 Nokia 5110 |
| MAX7219 LED Dot Matrix | 8x8 LED dot matrix module (daisy-chainable). SPI communication. Can chain many modules. | [Source](https://github.com/markruys/arduino-Max72xxPanel) | Adafruit MAX7219 or MD_Parola |

---

---

## 🔊 Sound & Audio (3)

| Sensor | Description | GitHub Library | Library |
|--------|-------------|----------------|-----------------|
| Sound Sensor (KY-037/KY-038) | Sound detection module. Analog (volume level) + digital (threshold trigger) output. | [Source](https://github.com/adafruit/Adafruit_Loudness_Sensor) | Built into Arduino (analogRead/digitalRead) |
| DFPlayer Mini MP3 | Mini MP3 player module. Plays MP3/WAV from micro SD card or USB. Serial control. | [Source](https://github.com/DFRobot/DFRobotDFPlayerMini) | DFRobotDFPlayerMini |
| MAX98357A I2S Amplifier | 3W mono Class D amplifier with I2S input. Direct digital audio from I2S pins. | [Source](https://github.com/adafruit/Adafruit_MAX98357) | Adafruit MAX98357A |

---

## 📡 Communication & IR (5)

| Sensor | Description | GitHub Library | Library |
|--------|-------------|----------------|-----------------|
| HC-05/HC-06 Bluetooth | Bluetooth 2.0 serial module. HC-05 supports master+slave, HC-06 slave only. 9600 baud. | [Source](https://github.com/RoboCraft/Bluetooth_HC05) | SoftwareSerial + AT commands |
| nRF24L01 | 2.4GHz wireless transceiver. 1km+ range with antenna version. SPI interface. Multiple nodes. | [Source](https://github.com/nRF24/RF24) | RF24 Library |
| ESP8266 (WiFi) | ESP-01/ESP-12 WiFi module. Can also run standalone programs. Connect Arduino to internet. | [Source](https://github.com/ekstrand/ESP8266wifi) | ESP8266WiFi or SoftwareSerial AT mode |
| LoRa SX1278/SX1276 | Long-range (up to 10km) low-power wireless. 433MHz/868MHz/915MHz. SPI interface. | [Source](https://github.com/sandeepmistry/arduino-LoRa) | arduino-LoRa by Sandeep Mistry |
| IR Receiver/LED TSOP38238 | 38kHz IR receiver module. Decode from TV remotes, AC remotes. Digital output. | [Source](https://github.com/Arduino-IRremote/Arduino-IRremote) | IRremote Ken Shirriff's |


### ⚡ Actuators (9)

| Actuator | Description | GitHub Library | Arduino Library |
|----------|-------------|----------------|-----------------|
| 5V Relay Module | Electromechanical relay. Single or 4-channel. Active-low trigger. Switches AC/DC loads up to 10A. | [Source](https://github.com/adafruit/Adafruit_FeatherWing_Dual_Relay) | Built into Arduino (digitalWrite) |
| SG90 Micro Servo | 9g micro servo motor. 180 degree rotation. 4.8V operating. Internal gear. | [Source](https://github.com/RoboticsBrno/ServoESP32) | Servo.h (built-in) |
| L298N Motor Driver | Dual H-bridge motor driver. Controls 2 DC motors or 1 stepper. Up to 2A per channel. | [Source](https://github.com/gioblu/PJON) | Built into Arduino (digitalWrite/analogWrite) |
| L293D Motor Shield | Arduino shield for driving 2 stepper motors or 4 DC motors. Up to 600mA per channel. | [Source](https://github.com/adafruit/Adafruit_Motor_Shield_V2_Library) | Adafruit Motor Shield V2 Library |
| 28BYJ-48 Stepper Motor | Cheap, precise 5V stepper with ULN2003 driver board. Great for clocks, gates, and small robots. | [Source](https://github.com/arduino-libraries/Stepper) | Stepper (built-in) |
| A4988 / DRV8825 Driver | Microstepping drivers for NEMA 17/23 stepper motors. Controls speed/direction with 2 pins. | [Source](https://github.com/laurb9/StepperDriver) | A4988 Stepper Driver |
| MG996R Metal Servo | High torque (10kg-cm) standard servo with metal gears. Good for robot arms/car steering. | [Source](https://github.com/RoboticsBrno/ServoESP32) | Servo.h (built-in) |
| Solid State Relay (SSR) | Silent, fast switching for AC loads. Opto-isolated input switches 24-380VAC without mechanical parts. | [Source](https://github.com/panStamp/relay) | Built into Arduino (digitalWrite) |
| Vibration Motor (DC Disc) | Small coin/disc motor for haptic feedback. Driven via PWM/Transistor for intensity control. | [Source](https://github.com/adafruit/Adafruit_SensorLab) | Built into Arduino (analogWrite) |

### 📡 Wireless & Positioning (4)

| Module | Description | GitHub Library | Arduino Library |
|--------|-------------|----------------|-----------------|
| NEO-6M / NEO-M8N GPS | Ublox GPS module with ceramic antenna. Serial UART. Tracks location, speed, time, satellites. | [Source](https://github.com/mikalhart/TinyGPSPlus) | TinyGPSPlus |
| SIM800L GSM/GPRS | Quad-band cellular module. Send SMS, make calls, GPRS data. Requires 3.7V-4.2V LiPo usually. | [Source](https://github.com/vshymanskyy/TinyGSM) | TinyGSM |
| ESP32 (Co-processor) | Dual-core WiFi/BT module. Can run Arduino sketches or act as modem for Uno via UART. | [Source](https://github.com/nkolban/ESP32_BLE_Arduino) | ESP32 Arduino Core |
| MCP2515 CAN Bus | Controller Area Network transceiver for automotive/industrial buses. SPI interface. | [Source](https://github.com/coryjfowler/MCP_CAN_lib) | MCP_CAN_lib |

### ❤️ Health & Biomedical (3)

| Sensor | Description | GitHub Library | Library |
|--------|-------------|----------------|-----------------|
| MAX30102 | Pulse oximeter and heart rate monitor via PPG. Measures SpO2 and BPM from fingertip. I2C interface. | [Source](https://github.com/sparkfun/SparkFun_MAX3010x_Sensor_Library) | SparkFun MAX3010x |
| AD8232 | ECG/heart electrical signal module. Single-lead output amplifies cardiac activity. Analog output. | [Source](https://github.com/sparkfun/AD8232_Heart_Rate_Monitor) | SparkFun AD8232 |
| MAX30101 | 3-wavelength PPG for SpO2, heart rate, and respiration rate. More versatile than MAX30102. I2C. | [Source](https://github.com/tutrp/Max30101-Arduino-Library) | MAX30101 Arduino |

### 🌡️ IR & Thermal (2)

| Sensor | Description | GitHub Library | Library |
|--------|-------------|----------------|-----------------|
| MLX90614 | Non-contact IR thermometer. Measures ambient and object temp (-40 to 300C). +/-0.5C accuracy. I2C. | [Source](https://github.com/adafruit/Adafruit-MLX90614-Library) | Adafruit MLX90614 |
| MLX90640 | 32x24 pixel thermal imaging camera. Full heat map visualization. I2C interface. Real-time IR imaging. | [Source](https://github.com/adafruit/Adafruit_MLX90640) | Adafruit MLX90640 |

### 🧭 Advanced IMU (3)

| Sensor | Description | GitHub Library | Library |
|--------|-------------|----------------|-----------------|
| LSM6DS3 | 6-axis IMU: 3-axis accel + gyro. Lower power than MPU6050. SPI/I2C. Built-in step counter. | [Source](https://github.com/adafruit/Adafruit_LSM6DS) | Adafruit LSM6DS |
| BNO055 | 9-axis absolute orientation sensor. On-chip sensor fusion outputs quaternion/Euler angles directly. No external math. | [Source](https://github.com/adafruit/Adafruit_BNO055) | Adafruit BNO055 |
| BNO080/BNO085 | VR-grade IMU with ARM Cortex M0 processing sensor fusion. Rotation vector output. AR/VR ready. I2C. | [Source](https://github.com/sparkfun/SparkFun_BNO08x_Arduino_Library) | SparkFun BNO08x |

### 🌡️ Pressure & Weather (2)

| Sensor | Description | GitHub Library | Library |
|--------|-------------|----------------|-----------------|
| LPS22HB | Miniature piezoresistive pressure sensor (260-1260 hPa). I2C/SPI. Used in drones and wearables. | [Source](https://github.com/pololu/lps22hb-arduino) | Pololu LPS22HB |
| MS5611 | High-resolution barometric altimeter (10cm resolution). I2C/SPI. Common in flight controllers. | [Source](https://github.com/millerlp/MS5611) | MS5611 Arduino |

### 🌱 Water Quality (2)

| Sensor | Description | GitHub Library | Library |
|--------|-------------|----------------|-----------------|
| TDS Meter (Gravity) | Water total dissolved solids sensor. Measures water purity and conductivity. Analog output. | [Source](https://github.com/DFRobot/DFRobot_TDS) | DFRobot TDS |
| Turbidity Sensor | Detects water clarity via light scattering. Analog output. Water quality monitoring. | Custom | Built into Arduino (analogRead) |

### 🔊 Sound (1)

| Sensor | Description | GitHub Library | Library |
|--------|-------------|----------------|-----------------|
| INMP441 | MEMS omnidirectional microphone with I2S digital output. High-quality audio capture. | Custom | I2S built-in (ESP32) |

<!--
### 📟 Compatible Boards (7)

| Board | Description | GitHub Core | Notes |
|-------|-------------|-------------|-------|
| ESP32 DevKit V1 | Dual core Xtensa LX6, WiFi, Bluetooth 4.2/BLE. 520KB SRAM. | [Source](https://github.com/espressif/arduino-esp32) | High power, cheap, popular IoT board |
| Wemos D1 Mini | ESP8266-based, very small form factor. Built-in WiFi. 4MB Flash. | [Source](https://github.com/esp8266/Arduino) | Great for sensors/IoT nodes |
| STM32 Blue Pill | ARM Cortex-M3 (72MHz). 64KB SRAM, 128KB Flash. 3.3V logic. | [Source](https://github.com/stm32duino/Arduino_Core_STM32) | Much faster than Uno, cheap |
| Seeeduino XIAO | SAMD21 ARM Cortex-M0+, tiny size (thumb). USB-C. | [Source](https://github.com/Seeed-Studio/ArduinoCore-samd) | Smallest Arduino, wearables |
| Arduino Mega 2560 | ATmega2560, 256KB Flash, 54 Digital I/O. | [Source](https://github.com/arduino/ArduinoCore-avr) | Best for complex projects needing many pins |
| Digispark (ATtiny85) | ATtiny85, 6KB Flash, 6 pins. Programmable via USB (bitbang). | [Source](https://github.com/digistump/DigistumpArduino) | Tiny standalone projects |
| Teensy 4.1 | ARM Cortex-M7 (600MHz). Huge memory, high speed. | [Source](https://github.com/PaulStoffregen/cores) | High-performance, audio, complex graphics |

-->


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





