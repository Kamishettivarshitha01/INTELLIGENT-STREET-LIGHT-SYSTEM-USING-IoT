// ----- Smart Light Control using LDR + Relay + PWM LED -----

#define relayPin 7          // Relay for big bulb
int ldrPin = A0;            // LDR sensor pin
int ledPin = 9;             // LED PWM pin

void setup() {
  pinMode(relayPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  digitalWrite(relayPin, HIGH); // Relay OFF initially

  Serial.begin(9600);
}

void loop() {
  // ----- Read LDR -----
  int sensorValue = analogRead(ldrPin);

  // ----- Relay Control -----
  if (sensorValue > 1000) {     // Adjust threshold as needed
    digitalWrite(relayPin, LOW);  // Relay ON (big bulb ON)
  } else {
    digitalWrite(relayPin, HIGH); // Relay OFF (big bulb OFF)
  }

  // ----- LED Brightness Control -----
  int brightness = map(sensorValue, 76, 1023, 0, 255);
  brightness = constrain(brightness, 30, 255); // Keeps brightness within range

  analogWrite(ledPin, brightness);

  // ----- Debugging -----
  Serial.print("LDR Sensor: ");
  Serial.print(sensorValue);
  Serial.print(" -> LED Brightness: ");
  Serial.print(brightness);

  if (sensorValue > 1000) {
    Serial.println(" | Relay: ON (Dark)");
  } else {
    Serial.println(" | Relay: OFF (Bright)");
  }

  delay(200); // Small delay for stability
}
