// ARDUINO DIGITAL INPUT PIN STATE CHECK FOR BPW34 PHOTO DIODE
// THIS CODE IS FREE TO USE, MODIFY AND DISTRUBUTE

void setup() {
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop() {
  int digitalVal = digitalRead(2);
  
  Serial.print("D2 Digital State: ");
  Serial.print(digitalVal == HIGH ? "HIGH" : "LOW");
  Serial.print(" | Output Voltage: ");
  Serial.print(digitalVal == HIGH ? "5.00" : "0.00");
  Serial.println(" V");
  
  delay(200);
}
