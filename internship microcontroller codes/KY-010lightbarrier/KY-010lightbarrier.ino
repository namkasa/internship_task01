int SensorPIN = 10; // to define the sensor input pin
int value; //temporary variable

void setup() {
  pinMode(SensorPIN, INPUT); // to define the sensor pin as an input 
  digitalWrite(SensorPIN, HIGH); // activation of the internal pull-up resistor
  Serial.begin(9600); //te beginning of the serial monitor 
  Serial.println("Light barrier test");
}

void loop() {
  value = digitalRead(SensorPIN) ; // to read the sensor value.
  if (value == HIGH) 
  {
  Serial.println("Detected");
  delay(100); //100 milisecond break before the next loop
  }

}
