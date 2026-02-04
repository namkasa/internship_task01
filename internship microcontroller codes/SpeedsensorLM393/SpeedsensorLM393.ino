
  //code to measure the speed of a geared wheel with an encoder wheel 
// Define the digital pin connected to the LM393 sensor output
const int encoderPin = 2; // Digital Pin 2 for Interrupt 0

// Define the number of slots/holes on your encoder disk
// You need to count this on your specific disk
const int pulsesPerRevolution = 20; // Example: 20 holes/slots

// Volatile variable to store the number of pulses
volatile long pulseCount = 0;

// Time variables for RPM calculation
unsigned long prevMillis = 0;
const long interval = 1000; // Calculate RPM every 1 second (in milliseconds)

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  Serial.println("Motor Speed Measurement Ready");

  // Set the encoder pin as an input
  pinMode(encoderPin, INPUT_PULLUP); // Use INPUT_PULLUP if the sensor output is open-drain/NPN
                                   // Otherwise, just INPUT and ensure sensor has a pull-up resistor

  // Attach an interrupt to the encoder pin
  // RISING: Triggers when the signal goes from LOW to HIGH
  // FALLING: Triggers when the signal goes from HIGH to LOW
  // CHANGE: Triggers on both RISING and FALLING edges (might need to divide pulses by 2)
  attachInterrupt(digitalPinToInterrupt(encoderPin), pulseCounter, RISING);
}

void loop() {
  // Check if it's time to calculate RPM
  unsigned long currentMillis = millis();
  //tis loop contionously checks if one second as passed since RPM calculation.
  if (currentMillis - prevMillis >= interval) {
    prevMillis = currentMillis;

    // Disable interrupts while reading pulseCount to prevent corruption
    noInterrupts();
    long currentPulses = pulseCount;
    pulseCount = 0; // Reset counter for the next interval
    interrupts();

    // Calculate RPM
    // (Pulses / Pulses_per_revolution) = Revolutions in the interval
    // (Revolutions / (Interval_in_seconds)) = Revolutions per second
    // (Revolutions per second * 60) = Revolutions per minute (RPM)

    // Ensure interval is not zero to avoid division by zero
    float durationSeconds = (float)interval / 1000.0;//converts the milliseconds into seconds 
    if (durationSeconds == 0) durationSeconds = 1.0; // Prevent division by zero if interval is somehow 0

    float revolutions = (float)currentPulses / pulsesPerRevolution;
    float rps = revolutions / durationSeconds;
    float rpm = rps * 60.0; // converts the revolutions per second to revolutions per minute 

    // Print the result to the Serial Monitor
    Serial.print("Pulses: ");
    Serial.print(currentPulses);
    Serial.print("\tRPM: ");
    Serial.println(rpm);
  }
}

// Interrupt Service Routine (ISR) - This function is called every time an interrupt is detected
void pulseCounter() {
  pulseCount++;
}




//void loop() {
  // put your main code here, to run repeatedly:

//}
