/*
 * Auto-Dimming Night Light
 * =========================
 * Automatically turns on LED when dark, with smooth brightness
 * based on ambient light level. Turns off during daytime.
 * Uses PWM for smooth fade transitions.
 *
 * Hardware:
 *   - LDR (Light Dependent Resistor) + 10k resistor
 *   - LEDs (warm white recommended) or LED strip
 *   - TIP120 NPN Transistor (for LED strips) OR direct drive
 *
 * Wiring:
 *
 *   LDR (Voltage Divider):
 *     LDR -> 5V
 *     LDR -> A0 --- 10k Resistor ---| GND
 *
 *   LED (Single LED or small group):
 *     LED Anode -> 5V (via 150ohm resistor per LED)
 *     LED Cathode -> Pin 9 (PWM)
 *     Note: For multiple LEDs or strips, use TIP120 transistor:
 *       LED+ -> 12V adapter -> LED strip VCC
 *       LED strip GND -> TIP120 Collector
 *       TIP120 Emitter -> GND
 *       TIP120 Base   -> 1k resistor -> Pin 9
 *
 *   Optional Button (manual override):
 *     Button Pin 1 -> Pin 7
 *     Button Pin 2 -> GND
 *
 * Usage:
 *   1. Open Serial Monitor and note LDR readings:
 *      - In a bright room: ~600-900 (adjust BRIGHT_DARK)
 *      - In darkness: ~100-200 (adjust DARK_LEVEL)
 *   2. Adjust thresholds below for your environment.
 *   3. The LED will smoothly fade based on ambient light.
 */

const int ldrPin = A0;
const int ledPin = 9;
const int buttonPin = 7;

// LDR Thresholds - CALIBRATE THESE for your setup!
const int LIGHT_LEVEL = 500;  // Below = getting dark
const int DARK_LEVEL = 150;   // Below = fully dark

// LED brightness range (PWM: 0-255)
const int MIN_BRIGHTNESS = 50;   // Minimum LED brightness when dark
const int MAX_BRIGHTNESS = 255;  // Full brightness in darkness

// Smooth transition settings
const int FADE_STEP = 5;         // How fast brightness changes per cycle
const int CHECK_INTERVAL = 200;  // ms between sensor reads

unsigned long lastCheck = 0;
int currentBrightness = 0;
bool manualOverride = false;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  
  analogWrite(ledPin, 0);
  
  Serial.println("=== Auto-Dimming Night Light ===");
  Serial.println("Place sensor in its final location first.");
  Serial.println("Press button to toggle manual override.");
}

void loop() {
  unsigned long now = millis();
  
  // Check button for manual toggle
  if (digitalRead(buttonPin) == LOW) {
    manualOverride = !manualOverride;
    if (manualOverride) {
      Serial.println("Manual mode: ON");
    } else {
      Serial.println("Manual mode: AUTO");
    }
    delay(300); // Debounce
  }
  
  if (now - lastCheck >= CHECK_INTERVAL) {
    lastCheck = now;
    
    if (manualOverride) {
      // Manual mode: keep LED at max
      fadeTo(MAX_BRIGHTNESS);
    } else {
      int ldrValue = analogRead(ldrPin);
      int targetBrightness = calculateBrightness(ldrValue);
      fadeTo(targetBrightness);
      
      Serial.print("LDR: ");
      Serial.print(ldrValue);
      Serial.print(" | Brightness: ");
      Serial.println(currentBrightness);
    }
  }
}

int calculateBrightness(int ldrValue) {
  if (ldrValue < DARK_LEVEL) {
    return MAX_BRIGHTNESS;  // Fully dark, max brightness
  } else if (ldrValue > LIGHT_LEVEL) {
    return 0;               // Bright enough, LED off
  }
  
  // Map dark-to-light range to brightness range
  int brightness = map(ldrValue, DARK_LEVEL, LIGHT_LEVEL, MAX_BRIGHTNESS, MIN_BRIGHTNESS);
  return brightness;
}

void fadeTo(int target) {
  // Smooth transition (prevents jarring brightness jumps)
  while (currentBrightness != target) {
    if (currentBrightness < target) {
      currentBrightness += FADE_STEP;
      if (currentBrightness > target) currentBrightness = target;
    } else {
      currentBrightness -= FADE_STEP;
      if (currentBrightness < target) currentBrightness = target;
    }
    analogWrite(ledPin, currentBrightness);
    delay(10);
  }
}
