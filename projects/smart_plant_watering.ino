/*
 * Smart Plant Watering System
 * ===========================
 * Monitors soil moisture and auto-waters plants when soil gets too dry.
 * Includes manual override via button and status LED indicators.
 *
 * Hardware:
 *   - Soil Moisture Sensor (capacitive or resistive type)
 *   - 5V Relay Module (for water pump)
 *   - Mini water pump (3-6V)
 *   - LED (Green = moist, Red = dry)
 *   - Push button (manual water override)
 *
 * Wiring:
 *   Soil Moisture Sensor:
 *     VCC  -> 5V
 *     GND  -> GND
 *     AOUT -> A0
 *     DOUT -> (not used)
 *
 *   Relay Module:
 *     VCC  -> 5V
 *     GND  -> GND
 *     IN   -> Pin 8
 *
 *   LEDs:
 *     Green LED (+ 220ohm resistor) -> Pin 11 -> GND
 *     Red LED (+ 220ohm resistor)   -> Pin 10 -> GND
 *
 *   Push Button:
 *     One leg -> Pin 7, other leg -> GND (uses INPUT_PULLUP)
 *
 *   Water Pump:
 *     Connect to relay COM/NO terminals.
 *     Pump power from external 5V source (Arduino 5V pin for small pumps only).
 *
 * Usage:
 *   1. Calibrate DRY_VALUE and WET_VALUE by reading serial output
 *      with dry soil, then very wet soil.
 *   2. Adjust THRESHOLD accordingly (default 450 works for most sensors).
 */

const int moisturePin = A0;
const int relayPin = 8;
const int ledGreen = 11;
const int ledRed = 10;
const int buttonPin = 7;

// Calibrate these values for your sensor
const int DRY_VALUE = 600;   // Reading in dry air
const int WET_VALUE = 200;   // Reading in water
const int THRESHOLD = 450;   // Water when moisture exceeds this (lower = dryer soil)
const int WATER_DURATION = 3000;  // ms to run pump per watering cycle
const int CHECK_INTERVAL = 5000;  // ms between moisture checks

unsigned long lastCheck = 0;
bool pumpRunning = false;

void setup() {
  Serial.begin(9600);
  
  pinMode(relayPin, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  
  // Relay is HIGH = OFF, LOW = ON (active-low relay modules)
  digitalWrite(relayPin, HIGH);
  
  Serial.println("=== Smart Plant Watering System ===");
  Serial.println("Calibrating... place sensor in soil to begin.");
  delay(2000);
}

void loop() {
  unsigned long now = millis();
  
  // Manual override: button press waters immediately
  if (digitalRead(buttonPin) == LOW) {
    Serial.println("Manual watering activated!");
    waterPlants(WATER_DURATION * 2);
    delay(500);  // Debounce
  }
  
  // Automatic check
  if (now - lastCheck >= CHECK_INTERVAL && !pumpRunning) {
    lastCheck = now;
    checkMoisture();
  }
}

void checkMoisture() {
  int moisture = readMoisture();
  int percent = map(moisture, DRY_VALUE, WET_VALUE, 0, 100);
  percent = constrain(percent, 0, 100);
  
  Serial.print("Moisture: ");
  Serial.print(percent);
  Serial.print("% (raw: ");
  Serial.print(moisture);
  Serial.println(")");
  
  if (moisture > THRESHOLD) {
    // Soil is dry - turn off green, turn on red, water
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, HIGH);
    Serial.println("Soil is DRY! Watering...");
    waterPlants(WATER_DURATION);
  } else {
    // Soil is moist enough
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledRed, LOW);
    Serial.println("Soil moisture OK.");
  }
}

int readMoisture() {
  // Average 5 readings for stability
  int sum = 0;
  for (int i = 0; i < 5; i++) {
    sum += analogRead(moisturePin);
    delay(10);
  }
  return sum / 5;
}

void waterPlants(int duration) {
  pumpRunning = true;
  digitalWrite(relayPin, LOW);    // Turn pump ON (active-low relay)
  delay(duration);
  digitalWrite(relayPin, HIGH);   // Turn pump OFF
  pumpRunning = false;
  Serial.println("Watering cycle complete.");
}
