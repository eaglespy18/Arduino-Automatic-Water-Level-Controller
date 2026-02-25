const int sensorPin = A0;  // Water sensor
const int redLED = 3;      // LOW water
const int yellowLED = 5;   // MEDIUM water
const int greenLED = 6;    // HIGH water
const int buzzer = 11;     // Buzzer for LOW water

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int value = analogRead(sensorPin);  // Read water sensor

  // LOW  Level
  if (value > 1 && value < 350) {
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
    tone(buzzer, 500); // Buzzer ON
  } else {
    digitalWrite(redLED, LOW);
    noTone(buzzer); // Buzzer OFF
  }

  // MEDIUM water Level 
  if (value >= 350 && value < 510) {
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
  } else {
    digitalWrite(yellowLED, LOW);
  }

  // HIGH water Level
  if (value >= 510) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
  } else {
    digitalWrite(greenLED, LOW);
  }

  delay(500); // Small delay for stability
}