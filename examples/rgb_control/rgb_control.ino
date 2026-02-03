// KY-009 RGB LED Control
// Color mixing and effects

const int RED_PIN = 10;
const int GREEN_PIN = 11;
const int BLUE_PIN = 12;

// Color definitions
struct Color {
  int red;
  int green;
  int blue;
  String name;
};

Color colors[] = {
  {255, 0, 0, "Red"},
  {0, 255, 0, "Green"},
  {0, 0, 255, "Blue"},
  {255, 255, 0, "Yellow"},
  {0, 255, 255, "Cyan"},
  {255, 0, 255, "Magenta"},
  {255, 255, 255, "White"},
  {255, 165, 0, "Orange"},
  {128, 0, 128, "Purple"}
};

const int numColors = sizeof(colors) / sizeof(colors[0]);

void setup() {
  Serial.begin(9600);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  
  Serial.println("=== KY-009 RGB LED Controller ===");
  Serial.println("Cycling through colors...");
}

void loop() {
  // Cycle through all colors
  for (int i = 0; i < numColors; i++) {
    setColor(colors[i]);
    Serial.print("Showing: ");
    Serial.println(colors[i].name);
    delay(1000);
  }
  
  // Fade effect
  Serial.println("Starting fade effect...");
  fadeEffect();
  
  // Random colors
  Serial.println("Random colors...");
  for (int i = 0; i < 10; i++) {
    randomColor();
    delay(500);
  }
}

void setColor(Color c) {
  analogWrite(RED_PIN, c.red);
  analogWrite(GREEN_PIN, c.green);
  analogWrite(BLUE_PIN, c.blue);
}

void fadeEffect() {
  // Red fade
  for (int i = 0; i <= 255; i++) {
    analogWrite(RED_PIN, i);
    delay(10);
  }
  for (int i = 255; i >= 0; i--) {
    analogWrite(RED_PIN, i);
    delay(10);
  }
  
  // Green fade
  for (int i = 0; i <= 255; i++) {
    analogWrite(GREEN_PIN, i);
    delay(10);
  }
  for (int i = 255; i >= 0; i--) {
    analogWrite(GREEN_PIN, i);
    delay(10);
  }
  
  // Blue fade
  for (int i = 0; i <= 255; i++) {
    analogWrite(BLUE_PIN, i);
    delay(10);
  }
  for (int i = 255; i >= 0; i--) {
    analogWrite(BLUE_PIN, i);
    delay(10);
  }
}

void randomColor() {
  int r = random(256);
  int g = random(256);
  int b = random(256);
  
  analogWrite(RED_PIN, r);
  analogWrite(GREEN_PIN, g);
  analogWrite(BLUE_PIN, b);
  
  Serial.print("Random RGB: (");
  Serial.print(r);
  Serial.print(", ");
  Serial.print(g);
  Serial.print(", ");
  Serial.print(b);
  Serial.println(")");
}
