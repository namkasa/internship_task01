int led = 13;
void setup() {
  pinMode(led, OUTPUT); //initialisation output pin for the LED

}

void loop() {
  digitalWrite(led, HIGH); //LED is switched on
  delay(4000);// wait for 4 seconds 
  digitalWrite(led, LOW); //LED is switched off
  delay(2000); //wait another 2 seconds

}
