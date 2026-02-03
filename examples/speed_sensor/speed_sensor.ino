// LM393 Speed Sensor - RPM Calculator
// Measures rotation speed using perforated disc

const int SENSOR_PIN = 2;
const int LED_INDICATOR = 13;

volatile unsigned long pulseCount = 0;
unsigned long lastTime = 0;
const int HOLES_IN_DISC = 20; // Change this to match your disc
float rpm = 0;

void setup() {
  Serial.begin(9600);
  pinMode(SENSOR_PIN, INPUT);
  pinMode(LED_INDICATOR, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(SENSOR_PIN), countPulse, RISING);
  
  Serial.println("=== LM393 Speed Sensor RPM Calculator ===");
  Serial.print("Disc holes: ");
  Serial.println(HOLES_IN_DISC);
  Serial.println("========================================");
}

void loop() {
  unsigned long currentTime = millis();
  
  if (currentTime - lastTime >= 1000) { // Calculate every second
    lastTime = currentTime;
    
    // Calculate RPM
    noInterrupts();
    rpm = (pulseCount * 60.0) / HOLES_IN_DISC;
    pulseCount = 0;
    interrupts();
    
    // Print results
    Serial.print("Time: ");
    Serial.print(currentTime / 1000);
    Serial.print("s | RPM: ");
    Serial.print(rpm);
    Serial.print(" | Frequency: ");
    Serial.print(rpm * HOLES_IN_DISC / 60.0);
    Serial.println(" Hz");
    
    // Blink LED for visual feedback
    digitalWrite(LED_INDICATOR, HIGH);
    delay(50);
    digitalWrite(LED_INDICATOR, LOW);
  }
}

void countPulse() {
  pulseCount++;
}
