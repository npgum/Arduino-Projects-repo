/*
 * Motion-Activated Security Light with Auto-Off Timer
 * ====================================================
 * Detects motion using PIR sensor and turns on a light/LED strip.
 * Stays on for configurable duration after last detected motion.
 * Includes light level sensor to only activate in darkness.
 *
 * Hardware:
 *   - PIR Motion Sensor (HC-SR501)
 *   - LDR (Light Dependent Resistor) + 10k resistor
 *   - 5V Relay Module OR LED strip with MOSFET
 *   - Status LED indicator
 *
 * Wiring:
 *   PIR Sensor:
 *     VCC  -> 5V
 *     GND  -> GND
 *     OUT  -> Pin 2
 *
 *   LDR (voltage divider):
 *     LDR -> 5V
 *     LDR -> A0 -> 10k resistor -> GND
 *
 *   Relay (for lamp/LED strip):
 *     VCC  -> 5V
 *     GND  -> GND
 *     IN   -> Pin 8
 *
 *   Status LED (+ 220ohm resistor):
 *     Anode -> Pin 13, Cathode -> GND
 *
 * Usage:
 *   1. Adjust LIGHT_THRESHOLD based on room ambient light reading
 *      (check Serial Monitor for LDR values).
 *   2. Set TIMEOUT_MS for how long light stays on after motion.
 *   3. Mount PIR sensor facing entry point, adjust sensitivity
 *      using HC-SR501 potentiometers.
 */

const int pirPin = 2;
const int ldrPin = A0;
const int relayPin = 8;
const int statusLed = 13;

// Configurable settings
const int LIGHT_THRESHOLD = 500;  // Below this = dark (adjust for your room)
const unsigned long TIMEOUT_MS = 30000;  // Light stays on 30s after last motion
const bool FORCE_ON_DARKNESS = true;    // Only activate when it's dark

unsigned long motionTime = 0;
bool lightOn = false;
unsigned long lastSerialUpdate = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(statusLed, OUTPUT);
  digitalWrite(relayPin, HIGH);  // Relay OFF (active-low)
  Serial.println("=== Motion-Activated Security Light ===");
}

void loop() {
  bool motionDetected = digitalRead(pirPin) == HIGH;
  int lightLevel = analogRead(ldrPin);
  bool isDark = lightLevel < LIGHT_THRESHOLD;
  bool shouldActivate = !FORCE_ON_DARKNESS || isDark;
  
  unsigned long now = millis();
  
  if (motionDetected && shouldActivate) {
    motionTime = now;
    if (!lightOn) {
      Serial.println("[MOTION] Activating light!");
      digitalWrite(relayPin, LOW);   // Light ON
      digitalWrite(statusLed, HIGH);
      lightOn = true;
      logStatus(motion, lightLevel, isDark);
    }
  }
  
  // Timeout check
  if (lightOn && (now - motionTime >= TIMEOUT_MS)) {
    Serial.println("[TIMEOUT] Turning off light.");
    digitalWrite(relayPin, HIGH);    // Light OFF
    digitalWrite(statusLed, LOW);
    lightOn = false;
  }
  
  // Periodic status update
  if (now - lastSerialUpdate >= 5000) {
    lastSerialUpdate = now;
    logStatus(lightOn ? "ACTIVE" : "STANDBY", lightLevel, isDark);
  }
  
  delay(100);
}

void logStatus(const char* state, int lightLevel, bool isDark) {
  Serial.print("State: ");
  Serial.print(state);
  Serial.print(" | Light: ");
  Serial.print(lightLevel);
  Serial.print(" (dark: ");
  Serial.print(isDark ? "YES" : "NO");
  Serial.println(")");
}
