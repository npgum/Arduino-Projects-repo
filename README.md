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


### 🌡️ Temperature & Humidity (10)

| Sensor | Description | GitHub Source | Library |
|----------|------------------------------|--------------------|--------------------|
| DHT11 | Low-cost digital temperature/humidity. Max read every 2s. | [Source](https://github.com/adafruit/DHT-sensor-library) | DHT sensor library (Adafruit) |
| DHT22/AM2302 | Higher accuracy (-40 to 80C) temp/humidity. | [Source](https://github.com/adafruit/DHT-sensor-library) | DHT sensor library (Adafruit) |
| DS18B20 | Waterproof 1-Wire temp sensor. Multiple on single pin. | [Source](https://github.com/PaulStoffregen/OneWire) | OneWire + DallasTemperature |
| BME280 | Temp, humidity, and pressure sensor via I2C/SPI. | [Source](https://github.com/adafruit/Adafruit_BME280_Library) | Adafruit BME280 + Unified Sensor |
| BMP280 | Pressure and temp sensor. Cheaper than BME280 (no humidity). | [Source](https://github.com/adafruit/Adafruit_BMP280_Library) | Adafruit BMP280 Library |
| LM35 | Analog linear temp sensor. 10mV/C. | [Source](https://github.com/Erriez/ErriezLM35) | Erriez LM35 |
| MAX6675 | K-type thermocouple amplifier (up to 1024C). | [Source](https://github.com/adafruit/MAX6675-library) | Adafruit MAX6675 Library |
| BMP180 | Older barometric pressure/altimeter sensor. | [Source](https://github.com/adafruit/Adafruit_BMP085_Unified) | Adafruit BMP085 Unified |
| HTU21D | High precision I2C temp/humidity sensor. | [Source](https://github.com/sparkfun/HTU21D_Breakout) | SparkFun HTU21D |
| SHT31 | Industrial-grade temp/humidity with heater. | [Source](https://github.com/adafruit/Adafruit_SHT31) | Adafruit SHT31 |


### 💨 Gas & Air Quality (8)

| Sensor | Description | GitHub Source | Library |
|----------|------------------------------|--------------------|--------------------|
| MQ-2 | LPG, propane, hydrogen, methane, and smoke detection. | [Source](https://github.com/miguel5612/MQSensorsLib) | MQUnifiedsensor (MQSensorsLib) |
| MQ-7 | Carbon monoxide (CO) detection. | [Source](https://github.com/miguel5612/MQSensorsLib) | MQUnifiedsensor (MQSensorsLib) |
| MQ-135 | Indoor air quality: NH3, NOx, alcohol, smoke, CO2. | [Source](https://github.com/GeorgK/MQ135) | MQ135 Library |
| MQ-4 | Methane and natural gas detection. | [Source](https://github.com/miguel5612/MQSensorsLib) | MQUnifiedsensor (MQSensorsLib) |
| SGP30 | TVOC and CO2 equivalent via I2C. Higher accuracy than MQ. | [Source](https://github.com/adafruit/Adafruit_SGP30) | Adafruit SGP30 Library |
| Dust (GP2Y1010AU0F) | Optical PM2.5/PM10 dust sensor. | [Source](https://github.com/mickey9801/GP2Y1010AU0F) | GP2Y1010AU0F Dust Sensor |
| SDS011 | Professional laser PM2.5/PM10 dust sensor via UART. | [Source](https://github.com/ricki-z/SDS011) | SDS011 Luftdaten Library |
| MQ-131 | Ozone (O3) detection. 10-1000ppb. | [Source](https://github.com/ostaquet/Arduino-MQ131-driver) | MQ131 Ozone Driver |


### 📏 Distance & Ranging (2)

| Sensor | Description | GitHub Source | Library |
|----------|------------------------------|--------------------|--------------------|
| HC-SR04 | Ultrasonic distance sensor. 2-400cm. | [Source](https://github.com/Martinsos/arduino-lib-hc-sr04) | HCSR04 or NewPing |
| VL53L0X | Time-of-flight laser ranging. 2m max, I2C. | [Source](https://github.com/pololu/vl53l0x-arduino) | Pololu VL53L0X Arduino |


### 🏃 Motion & Orientation (5)

| Sensor | Description | GitHub Source | Library |
|----------|------------------------------|--------------------|--------------------|
| PIR HC-SR501 | Passive IR motion. 3-7m range. | [Source](https://github.com/arduino/ArduinoCore-avr) | Built-in (digitalRead) — Arduino Core |
| RCWL-0516 | Microwave Doppler radar motion. Works through walls. | [Source](https://github.com/jdesbonnet/RCWL-0516) | RCWL-0516 Arduino Library |
| APDS-9960 | RGB color, ambient light, proximity, gesture via I2C. | [Source](https://github.com/sparkfun/SparkFun_APDS-9960_Sensor_Arduino_Library) | SparkFun APDS9960 Library |
| Tilt Sensor (Ball) | Digital ball-in-cylinder tilt switch. | [Source](https://github.com/arduino/ArduinoCore-avr) | Built-in (digitalRead) — Arduino Core |
| Vibration Sensor (SW-420) | Digital vibration/impact detection. | [Source](https://github.com/arduino/ArduinoCore-avr) | Built-in (digitalRead) — Arduino Core |


### 💡 Light & Vision (5)

| Sensor | Description | GitHub Source | Library |
|----------|------------------------------|--------------------|--------------------|
| LDR (Photoresistor) | Light-dependent resistor via voltage divider. | [Source](https://github.com/arduino/ArduinoCore-avr) | Built-in (analogRead) — Arduino Core |
| BH1750 | Digital lux meter via I2C. 1-65535 lux. | [Source](https://github.com/claws/BH1750) | BH1750 Library |
| TCS3200/TCS34725 | RGB color light-to-frequency converter. | [Source](https://github.com/adafruit/Adafruit_TCS34725) | Adafruit TCS34725 |
| UV Sensor (VEML6070) | UV-A/UV-B radiation sensor via I2C. | [Source](https://github.com/adafruit/Adafruit_VEML6070) | Adafruit VEML6070 |
| IR Flame Sensor | Flame detection (760-1100nm infrared). | [Source](https://github.com/arduino/ArduinoCore-avr) | Built-in (analogRead) — Arduino Core |


### 🌱 Soil & Water (6)

| Sensor | Description | GitHub Source | Library |
|----------|------------------------------|--------------------|--------------------|
| Soil Moisture (Capacitive) | Corrosion-resistant analog moisture detector. | [Source](https://github.com/ArminJo/Arduino-SensorKit) | Soil Moisture Sensor Library |
| Soil Moisture (Resistive) | Basic cheap analog moisture (corrodes quickly). | [Source](https://github.com/arduino/ArduinoCore-avr) | Built-in (analogRead) — Arduino Core |
| Rain Sensor (FC-37) | Analog/digital rain detection. | [Source](https://github.com/arduino/ArduinoCore-avr) | Built-in (analogRead) — Arduino Core |
| Water Level Sensor | Analog depth detection via exposed pad. | [Source](https://github.com/arduino/ArduinoCore-avr) | Built-in (analogRead) — Arduino Core |
| Flow Sensor (YF-S201) | Hall effect water flow (1-30 L/min). | [Source](https://github.com/arduino/ArduinoCore-avr) | pulseIn() — Arduino Core |
| pH Sensor (Gravity) | 0-14 pH analog meter via BNC connector. | [Source](https://github.com/DFRobot/DFRobot_PH) | DFRobot PH Library |


### 💧 Water Quality (2)

| Sensor | Description | GitHub Source | Library |
|----------|------------------------------|--------------------|--------------------|
| TDS Meter (Gravity) | Measures water purity via conductivity. | [Source](https://github.com/DFRobot/DFRobot_TDS) | DFRobot TDS |
| Turbidity Sensor SEN0189 | Water clarity via light scattering. | [Source](https://github.com/duyhuynh/Turbidity_Sensor) | DTH_Turbidity_Sensor |


### 🧭 IMU & Compass (7)

| Sensor | Description | GitHub Source | Library |
|----------|------------------------------|--------------------|--------------------|
| MPU6050 | 6-axis IMU: 3-axis accel + gyro via I2C. | [Source](https://github.com/Tockn/MPU6050_tockn) | MPU6050_tockn or Adafruit MPU6050 |
| MPU9250 | 9-axis IMU: accel + gyro + magnetometer. | [Source](https://github.com/sparkfun/SparkFun_MPU-9250-DMP_Arduino_Library) | SparkFun MPU-9250 DMP |
| ADXL345 | High-resolution 13-bit 3-axis accelerometer. | [Source](https://github.com/adafruit/Adafruit_ADXL345) | Adafruit ADXL345 |
| HMC5883L | Digital 3-axis compass via I2C. | [Source](https://github.com/adafruit/Adafruit_HMC5883_Unified) | Adafruit HMC5883 Unified |
| LSM6DS3 | 6-axis IMU (lower power). SPI/I2C. Built-in step counter. | [Source](https://github.com/adafruit/Adafruit_LSM6DS) | Adafruit LSM6DS |
| BNO055 | 9-axis absolute orientation sensor (sensor fusion). | [Source](https://github.com/adafruit/Adafruit_BNO055) | Adafruit BNO055 |
| BNO080/BNO085 | VR-grade IMU with sensor fusion. AR/VR ready. | [Source](https://github.com/sparkfun/SparkFun_BNO08x_Arduino_Library) | SparkFun BNO08x |


### 🔥 IR & Thermal (2)

| Sensor | Description | GitHub Source | Library |
|----------|------------------------------|--------------------|--------------------|
| MLX90614 | Non-contact IR thermometer (-40 to 300C). I2C. | [Source](https://github.com/adafruit/Adafruit-MLX90614-Library) | Adafruit MLX90614 |
| MLX90640 | 32x24 pixel thermal imaging camera via I2C. | [Source](https://github.com/adafruit/Adafruit_MLX90640) | Adafruit MLX90640 |


### 🔒 Security & Biometrics (3)

| Sensor | Description | GitHub Source | Library |
|----------|------------------------------|--------------------|--------------------|
| RFID RC522 | 13.56MHz RFID/NFC reader via SPI. | [Source](https://github.com/miguelbalboa/rfid) | MFRC522 Library |
| Fingerprint (R503) | Optical fingerprint sensor. UART or USB. | [Source](https://github.com/adafruit/Adafruit-Fingerprint-Sensor-Library) | Adafruit Fingerprint |
| PN532 NFC/RFID | NFC reader/writer via I2C/SPI/HSU. | [Source](https://github.com/adafruit/Adafruit-PN532) | Adafruit PN532 |


### ⏱️ Measurement & Timing (4)

| Sensor | Description | GitHub Source | Library |
|----------|------------------------------|--------------------|--------------------|
| ACS712 | AC/DC current sensor (5A/20A/30A). Analog output. | [Source](https://github.com/RTW88/ACS712-Arduino-Library) | ACS712 Current Sensor |
| ZMPT101B | AC mains voltage sensor module. Analog output. | [Source](https://github.com/limagiran/zmpt101b-arduino) | ZMPT101B Library |
| DS3231 RTC | High-precision I2C real-time clock with battery backup. | [Source](https://github.com/adafruit/RTClib) | RTClib by Adafruit |
| HX711 Load Cell | 24-bit ADC for weighing scale load cells. | [Source](https://github.com/bogde/HX711) | HX711 Library by bogde |


### 🌡️ Pressure & Weather (2)

| Sensor | Description | GitHub Source | Library |
|----------|------------------------------|--------------------|--------------------|
| LPS22HB | Piezoresistive pressure (260-1260 hPa). I2C/SPI. | [Source](https://github.com/pololu/lps22hb-arduino) | Pololu LPS22HB |
| MS5611 | High-res barometric altimeter (10cm resolution). | [Source](https://github.com/millerlp/MS5611) | MS5611 Arduino |


### ❤️ Health & Biomedical (3)

| Sensor | Description | GitHub Source | Library |
|----------|------------------------------|--------------------|--------------------|
| MAX30102 | Pulse oximeter and heart rate monitor (SpO2, BPM). I2C. | [Source](https://github.com/sparkfun/SparkFun_MAX3010x_Sensor_Library) | SparkFun MAX3010x |
| MAX30101 | 3-wavelength PPG for SpO2, HR, and respiration rate. | [Source](https://github.com/tutrp/Max30101-Arduino-Library) | MAX30101 Arduino |
| AD8232 | ECG/heart electrical signal single-lead output. | [Source](https://github.com/sparkfun/AD8232_Heart_Rate_Monitor) | SparkFun AD8232 |


### 📺 Displays (4)

| Display | Description | GitHub Source | Library |
|----------|------------------------------|--------------------|--------------------|
| 16x2 LCD (HD44780) | 16×2 characters. Parallel (6 pins) or I2C module (2 pins). | [Source](https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library) | LiquidCrystal or LiquidCrystal_I2C |
| OLED 0.96" SSD1306 | 128×64 pixel OLED display via I2C. | [Source](https://github.com/adafruit/Adafruit_SSD1306) | Adafruit SSD1306 + GFX |
| Nokia 5110 LCD | 84×48 pixel monochrome LCD via SPI. | [Source](https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library) | Adafruit PCD8544 Nokia 5110 |
| MAX7219 LED Matrix | 8×8 LED dot matrix. Daisy-chainable via SPI. | [Source](https://github.com/markruys/arduino-Max72xxPanel) | Adafruit MAX7219 or MD_Parola |


### 🔊 Sound & Audio (4)

| Module | Description | GitHub Source | Library |
|----------|------------------------------|--------------------|--------------------|
| Sound Sensor (KY-037) | Analog/digital sound detection module. | [Source](https://github.com/arduino/ArduinoCore-avr) | Built-in (analogRead/digitalRead) — Arduino Core |
| DFPlayer Mini MP3 | MP3/WAV player from micro SD card via UART. | [Source](https://github.com/DFRobot/DFRobotDFPlayerMini) | DFRobotDFPlayerMini |
| MAX98357A I2S | 3W mono Class D amplifier via I2S. | [Source](https://github.com/adafruit/Adafruit_MAX98357) | Adafruit MAX98357A |
| INMP441 | MEMS omnidirectional mic via I2S. High quality. | [Source](https://github.com/espressif/arduino-esp32) | I2S (ESP32 built-in) — ESP32 Arduino Core |


### 📡 Communication & Wireless (9)

| Module | Description | GitHub Source | Library |
|----------|------------------------------|--------------------|--------------------|
| HC-05/HC-06 Bluetooth | Bluetooth 2.0 serial module (9600 baud). | [Source](https://github.com/RoboCraft/Bluetooth_HC05) | SoftwareSerial + AT commands |
| nRF24L01 | 2.4GHz wireless. 1km+ range. SPI. | [Source](https://github.com/nRF24/RF24) | RF24 Library |
| ESP8266 (WiFi) | WiFi module. Can run standalone or as Uno modem. | [Source](https://github.com/ekstrand/ESP8266wifi) | ESP8266WiFi |
| LoRa SX1278/SX1276 | Long-range low-power wireless (433MHz/915MHz). SPI. | [Source](https://github.com/sandeepmistry/arduino-LoRa) | arduino-LoRa (Sandeep Mistry) |
| IR Receiver TSOP382 | 38kHz IR receiver to decode remotes. Digital output. | [Source](https://github.com/Arduino-IRremote/Arduino-IRremote) | Arduino-IRremote |
| NEO-6M / NEO-M8N GPS | Ublox GPS via UART. Location, speed, time. | [Source](https://github.com/mikalhart/TinyGPSPlus) | TinyGPSPlus |
| SIM800L GSM/GPRS | Quad-band cellular for SMS, calls, GPRS. 3.7-4.2V. | [Source](https://github.com/vshymanskyy/TinyGSM) | TinyGSM |
| ESP32 (Co-processor) | Dual-core WiFi/BT. Can run standalone or as modem. | [Source](https://github.com/nkolban/ESP32_BLE_Arduino) | ESP32 Arduino Core |
| MCP2515 CAN Bus | Automotive/industrial CAN bus via SPI. | [Source](https://github.com/coryjfowler/MCP_CAN_lib) | MCP_CAN_lib |


### ⚡ Actuators (9)

| Actuator | Description | GitHub Source | Library |
|----------|------------------------------|--------------------|--------------------|
| 5V Relay Module | Electromechanical relay for AC/DC loads. Active-low. | [Source](https://github.com/arduino/ArduinoCore-avr) | Built-in (digitalWrite) — Arduino Core |
| SG90 Micro Servo | 9g micro servo (180°). 4.8V. | [Source](https://github.com/arduino-libraries/Servo) | Servo.h — Arduino Core |
| MG996R Metal Servo | High torque (10kg-cm) metal gear servo. | [Source](https://github.com/arduino-libraries/Servo) | Servo.h — Arduino Core |
| L298N Motor Driver | Dual H-bridge for 2 DC motors or 1 stepper. | [Source](https://github.com/AndreaLombardo/L298N) | L298N Library |
| L293D Motor Shield | Shield for 2 steppers or 4 DC motors. | [Source](https://github.com/adafruit/Adafruit_Motor_Shield_V2_Library) | Adafruit Motor Shield V2 |
| Solid State Relay (SSR) | Silent AC switching (24-380VAC) via opto-isolation. | [Source](https://github.com/arduino/ArduinoCore-avr) | Built-in (digitalWrite) — Arduino Core |
| 28BYJ-48 Stepper | 5V stepper with ULN2003 driver. | [Source](https://github.com/arduino-libraries/Stepper) | Stepper — Arduino Core |
| A4988 / DRV8825 Driver | Microstepping drivers for NEMA 17/23. 2-pin control. | [Source](https://github.com/laurb9/StepperDriver) | A4988 Stepper Driver |
| Vibration Motor (DC) | Small coin/disc motor via PWM/Transistor. | [Source](https://github.com/arduino/ArduinoCore-avr) | Built-in (analogWrite) — Arduino Core |


### 📟 Compatible Boards (7)

| Board | Spec | GitHub Core | Notes |
|----------|------------------------------|--------------------|--------------------|
| ESP32 DevKit V1 | Xtensa LX6 dual core, WiFi, BLE. 520KB SRAM. | [Source](https://github.com/espressif/arduino-esp32) | Cheap IoT powerhouse |
| Wemos D1 Mini | ESP8266. Tiny form factor. WiFi. 4MB Flash. | [Source](https://github.com/esp8266/Arduino) | Small sensor nodes |
| STM32 Blue Pill | ARM Cortex-M3 72MHz. 64KB SRAM, 128KB Flash. | [Source](https://github.com/stm32duino/Arduino_Core_STM32) | Faster than Uno, cheap |
| Seeeduino XIAO | SAMD21 Cortex-M0+. Thumb-sized. USB-C. | [Source](https://github.com/Seeed-Studio/ArduinoCore-samd) | Wearables |
| Arduino Mega 2560 | ATmega2560. 256KB Flash. 54 I/O. | [Source](https://github.com/arduino/ArduinoCore-avr) | Many pins for complex projects |
| Digispark ATtiny85 | ATtiny85. 6KB Flash, 6 pins. USB bitbang. | [Source](https://github.com/digistump/DigistumpArduino) | Tiny standalone |
| Teensy 4.1 | ARM Cortex-M7 600MHz. Huge memory/speed. | [Source](https://github.com/PaulStoffregen/cores) | High performance |


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





