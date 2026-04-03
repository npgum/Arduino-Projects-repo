/*
 * Home Thermostat Display
 * =======================
 * Reads temperature and humidity, displays on LCD,
 * and triggers visual/audible alerts when conditions exceed limits.
 *
 * Hardware:
 *   - DHT11 or DHT22 Temperature/Humidity Sensor
 *   - 16x2 LCD (I2C module recommended)
 *   - Blue LED (comfortable temp)
 *   - Red LED (too hot)
 *   - Yellow LED (too humid or too cold)
 *   - Buzzer (optional, for audible alert)
 *
 * Wiring:
 *   DHT11 Sensor:
 *     VCC  -> 5V (or 3.3V for DHT22)
 *     GND  -> GND
 *     DATA -> Pin 2
 *
 *   I2C LCD:
 *     VCC  -> 5V
 *     GND  -> GND
 *     SDA  -> A4
 *     SCL  -> A5
 *
 *   LEDs (each with 220ohm resistor):
 *     Blue LED  -> Pin 9 -> GND    (comfortable)
 *     Red LED   -> Pin 10 -> GND   (too hot)
 *     Yellow LED -> Pin 11 -> GND  (too cold/humid)
 *
 *   Buzzer:
 *     +ve  -> Pin 6
 *     -ve  -> GND
 *
 * Note: Uses LiquidCrystal_I2C library. Install via
 *   Arduino IDE: Sketch -> Include Library -> Manage Libraries
 *   Search for "LiquidCrystal I2C" by Frank de Brabander
 */

#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2
#define DHTTYPE DHT11  // Change to DHT22 if using DHT22

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C address 0x27 or 0x3F

const int ledBlue = 9;
const int ledRed = 10;
const int ledYellow = 11;
const int buzzerPin = 6;

// Alert thresholds (adjust for your preference)
const float TEMP_COMFORT_MAX = 28.0;  // Above this = hot
const float TEMP_COMFORT_MIN = 20.0;  // Below this = cold
const float HUMID_COMFORT_MAX = 70.0; // Above this = too humid
const float HUMID_COMFORT_MIN = 30.0; // Below this = too dry

// Sensor read interval (DHT needs 2s between reads)
const unsigned long READ_INTERVAL = 2000;
unsigned long lastRead = 0;

void setup() {
  Serial.begin(9600);
  
  dht.begin();
  lcd.init();
  lcd.backlight();
  
  pinMode(ledBlue, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  lcd.setCursor(0, 0);
  lcd.print("Thermostat v1.0");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(2000);
  
  Serial.println("=== Home Thermostat Display ===");
  Serial.print("Temp range: ");
  Serial.print(TEMP_COMFORT_MIN);
  Serial.print("C - ");
  Serial.print(TEMP_COMFORT_MAX);
  Serial.println("C");
  Serial.print("Humidity range: ");
  Serial.print(HUMID_COMFORT_MIN);
  Serial.print("% - ");
  Serial.print(HUMID_COMFORT_MAX);
  Serial.println("%");
}

void loop() {
  unsigned long now = millis();
  
  if (now - lastRead >= READ_INTERVAL) {
    lastRead = now;
    
    float temp = dht.readTemperature();
    float humidity = dht.readHumidity();
    
    if (isnan(temp) || isnan(humidity)) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Sensor Error!");
      Serial.println("Failed to read from DHT sensor!");
      allLEDsOff();
      return;
    }
    
    // Update LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("T:");
    lcd.print(temp, 1);
    lcd.print("C  H:");
    lcd.print(humidity, 0);
    lcd.print("%");
    
    // Check conditions and update LEDs
    checkConditions(temp, humidity);
    
    // Serial logging
    Serial.print("Temp: ");
    Serial.print(temp, 1);
    Serial.print("C | Humidity: ");
    Serial.print(humidity, 1);
    Serial.print("% | Status: ");
    Serial.println(getStatusText(temp, humidity));
  }
}

void checkConditions(float temp, float humidity) {
  allLEDsOff();
  noTone(buzzerPin);
  
  if (temp > TEMP_COMFORT_MAX) {
    // Too hot
    digitalWrite(ledRed, HIGH);
    tone(buzzerPin, 1000, 200);  // Beep warning
  } else if (temp < TEMP_COMFORT_MIN) {
    // Too cold
    digitalWrite(ledYellow, HIGH);
  } else if (humidity > HUMID_COMFORT_MAX || humidity < HUMID_COMFORT_MIN) {
    // Humidity out of range
    digitalWrite(ledYellow, HIGH);
  } else {
    // Comfortable!
    digitalWrite(ledBlue, HIGH);
  }
}

void allLEDsOff() {
  digitalWrite(ledBlue, LOW);
  digitalWrite(ledRed, LOW);
  digitalWrite(ledYellow, LOW);
}

const char* getStatusText(float temp, float humidity) {
  if (temp > TEMP_COMFORT_MAX) return "TOO HOT";
  if (temp < TEMP_COMFORT_MIN) return "TOO COLD";
  if (humidity > HUMID_COMFORT_MAX) return "TOO HUMID";
  if (humidity < HUMID_COMFORT_MIN) return "TOO DRY";
  return "COMFORTABLE";
}
