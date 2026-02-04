//to turn LEDs on or off
int led_red = 11; //pin for red
int led_green = 10; //pin for green 

void setup() {
  // initialisation of output pins for the LEDs
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);

}

void loop() {
  diitalWrite(led_red, HIGH); // red LED is switched on
  digitalWrite(led_green, LOW); // green LED is switched off
  delay(3000); //for 3 seconds 

  digitalWrite(led_red, LOW); //switched off
  digitalWrite(led_green, LOW);
  delay(3000); //for another 3 seconds 

}
