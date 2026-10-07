/*
 * Arduino Home Environment Dashboard
 * ====================================
 * ALL-IN-ONE home monitoring system combining:
 *   - Temperature/Humidity (DHT11)
 *   - Air Quality (MQ-135)
 *   - Light Level (LDR)
 *   - Ultrasonic Distance (HC-SR04 for water level)
 *   - Motion Detection (PIR)
 *   - Soil Moisture (capacitive sensor)
 *
 * All data displayed on LCD with serial logging.
 * LEDs indicate status per sensor type.
 *
 * Hardware:
 *   - DHT11 Temperature/Humidity Sensor
 *   - MQ-135 Air Quality Sensor
 *   - LDR + 10k Resistor (Light Level)
 *   - HC-SR04 Ultrasonic Distance Sensor
 *   - PIR Motion Sensor (HC-SR501)
 *   - Soil Moisture Sensor (capacitive)
 *   - 16x2 LCD (I2C module)
 *   - Push Button (for cycling through sensor views)
 *   - 3x LEDs for status indication
 *
 * Wiring:
 *
 *   I2C LCD:
 *     VCC  -> 5V
 *     GND  -> GND
 *     SDA  -> A4
 *     SCL  -> A5
 *
 *   DHT11 Sensor:
 *     VCC  -> 5V
 *     GND  -> GND
 *     DATA -> Pin 2
 *
 *   MQ-135 Air Quality:
 *     VCC  -> 5V
 *     GND  -> GND
 *     AOUT -> A0
 *
 *   LDR (voltage divider):
 *     LDR -> 5V
 *     LDR -> A1 --- 10k Resistor -> GND
 *
 *   HC-SR04 Ultrasonic:
 *     VCC  -> 5V
 *     GND  -> GND
 *     TRIG -> Pin 5
 *     ECHO -> Pin 6
 *
 *   PIR Motion Sensor:
 *     VCC  -> 5V
 *     GND  -> GND
 *     OUT  -> Pin 3
 *
 *   Soil Moisture:
 *     VCC  -> 5V
 *     GND  -> GND
 *     AOUT -> A2
 *
 *   Status LED (Pin 13):
 *     Pin 13 -> 220ohm Resistor -> LED Anode
 *     LED Cathode -> GND
 *
 *   Button (Pin 7):
 *     Pin 7 -> Button -> GND  (INPUT_PULLUP)
 *
 * Usage:
 *   1. Connect all sensors as described above.
 *   2. Open Serial Monitor to see all sensor data.
 *   3. Press button to cycle through LCD views:
 *      View 0: Temperature + Humidity
 *      View 1: Air Quality + Light Level
 *      View 2: Water Level + Soil Moisture  
 *      View 3: Motion Detection + System Uptime
 *   4. Calibrate thresholds in the CONFIGURATION section.
 */

#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// === SENSOR PINS ===
const int SENSOR_DHT = 2;      // DHT11 data pin
const int SENSOR_MQ135 = A0;   // MQ-135 analog
const int SENSOR_LDR = A1;     // LDR analog
const int SENSOR_MOISTURE = A2; // Soil moisture analog
const int ULTRASONIC_TRIG = 5; // HC-SR04 trigger
const int ULTRASONIC_ECHO = 6; // HC-SR04 echo
const int SENSOR_PIR = 3;      // PIR motion sensor
const int LCD_ADDRESS = 0x27;  // I2C LCD address (try 0x3F if it doesn't work)
const int BUTTON_PIN = 7;      // View cycle button
const int STATUS_LED = 13;     // System status LED

// === CONFIGURATION ===
DHT dht(SENSOR_DHT, DHT11);
LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);

const int NUM_VIEWS = 4;
int currentView = 0;
unsigned long lastReading = 0;
unsigned long systemStart = 0;
bool motionDetected = false;

// Sensor read interval (2s for DHT11)
const unsigned long READ_INTERVAL = 2000;

// Thresholds
const int AIR_QUALITY_GOOD = 150;
const int AIR_QUALITY_MODERATE = 300;
const int LIGHT_DARK_THRESHOLD = 500;
const int SOIL_MOISTURE_DRY = 450;

// View names, for reference (LCD content is built in updateLCD()):
//   0 = Temperature + Humidity
//   1 = Air Quality + Light Level
//   2 = Water Level + Soil Moisture
//   3 = Motion + System Uptime

void setup() {
  Serial.begin(9600);
  systemStart = millis();
  
  // Initialize pins
  pinMode(ULTRASONIC_TRIG, OUTPUT);
  pinMode(ULTRASONIC_ECHO, INPUT);
  pinMode(SENSOR_PIR, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(STATUS_LED, OUTPUT);
  
  // Initialize sensors
  dht.begin();
  lcd.init();
  lcd.backlight();
  
  displaySplashScreen();
  
  Serial.println("=== Arduino Home Environment Dashboard ===");
  Serial.println("Sensors: DHT11, MQ-135, LDR, HC-SR04, PIR, Soil Moisture");
  Serial.println("Press button to cycle through views.");
}

void loop() {
  // Button press cycles view
  static bool buttonWas = false;
  bool buttonIs = digitalRead(BUTTON_PIN) == LOW;
  if (buttonIs && !buttonWas) {
    currentView = (currentView + 1) % NUM_VIEWS;
    lcd.clear();
  }
  buttonWas = buttonIs;
  
  // Read sensors at intervals
  unsigned long now = millis();
  if (now - lastReading >= READ_INTERVAL) {
    lastReading = now;
    readAllSensors();
  }
  
  // Blink status LED every 2 seconds (system alive indicator)
  if ((now / 1000) % 4 == 0) {
    digitalWrite(STATUS_LED, HIGH);
  } else {
    digitalWrite(STATUS_LED, LOW);
  }
  
  delay(100);
}

void readAllSensors() {
  // DHT11 - Temperature and Humidity
  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();
  if (isnan(temp)) temp = -1;
  if (isnan(humidity)) humidity = -1;
  
  // MQ-135 - Air Quality (lower = better)
  int airQuality = 0;
  for (int i = 0; i < 5; i++) {
    airQuality += analogRead(SENSOR_MQ135);
    delay(10);
  }
  airQuality /= 5;
  
  // LDR - Light Level
  int lightLevel = analogRead(SENSOR_LDR);
  
  // Soil Moisture
  int soilMoisture = 0;
  for (int i = 0; i < 5; i++) {
    soilMoisture += analogRead(SENSOR_MOISTURE);
    delay(10);
  }
  soilMoisture /= 5;
  
  // Ultrasonic - Distance/Water Level
  float distance = measureDistance();
  
  // PIR - Motion Detection
  bool currentMotion = digitalRead(SENSOR_PIR) == HIGH;
  if (currentMotion) motionDetected = true;
  
  // Update Serial logging
  logToSerial(temp, humidity, airQuality, lightLevel, 
              distance, currentMotion, soilMoisture);
  
  // Update LCD for current view
  // motionDetected is the latched flag (stays set until view 3 shows it), so the
  // display does not miss a brief trigger between 2-second sensor reads.
  updateLCD(currentView, temp, humidity, airQuality, lightLevel, 
            distance, motionDetected, soilMoisture);
}

void logToSerial(float temp, float humidity, int airQuality, int lightLevel, 
                 float distance, bool motion, int soilMoisture) {
  Serial.println("--- Sensor Readings ---");
  Serial.print("Temperature: "); Serial.print(temp, 1); Serial.println(" C");
  Serial.print("Humidity: "); Serial.print(humidity, 1); Serial.println(" %");
  Serial.print("Air Quality: "); Serial.println(airQuality);
  Serial.print("Light Level: "); Serial.println(lightLevel);
  Serial.print("Distance: "); Serial.print(distance, 1); Serial.println(" cm");
  Serial.print("Motion: "); Serial.println(motion ? "DETECTED" : "None");
  Serial.print("Soil Moisture: "); Serial.println(soilMoisture);
  Serial.print("Uptime: "); Serial.print(formatUptime()); Serial.println();
  Serial.println("----------------------");
}

void updateLCD(int view, float temp, float humidity, int airQuality, int lightLevel, 
               float distance, bool motion, int soilMoisture) {
  lcd.setCursor(0, 0);
  
  switch (view) {
    case 0:  // Temperature + Humidity
      lcd.print("Temp: ");
      lcd.print(temp, 1);
      lcd.print("C ");
      lcd.setCursor(0, 1);
      lcd.print("Humd: ");
      lcd.print(humidity, 0);
      lcd.print("%  ");
      if (humidity < 0) {
        lcd.clear();
        lcd.print("DHT Sensor Error");
      }
      break;
      
    case 1:  // Air Quality + Light Level
      lcd.print("Air: ");
      lcd.print(airQuality);
      lcd.print("     ");
      lcd.setCursor(0, 1);
      lcd.print(lightLevel < LIGHT_DARK_THRESHOLD ? "Dark    " : "Bright  ");
      lcd.print(lightLevel);
      break;
      
    case 2:  // Water Level + Soil Moisture
      lcd.print("Dist: ");
      lcd.print(distance, 0);
      lcd.print("cm  ");
      lcd.setCursor(0, 1);
      lcd.print("Soil: ");
      lcd.print(soilMoisture);
      lcd.print(soilMoisture > SOIL_MOISTURE_DRY ? " Dry" : " Wet");
      break;
      
    case 3:  // Motion + System Uptime
      lcd.print("Motion:");
      lcd.print(motion ? " YES " : " NO  ");
      lcd.setCursor(0, 1);
      lcd.print("Up: ");
      lcd.print(formatUptime());
      if (motionDetected) {
        motionDetected = false;  // Reset after display
      }
      break;
  }
}

float measureDistance() {
  digitalWrite(ULTRASONIC_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASONIC_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_TRIG, LOW);
  
  long duration = pulseIn(ULTRASONIC_ECHO, HIGH, 30000);
  if (duration == 0) return -1;  // Timeout
  
  float distance = duration * 0.0343 / 2.0;
  return distance;
}

const char* formatUptime() {
  static char buffer[20];
  unsigned long seconds = (millis() - systemStart) / 1000;
  unsigned long minutes = seconds / 60;
  unsigned long hours = minutes / 60;
  unsigned long days = hours / 24;
  
  // %lu, not %ld: these are unsigned long. On AVR both are 32-bit so the
  // compiler stays quiet, but %ld prints garbage once uptime passes
  // LONG_MAX (~24.8 days) — an unattended dashboard will get there.
  if (days > 0) {
    snprintf(buffer, sizeof(buffer), "%lud %luh %lum", days, hours % 24, minutes % 60);
  } else {
    snprintf(buffer, sizeof(buffer), "%luh %lum %lus", hours, minutes % 60, seconds % 60);
  }
  return buffer;
}

void displaySplashScreen() {
  lcd.setCursor(0, 0);
  lcd.print("Home Dashboard");
  lcd.setCursor(0, 1);
  lcd.print("v1.0 Initializing");
  delay(2000);
}
