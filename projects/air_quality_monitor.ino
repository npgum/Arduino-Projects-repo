/*
 * Air Quality Monitor with MQ-135
 * ================================
 * Measures air quality using MQ-135 gas sensor.
 * Monitors CO2, alcohol, benzene, smoke, and ammonia levels.
 * Provides LCD display and visual LED indicator system.
 *
 * Hardware:
 *   - MQ-135 Gas Sensor (with analog output)
 *   - 16x2 LCD (I2C module)
 *   - Green LED (good air)
 *   - Yellow LED (moderate)
 *   - Red LED (poor air)
 *
 * Wiring:
 *   MQ-135 Sensor:
 *     VCC  -> 5V
 *     GND  -> GND
 *     AOUT -> A0
 *     DOUT -> (optional, not used)
 *
 *   I2C LCD:
 *     VCC  -> 5V
 *     GND  -> GND
 *     SDA  -> A4
 *     SCL  -> A5
 *
 *   LEDs (with 220ohm resistors):
 *     Green  -> Pin 9 -> GND
 *     Yellow -> Pin 10 -> GND
 *     Red    -> Pin 11 -> GND
 *
 * NOTE: Air quality values are relative (PPM approximation).
 * The MQ-135 requires 24-hour warmup for accurate calibration.
 * Thresholds below are approximate - calibrate for your environment.
 *
 * Usage:
 *   1. Power on and let sensor warm up for at least 24 hours
 *      (first reading will be inaccurate).
 *   2. Check Serial Monitor for baseline reading in clean air.
 *   3. Adjust THRESHOLD_* values based on your environment.
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int mq135Pin = A0;
const int ledGreen = 9;
const int ledYellow = 10;
const int ledRed = 11;

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Air quality thresholds (analog reading values)
// Lower value = better air quality
const int THRESHOLD_GOOD = 150;
const int THRESHOLD_MODERATE = 300;

const int CHECK_INTERVAL = 2000;
unsigned long lastCheck = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
  
  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(0, 0);
  lcd.print("Air Quality v1.0");
  lcd.setCursor(0, 1);
  lcd.print("Warming up 24h..");
  
  Serial.println("=== Air Quality Monitor ===");
  Serial.println("WARNING: MQ-135 needs 24h warmup for accurate readings.");
  Serial.println("Readings before warmup are estimates only.");
  delay(3000);
}

void loop() {
  unsigned long now = millis();
  
  if (now - lastCheck >= CHECK_INTERVAL) {
    lastCheck = now;
    
    int airQuality = readAirQuality();
    const char* status;
    
    // Average 10 readings for stability
    Serial.print("Air Quality Reading: ");
    Serial.print(airQuality);
    Serial.println(" (lower = better)");
    
    if (airQuality < THRESHOLD_GOOD) {
      status = "GOOD";
      setLED(ledGreen);
    } else if (airQuality < THRESHOLD_MODERATE) {
      status = "MODERATE";
      setLED(ledYellow);
    } else {
      status = "POOR - Ventilate!";
      setLED(ledRed);
    }
    
    // Update LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Air Quality:");
    lcd.setCursor(0, 1);
    lcd.print(status);
    
    Serial.print("Status: ");
    Serial.println(status);
  }
}

int readAirQuality() {
  int sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += analogRead(mq135Pin);
    delay(50);
  }
  return sum / 10;
}

void setLED(int pin) {
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledRed, LOW);
  digitalWrite(pin, HIGH);
}
