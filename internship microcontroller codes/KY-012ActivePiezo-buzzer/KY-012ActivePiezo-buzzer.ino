// code to switch on buzzer for 4 seconds and off for 2 seconds.
int buzzer = 13;
 
void setup() {
  pinMode(buzzer, OUTPUT); // Initialization output pin for the buzzer
}

// Main program loop
void loop() {
  // Buzzer is switched on
  digitalWrite(buzzer, HIGH);
  // Wait mode for 4 seconds
  delay(4000); 
  // Buzzer is switched off
  digitalWrite(buzzer, LOW); 
  // Waiting for a further two seconds
  delay(2000);
}

