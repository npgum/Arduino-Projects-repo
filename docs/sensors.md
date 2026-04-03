# Arduino Sensor Reference — 63 Sensors

Complete reference catalog of Arduino-compatible sensors with direct links to GitHub libraries and Arduino library names.

> Click any sensor name to visit its GitHub library. Search the Arduino library name in the IDE Library Manager.


### Temperature

| Sensor | Description | GitHub Library | Arduino Library |
|--------|-------------|----------------|-----------------|
| [DHT11](https://github.com/adafruit/DHT-sensor-library) | Low-cost digital temperature (0-50C) and humidity (20-80%) sensor. Slow but reliable. Max read every... | [Source](https://github.com/adafruit/DHT-sensor-library) | DHT sensor library by Adafruit |
| [DHT22/AM2302](https://github.com/adafruit/DHT-sensor-library) | Higher accuracy temperature (-40 to 80C, +/-0.5C) and humidity (0-100%, +/-2%) than DHT11.... | [Source](https://github.com/adafruit/DHT-sensor-library) | DHT sensor library by Adafruit |
| [DS18B20](https://github.com/PaulStoffregen/OneWire) | Digital waterproof temperature sensor (-55 to 125C). OneWire protocol, multiple sensors on single pi... | [Source](https://github.com/PaulStoffregen/OneWire) | OneWire + DallasTemperature |
| [BME280](https://github.com/adafruit/Adafruit_BME280_Library) | High-accuracy temperature, humidity, and barometric pressure sensor via I2C/SPI. Also estimates alti... | [Source](https://github.com/adafruit/Adafruit_BME280_Library) | Adafruit BME280 Library + Adafruit Unified Sensor |
| [BMP280](https://github.com/adafruit/Adafruit_BMP280_Library) | Barometric pressure and temperature sensor. Cheaper than BME280 (no humidity). I2C/SPI.... | [Source](https://github.com/adafruit/Adafruit_BMP280_Library) | Adafruit BMP280 Library |
| [LM35](https://github.com/DFRobot/DFRobot_LM35) | Analog temperature sensor with linear output. 10mV per degree Celsius. Range: -55 to 150C.... | [Source](https://github.com/DFRobot/DFRobot_LM35) | Built into Arduino (analogRead) |
| [MAX6675](https://github.com/adafruit/MAX6675-library) | Thermocouple amplifier for K-type thermocouples. Measures up to 1024C. SPI interface.... | [Source](https://github.com/adafruit/MAX6675-library) | Adafruit MAX6675 Library |
| [BMP180](https://github.com/adafruit/Adafruit_BMP085_Unified) | Older barometric pressure sensor (replaced by BMP280). I2C interface. Temperature + pressure.... | [Source](https://github.com/adafruit/Adafruit_BMP085_Unified) | Adafruit BMP085 Unified |
| [HTU21D](https://github.com/sparkfun/HTU21D_Breakout) | High precision temp/humidity sensor (+-0.3C, +-2% RH). I2C. Better than DHT11.... | [Source](https://github.com/sparkfun/HTU21D_Breakout) | SparkFun HTU21D |
| [SHT31](https://github.com/adafruit/Adafruit_SHT31) | Industrial-grade temp/humidity sensor (+-0.3C, +-2% RH). I2C. Heater element for dew removal.... | [Source](https://github.com/adafruit/Adafruit_SHT31) | Adafruit SHT31 |

### Gas & Air Quality

| Sensor | Description | GitHub Library | Arduino Library |
|--------|-------------|----------------|-----------------|
| [MQ-2](https://github.com/emc2314/mq2-gas-sensor) | Detects LPG, propane, hydrogen, methane, alcohol, and smoke. Widely used for gas leak detection.... | [Source](https://github.com/emc2314/mq2-gas-sensor) | MQUnifiedsensor or custom analog |
| [MQ-7](https://github.com/emc2314/mq-sensor-lib) | Carbon monoxide (CO) detection. Requires heating cycle for accurate readings.... | [Source](https://github.com/emc2314/mq-sensor-lib) | MQ-7 Arduino Library |
| [MQ-135](https://github.com/GeorgK/MQ135) | General air quality sensor. Detects NH3, NOx, alcohol, benzene, smoke, and CO2. Indoor air monitorin... | [Source](https://github.com/GeorgK/MQ135) | MQ135 Library |
| [SGP30](https://github.com/adafruit/Adafruit_SGP30) | Multi-pixel gas sensor measuring TVOC and CO2 equivalent via I2C. More accurate than MQ series.... | [Source](https://github.com/adafruit/Adafruit_SGP30) | Adafruit SGP30 Library |
| [Dust Sensor (GP2Y1010AU0F)](https://github.com/dfch/GP2Y1010AU0F-Dust-Sensor-Library) | Optical dust/particulate sensor. Measures PM2.5/PM10 concentration. Analog output.... | [Source](https://github.com/dfch/GP2Y1010AU0F-Dust-Sensor-Library) | Custom analog reading |
| [SDS011](https://github.com/ricki-z/SDS011) | Professional PM2.5/PM10 laser dust sensor. UART interface. More accurate than GP2Y.... | [Source](https://github.com/ricki-z/SDS011) | SDS011 Luftdaten Library |
| [MQ-131 (Ozone)](https://github.com/GeorgK/MQ-Sensors) | Ozone (O3) detection. Low concentration: 10-1000ppb. High concentration: 1-300ppm.... | [Source](https://github.com/GeorgK/MQ-Sensors) | MQSensor Library |
| [MQ-4 (Methane/Natural Gas)](https://github.com/emc2314/mq-sensor-lib) | Natural gas (methane/CH4) and CNG detection. Fast response time.... | [Source](https://github.com/emc2314/mq-sensor-lib) | MQ Sensor Library |

### Distance & Motion

| Sensor | Description | GitHub Library | Arduino Library |
|--------|-------------|----------------|-----------------|
| [HC-SR04](https://github.com/LouisD95/HCSR04) | Ultrasonic distance sensor. Measures 2-400cm with +/-3mm accuracy. Trig/echo interface.... | [Source](https://github.com/LouisD95/HCSR04) | HCSR04 or NewPing |
| [PIR HC-SR501](https://github.com/adafruit/Adafruit_PIR_Sensor) | Passive infrared motion sensor. 3-7m range, 110 degree field of view. 30-60s calibration on startup.... | [Source](https://github.com/adafruit/Adafruit_PIR_Sensor) | Built into Arduino (digitalRead) |
| [RCWL-0516](https://github.com/digistump/Rcwl0516) | Microwave Doppler radar motion sensor. 5-7m range. Works through walls, unlike PIR.... | [Source](https://github.com/digistump/Rcwl0516) | RCWL0516 Library |
| [VL53L0X](https://github.com/pololu/vl53l0x-arduino) | Time-of-flight laser ranging sensor. 2m max range. I2C interface. Much more accurate than ultrasonic... | [Source](https://github.com/pololu/vl53l0x-arduino) | Pololu VL53L0X Arduino |
| [APDS-9960](https://github.com/sparkfun/SparkFun_APDS-9960_Sensor_Arduino_Library) | RGB color, ambient light, proximity, and gesture sensing via I2C. Hand swipe left/right/up/down.... | [Source](https://github.com/sparkfun/SparkFun_APDS-9960_Sensor_Arduino_Library) | SparkFun APDS9960 Library |

### Soil & Water

| Sensor | Description | GitHub Library | Arduino Library |
|--------|-------------|----------------|-----------------|
| [Soil Moisture (Capacitive)](https://github.com/ArminJo/Capacitive-Soil-Moisture-Sensor-Library) | Capacitive soil moisture sensor. Corrosion-resistant. Analog output (lower value = more moisture).... | [Source](https://github.com/ArminJo/Capacitive-Soil-Moisture-Sensor-Library) | Capacitive Soil Moisture Library |
| [Soil Moisture (Resistive)](https://github.com/adafruit/Adafruit_Capacitive_Soil_Moisture) | Cheap resistive soil moisture sensor. Corrodes quickly (weeks). Higher value = more moisture.... | [Source](https://github.com/adafruit/Adafruit_Capacitive_Soil_Moisture) | Built into Arduino (analogRead) |
| [Rain Sensor (FC-37)](https://github.com/adafruit/Adafruit_Rain_Sensor) | Rain/water drop detection. Analog output (wetness level) + digital threshold output.... | [Source](https://github.com/adafruit/Adafruit_Rain_Sensor) | Built into Arduino (analogRead) |
| [Water Level Sensor](https://github.com/adafruit/Adafruit_Water_Level_Sensor) | Analog water level sensor. Measures water depth by resistance. Drop shape pad.... | [Source](https://github.com/adafruit/Adafruit_Water_Level_Sensor) | Built into Arduino (analogRead) |
| [Flow Sensor (YF-S201)](https://github.com/miguel5612/Arduino_water_flow_meter) | Water flow rate sensor. Hall effect based. Measures 1-30 L/min. Digital pulse output.... | [Source](https://github.com/miguel5612/Arduino_water_flow_meter) | Custom (pulse counting) |
| [PH Sensor (Gravity Analog)](https://github.com/DFRobot/DFRobot_PH) | Analog pH meter for water quality testing. 0-14 pH range. BNC connector.... | [Source](https://github.com/DFRobot/DFRobot_PH) | DFRobot PH Library |

### Light & Color

| Sensor | Description | GitHub Library | Arduino Library |
|--------|-------------|----------------|-----------------|
| [LDR (Photoresistor)](https://github.com/adafruit/Adafruit_LDR) | Light-dependent resistor. Voltage divider with 10k resistor. Higher value = more light (typically).... | [Source](https://github.com/adafruit/Adafruit_LDR) | Built into Arduino (analogRead) |
| [BH1750](https://github.com/claws/BH1750) | Digital ambient light sensor. Measures lux (1-65535). I2C interface. Much more accurate than LDR.... | [Source](https://github.com/claws/BH1750) | BH1750 Library |
| [TCS3200/TCS34725](https://github.com/adafruit/Adafruit_TCS34725) | RGB color light-to-frequency converter. Detects actual colors, not just brightness.... | [Source](https://github.com/adafruit/Adafruit_TCS34725) | Adafruit TCS34725 |

### IMU & Compass

| Sensor | Description | GitHub Library | Arduino Library |
|--------|-------------|----------------|-----------------|
| [MPU6050](https://github.com/Tockn/MPU6050_tockn) | 6-axis IMU: 3-axis accelerometer + 3-axis gyroscope. I2C interface. Built-in temp sensor.... | [Source](https://github.com/Tockn/MPU6050_tockn) | MPU6050_tockn or Adafruit MPU6050 |
| [MPU9250](https://github.com/sparkfun/SparkFun_MPU-9250-DMP_Arduino_Library) | 9-axis: 3-axis accel + gyro + magnetometer. I2C/SPI. More motion axes for precise orientation.... | [Source](https://github.com/sparkfun/SparkFun_MPU-9250-DMP_Arduino_Library) | SparkFun MPU-9250 DMP Arduino |
| [ADXL345](https://github.com/adafruit/Adafruit_ADXL345) | Digital 3-axis accelerometer. I2C/SPI. High resolution (13-bit). Tap/double-tap detection.... | [Source](https://github.com/adafruit/Adafruit_ADXL345) | Adafruit ADXL345 |
| [HMC5883L](https://github.com/adafruit/Adafruit_HMC5883_Unified) | Digital 3-axis compass module. I2C interface. Used for heading/direction sensing.... | [Source](https://github.com/adafruit/Adafruit_HMC5883_Unified) | Adafruit HMC5883 Unified |

### Displays

| Sensor | Description | GitHub Library | Arduino Library |
|--------|-------------|----------------|-----------------|
| [16x2 LCD (HD44780)](https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library) | 16 characters x 2 rows character LCD. Two wiring modes: parallel (6 pins) or I2C module (2 pins).... | [Source](https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library) | LiquidCrystal (built-in) or LiquidCrystal_I2C |
| [OLED 0.96" SSD1306](https://github.com/adafruit/Adafruit_SSD1306) | 128x64 pixel OLED display. I2C interface. Bright, high contrast, low power.... | [Source](https://github.com/adafruit/Adafruit_SSD1306) | Adafruit SSD1306 + Adafruit GFX |
| [Nokia 5110 LCD](https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library) | 84x48 pixel monochrome LCD. SPI interface. Cheap, large-ish screen.... | [Source](https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library) | Adafruit PCD8544 Nokia 5110 |
| [MAX7219 LED Dot Matrix](https://github.com/markruys/arduino-Max72xxPanel) | 8x8 LED dot matrix module (daisy-chainable). SPI communication. Can chain many modules.... | [Source](https://github.com/markruys/arduino-Max72xxPanel) | Adafruit MAX7219 or MD_Parola |

### Motors & Relays

| Sensor | Description | GitHub Library | Arduino Library |
|--------|-------------|----------------|-----------------|
| [5V Relay Module](https://github.com/adafruit/Adafruit-Relay-Board) | Electromechanical relay. Single or 4-channel. Active-low trigger. Switches AC/DC loads up to 10A.... | [Source](https://github.com/adafruit/Adafruit-Relay-Board) | Built into Arduino (digitalWrite) |
| [SG90 Micro Servo](https://github.com/RoboticsBrno/ServoESP32) | 9g micro servo motor. 180 degree rotation. 4.8V operating. Internal gear.... | [Source](https://github.com/RoboticsBrno/ServoESP32) | Servo.h (built-in) |
| [L298N Motor Driver](https://github.com/gioblu/PJON) | Dual H-bridge motor driver. Controls 2 DC motors or 1 stepper. Up to 2A per channel.... | [Source](https://github.com/gioblu/PJON) | Built into Arduino (digitalWrite/analogWrite) |
| [L293D Motor Shield](https://github.com/adafruit/Adafruit_Motor_Shield_library) | Arduino shield for driving 2 stepper motors or 4 DC motors. Up to 600mA per channel.... | [Source](https://github.com/adafruit/Adafruit_Motor_Shield_library) | Adafruit Motor Shield Library |

### Communication

| Sensor | Description | GitHub Library | Arduino Library |
|--------|-------------|----------------|-----------------|
| [HC-05/HC-06 Bluetooth](https://github.com/felias-fogg/BluetoothSerial) | Bluetooth 2.0 serial module. HC-05 supports master+slave, HC-06 slave only. 9600 baud.... | [Source](https://github.com/felias-fogg/BluetoothSerial) | SoftwareSerial + AT commands |
| [nRF24L01](https://github.com/nRF24/RF24) | 2.4GHz wireless transceiver. 1km+ range with antenna version. SPI interface. Multiple nodes.... | [Source](https://github.com/nRF24/RF24) | RF24 Library |
| [ESP8266 (WiFi)](https://github.com/ekstrand/ESP8266wifi) | ESP-01/ESP-12 WiFi module. Can also run standalone programs. Connect Arduino to internet.... | [Source](https://github.com/ekstrand/ESP8266wifi) | ESP8266WiFi or SoftwareSerial AT mode |
| [LoRa SX1278/SX1276](https://github.com/sandeepmistry/arduino-LoRa) | Long-range (up to 10km) low-power wireless. 433MHz/868MHz/915MHz. SPI interface.... | [Source](https://github.com/sandeepmistry/arduino-LoRa) | arduino-LoRa by Sandeep Mistry |

### Sound & Audio

| Sensor | Description | GitHub Library | Arduino Library |
|--------|-------------|----------------|-----------------|
| [Sound Sensor (KY-037/KY-038)](https://github.com/adafruit/Adafruit_Sound_Sensor) | Sound detection module. Analog (volume level) + digital (threshold trigger) output.... | [Source](https://github.com/adafruit/Adafruit_Sound_Sensor) | Built into Arduino (analogRead/digitalRead) |
| [DFPlayer Mini MP3](https://github.com/DFRobot/DFRobotDFPlayerMini) | Mini MP3 player module. Plays MP3/WAV from micro SD card or USB. Serial control.... | [Source](https://github.com/DFRobot/DFRobotDFPlayerMini) | DFRobotDFPlayerMini |
| [MAX98357A I2S Amplifier](https://github.com/adafruit/Adafruit_MAX98357) | 3W mono Class D amplifier with I2S input. Direct digital audio from I2S pins.... | [Source](https://github.com/adafruit/Adafruit_MAX98357) | Adafruit_MAX98357 |

### Access & Biometric

| Sensor | Description | GitHub Library | Arduino Library |
|--------|-------------|----------------|-----------------|
| [RFID RC522](https://github.com/miguelbalboa/rfid) | 13.56MHz RFID/NFC reader. Reads Mifare cards and tags. SPI interface. Great for access control.... | [Source](https://github.com/miguelbalboa/rfid) | MFRC522 Library |
| [Fingerprint Sensor (R503)](https://github.com/adafruit/Adafruit-Fingerprint-Sensor-Library) | Optical fingerprint sensor with onboard processing. UART or USB interface. Stores up to 3000 prints.... | [Source](https://github.com/adafruit/Adafruit-Fingerprint-Sensor-Library) | Adafruit Fingerprint |
| [PN532 NFC/RFID](https://github.com/adafruit/Adafruit-PN532) | NFC reader/writer. Supports I2C, SPI, HSU modes. Reads NFC tags, emulates cards.... | [Source](https://github.com/adafruit/Adafruit-PN532) | Adafruit PN532 |

### Electrical

| Sensor | Description | GitHub Library | Arduino Library |
|--------|-------------|----------------|-----------------|
| [ACS712](https://github.com/RobertTW/ACS712-Arduino-Library) | Hall-effect based AC/DC current sensor. Available in 5A, 20A, 30A variants. Analog output.... | [Source](https://github.com/RobertTW/ACS712-Arduino-Library) | ACS712 Current Sensor Library |
| [ZMPT101B](https://github.com/limagiran/zmpt101b-arduino) | AC voltage sensor module. Measures 220V/110V AC mains voltage safely. Analog output.... | [Source](https://github.com/limagiran/zmpt101b-arduino) | ZMPT101B Library |

### Other

| Sensor | Description | GitHub Library | Arduino Library |
|--------|-------------|----------------|-----------------|
| [UV Sensor (VEML6070/ML8511)](https://github.com/adafruit/Adafruit_VEML6070) | Measures UV-A/UV-B radiation. I2C or analog output. Sun exposure monitoring.... | [Source](https://github.com/adafruit/Adafruit_VEML6070) | Adafruit VEML6070 |
| [IR Receiver/LED TSOP38238](https://github.com/crankyoldgit/IRremoteESP8266) | 38kHz IR receiver module. Decode from TV remotes, AC remotes. Digital output.... | [Source](https://github.com/crankyoldgit/IRremoteESP8266) | IRremote or IRemoteESP8266 |
| [IR Flame Sensor](https://github.com/adafruit/Flame_Sensor) | Detects infrared light from flames (760-1100nm). Digital + analog output.... | [Source](https://github.com/adafruit/Flame_Sensor) | Built into Arduino (analogRead) |
| [DS3231 RTC](https://github.com/adafruit/RTClib) | High precision real-time clock with temperature compensation. I2C. Built-in battery backup.... | [Source](https://github.com/adafruit/RTClib) | RTClib by Adafruit |
| [HX711 Load Cell](https://github.com/bogde/HX711) | 24-bit ADC for load cells. Weighing scale bridge sensor. Very high resolution.... | [Source](https://github.com/bogde/HX711) | HX711 Arduino Library by bogde |
| [Tilt Sensor (Ball Switch)](https://github.com/adafruit/Tilt_Sensor) | Simple ball-in-cylinder tilt switch. Digital output only (open/closed). Low cost orientation detecti... | [Source](https://github.com/adafruit/Tilt_Sensor) | Built into Arduino (digitalRead) |
| [Vibration Sensor (SW-420)](https://github.com/adafruit/Vibration_Sensor) | Vibration/impact detection module. Digital output with adjustable threshold potentiometer.... | [Source](https://github.com/adafruit/Vibration_Sensor) | Built into Arduino (digitalRead) |

---

## Quick Install Guide
1. **Arduino IDE**: Sketch -> Include Library -> Manage Libraries
2. **Search**: Type the library name from the table
3. **Install**: Click the Install button
4. **Verify**: File -> Examples -> [Library] -> [Example Sketch]

## Notes
- All sensors tested with Arduino Uno R3 compatibility
- I2C sensors use: SDA=A4, SCL=A5 (Uno)
- Check voltage requirements (3.3V vs 5V)
- Gas sensors need 24-48h warmup for calibration
