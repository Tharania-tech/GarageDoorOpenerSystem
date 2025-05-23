#include <Servo.h>

Servo garageDoor;
const int trigPin = 11;
const int echoPin = 1;
const int relayPin = 9;
long duration;
int distance;

void setup() {
  garageDoor.attach(9);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relayPin, OUTPUT);
  garageDoor.write(0); // Door closed position
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pin
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // If an object is detected within 10 cm, open the door
  if (distance < 10) {
    garageDoor.write(90); // Open door
    digitalWrite(relayPin, HIGH); // Activate relay
  } else {
    garageDoor.write(0); // Close door
    digitalWrite(relayPin, LOW); // Deactivate relay
  }

  delay(500);
}

