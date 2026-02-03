// Complete Sensor Test Code
// Tests all 7 sensor modules simultaneously

// Pin Definitions
const int LED_FLASH_PIN = 13;
const int SPEED_SENSOR_PIN = 2;
const int BUZZER_PIN = 13;
const int TOUCH_DIGITAL_PIN = 7;
const int TOUCH_ANALOG_PIN = A0;
const int LIGHT_BARRIER_PIN = 11;
const int RGB_RED_PIN = 10;
const int RGB_GREEN_PIN = 11;
const int RGB_BLUE_PIN = 12;
const int TWO_COLOR_SIG_PIN = 10;
const int TWO_COLOR_VCC_PIN = 11;

// Variables
volatile int speedSensorCount = 0;
unsigned long lastMillis = 0;
bool touchDetected = false;
bool objectDetected = false;

void setup() {
  Serial.begin(9600);
  Serial.println("=== Arduino Sensor Modules Test ===");
  Serial.println("Initializing all sensors...");
  
  // Initialize pins
  pinMode(LED_FLASH_PIN, INPUT);
  pinMode(SPEED_SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(TOUCH_DIGITAL_PIN, INPUT);
  pinMode(LIGHT_BARRIER_PIN, INPUT);
  pinMode(RGB_RED_PIN, OUTPUT);
  pinMode(RGB_GREEN_PIN, OUTPUT);
  pinMode(RGB_BLUE_PIN, OUTPUT);
  pinMode(TWO_COLOR_SIG_PIN, OUTPUT);
  pinMode(TWO_COLOR_VCC_PIN, OUTPUT);
  
  // Attach interrupt for speed sensor
  attachInterrupt(digitalPinToInterrupt(SPEED_SENSOR_PIN), speedSensorISR, RISING);
  
  Serial.println("Setup complete. Starting sensor test...");
  Serial.println("======================================");
}

void loop() {
  unsigned long currentMillis = millis();
  
  // Update sensors every 500ms
  if (currentMillis - lastMillis >= 500) {
    lastMillis = currentMillis;
    
    // Read metal touch sensor
    touchDetected = digitalRead(TOUCH_DIGITAL_PIN);
    int touchIntensity = analogRead(TOUCH_ANALOG_PIN);
    
    // Read light barrier (inverted logic)
    objectDetected = !digitalRead(LIGHT_BARRIER_PIN);
    
    // Read 7-color LED module status
    int ledFlashState = digitalRead(LED_FLASH_PIN);
    
    // Print sensor readings
    Serial.println("\n=== Sensor Readings ===");
    Serial.print("Touch: ");
    Serial.print(touchDetected ? "DETECTED" : "None");
    Serial.print(" | Intensity: ");
    Serial.println(touchIntensity);
    
    Serial.print("Object: ");
    Serial.print(objectDetected ? "BLOCKED" : "Clear");
    Serial.print(" | LED Flash: ");
    Serial.println(ledFlashState ? "ON" : "OFF");
    
    Serial.print("Speed Count: ");
    Serial.println(speedSensorCount);
    
    // Reset speed counter
    speedSensorCount = 0;
    
    // Test RGB LED
    testRGBLED();
    
    // Test 2-color LED
    testTwoColorLED();
    
    // Sound buzzer if touch detected
    if (touchDetected) {
      digitalWrite(BUZZER_PIN, HIGH);
      delay(50);
      digitalWrite(BUZZER_PIN, LOW);
    }
  }
}

// Speed Sensor Interrupt Service Routine
void speedSensorISR() {
  speedSensorCount++;
}

// RGB LED Test Function
void testRGBLED() {
  Serial.println("Testing RGB LED...");
  
  // Cycle through colors
  setRGBColor(255, 0, 0);   // Red
  delay(100);
  setRGBColor(0, 255, 0);   // Green
  delay(100);
  setRGBColor(0, 0, 255);   // Blue
  delay(100);
  setRGBColor(255, 255, 0); // Yellow
  delay(100);
  setRGBColor(0, 255, 255); // Cyan
  delay(100);
  setRGBColor(255, 0, 255); // Magenta
  delay(100);
  setRGBColor(0, 0, 0);     // Off
}

// Set RGB Color Function
void setRGBColor(int red, int green, int blue) {
  analogWrite(RGB_RED_PIN, red);
  analogWrite(RGB_GREEN_PIN, green);
  analogWrite(RGB_BLUE_PIN, blue);
}

// 2-Color LED Test Function
void testTwoColorLED() {
  Serial.println("Testing 2-Color LED...");
  
  // Red
  digitalWrite(TWO_COLOR_SIG_PIN, HIGH);
  digitalWrite(TWO_COLOR_VCC_PIN, LOW);
  delay(100);
  
  // Green
  digitalWrite(TWO_COLOR_SIG_PIN, LOW);
  digitalWrite(TWO_COLOR_VCC_PIN, HIGH);
  delay(100);
  
  // Both (Orange/Yellow)
  digitalWrite(TWO_COLOR_SIG_PIN, HIGH);
  digitalWrite(TWO_COLOR_VCC_PIN, HIGH);
  delay(100);
  
  // Off
  digitalWrite(TWO_COLOR_SIG_PIN, LOW);
  digitalWrite(TWO_COLOR_VCC_PIN, LOW);
}
