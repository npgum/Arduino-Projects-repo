/*
 * Water Level Monitor with Ultrasonic Sensor
 * ============================================
 * Measures water level in a tank/container using HC-SR04 ultrasonic sensor
 * mounted at the top facing down. Displays level percentage and volume
 * estimation. Alerts when water is low.
 *
 * Hardware:
 *   - HC-SR04 Ultrasonic Sensor (waterproof version recommended)
 *   - 16x2 LCD (I2C module)
 *   - Buzzer (low water alarm)
 *   - Red LED (critical level)
 *   - Yellow LED (low level)
 *   - Green LED (good level)
 *
 * Wiring:
 *   HC-SR04:
 *     VCC   -> 5V
 *     GND   -> GND
 *     TRIG  -> Pin 5
 *     ECHO  -> Pin 6
 *
 *   I2C LCD:
 *     VCC   -> 5V
 *     GND   -> GND
 *     SDA   -> A4
 *     SCL   -> A5
 *
 *   LED (with 220ohm resistors):
 *     Green  -> Pin 9 -> GND
 *     Yellow -> Pin 10 -> GND  
 *     Red    -> Pin 11 -> GND
 *
 *   Buzzer:
 *     +ve   -> Pin 8
 *     -ve   -> GND
 *
 * CONFIGURATION:
 *   Measure your tank dimensions and update these values:
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int trigPin = 5;
const int echoPin = 6;
const int buzzerPin = 8;
const int ledGreen = 9;
const int ledYellow = 10;
const int ledRed = 11;

LiquidCrystal_I2C lcd(0x27, 16, 2);

// === TANK CONFIGURATION ===
// Distance from sensor to tank bottom when FULL (cm)
const float SENSOR_TO_FULL = 10.0;
// Distance from sensor to tank bottom when EMPTY (cm)
const float SENSOR_TO_EMPTY = 80.0;
// Tank max capacity in liters (for volume estimation)
const float MAX_CAPACITY_L = 1000.0;

// Alert thresholds (percentage)
const int LEVEL_LOW = 25;      // Yellow LED at this %
const int LEVEL_CRITICAL = 10; // Red LED + buzzer at this %

const int CHECK_INTERVAL = 3000;
unsigned long lastCheck = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
  
  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(0, 0);
  lcd.print("Water Level v1.0");
  lcd.setCursor(0, 1);
  lcd.print("Calibrating...");
  delay(2000);
  
  Serial.println("=== Water Level Monitor ===");
  Serial.print("Max Capacity: ");
  Serial.print(MAX_CAPACITY_L, 0);
  Serial.println(" liters");
}

void loop() {
  unsigned long now = millis();
  
  if (now - lastCheck >= CHECK_INTERVAL) {
    lastCheck = now;
    
    float distance = measureDistance();
    
    if (distance == -1) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Sensor Error!");
      Serial.println("Error reading ultrasonic sensor");
      return;
    }
    
    // Calculate water level percentage
    // Higher distance = less water (sensor measures from top)
    float levelPercent = 100.0 - ((distance - SENSOR_TO_FULL) / (SENSOR_TO_EMPTY - SENSOR_TO_FULL) * 100.0);
    levelPercent = constrain(levelPercent, 0, 100);
    
    float currentVolume = (levelPercent / 100.0) * MAX_CAPACITY_L;
    
    // Update LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Water: ");
    lcd.print(levelPercent, 0);
    lcd.print("%");
    
    lcd.setCursor(0, 1);
    lcd.print(currentVolume, 0);
    lcd.print("L / ");
    lcd.print(MAX_CAPACITY_L, 0);
    lcd.print("L");
    
    // Alert logic
    noTone(buzzerPin);
    if (levelPercent <= LEVEL_CRITICAL) {
      setLED(ledRed);
      tone(buzzerPin, 1500, 500);  // Alarm beep
      Serial.println("!!! CRITICAL: Water level very low!");
    } else if (levelPercent <= LEVEL_LOW) {
      setLED(ledYellow);
      Serial.println("WARNING: Water level low.");
    } else {
      setLED(ledGreen);
    }
    
    // Serial logging
    Serial.print("Distance: ");
    Serial.print(distance, 1);
    Serial.print("cm | Level: ");
    Serial.print(levelPercent, 1);
    Serial.print("% | Volume: ");
    Serial.print(currentVolume, 1);
    Serial.println("L");
  }
}

float measureDistance() {
  // Send 10us pulse to trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure echo duration
  long duration = pulseIn(echoPin, HIGH, 30000);  // 30ms timeout
  if (duration == 0) return -1;  // Timeout
  
  // Speed of sound: 343 m/s = 0.0343 cm/us
  // Divide by 2 for round trip
  float distance = duration * 0.0343 / 2.0;
  return distance;
}

void setLED(int pin) {
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledRed, LOW);
  digitalWrite(pin, HIGH);
}
