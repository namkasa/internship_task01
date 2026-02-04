 //code to alternating LEDs
int led_red =10; //pin for red 
int led_green = 11; //pin for green
int led_blue = 12; //pin for blue


void setup() {
  //intialisation of output pin 
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_blue, OUTPUT);

}

void loop() {
  digitalWrite(led_red, HIGH);// the red LED is on
  digitalWrite(led_green, LOW); // the green LED is off
  digitalWrite(led_blue, LOW); //the blue LED is off
  delay(4000); //wait 3 seconds 
  
  digitalWrite(led_red, LOW); // the red LED is off
  digitalWrite(led_green, HIGH); // the green LED is  on
  digitalWrite(led_blue,LOW ); //the blue LED is off
  delay(4000); //wait 3 seconds 

  digitalWrite(led_red, LOW ); // the red LED is off
  digitalWrite(led_green,LOW ); // the green LED is off
  digitalWrite(led_blue, HIGH); //the blue LED is on
  delay(4000); //wait 3 seconds 
} 
