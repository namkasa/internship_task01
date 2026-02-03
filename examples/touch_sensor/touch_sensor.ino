// KY-036 Metal Touch Sensor
// Digital and analog touch detection with threshold

const int DIGITAL_PIN = 7;
const int ANALOG_PIN = A0;
const int BUZZER_PIN = 8;
const int LED_PIN = 13;

const int THRESHOLD = 500;  // Adjust based on calibration
int touchValue = 0;
bool digitalState = false;
bool lastState = false;

void setup() {
  Serial.begin(9600);
  pinMode(DIGITAL_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  
  Serial.println("=== KY-036 Metal Touch Sensor ===");
  Serial.println("Touch the metal pad to test...");
  Serial.println("================================");
}

void loop() {
  // Read sensor values
  touchValue = analogRead(ANALOG_PIN);
  digitalState = digitalRead(DIGITAL_PIN);
  
  // Print values
  Serial.print("Analog: ");
  Serial.print(touchValue);
  Serial.print(" | Digital: ");
  Serial.print(digitalState ? "HIGH" : "LOW");
  Serial.print(" | Threshold: ");
  Serial.print(THRESHOLD);
  Serial.print(" | Status: ");
  
  // Check touch detection
  if (touchValue > THRESHOLD || digitalState) {
    Serial.println("TOUCHED");
    digitalWrite(LED_PIN, HIGH);
    
    // Beep pattern based on intensity
    int beeps = map(touchValue, THRESHOLD, 1023, 1, 5);
    for (int i = 0; i < beeps; i++) {
      digitalWrite(BUZZER_PIN, HIGH);
      delay(50);
      digitalWrite(BUZZER_PIN, LOW);
      delay(50);
    }
  } else {
    Serial.println("No touch");
    digitalWrite(LED_PIN, LOW);
  }
  
  // State change detection
  if (digitalState != lastState) {
    Serial.print("State changed to: ");
    Serial.println(digitalState ? "TOUCHED" : "RELEASED");
    lastState = digitalState;
  }
  
  delay(200);
}
