// ARDUINO ANALOG VOLTAGE CHECK FOR BPW34 PHOTO DIODE
// THIS CODE IS FREE TO USE, MODIFY AND DISTRUBUTE

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorVal = analogRead(A1);
  Serial.print("Raw A1 Value: ");
  Serial.print(sensorVal);
  Serial.print(" | Voltage: ");
  Serial.print(sensorVal * (5.0 / 1023.0));
  Serial.println(" V");
  delay(200);
}
