/* 
Use this with the the Smart Meter Simulator circuit
described in docs/SmartMeterSimulator.md to test the
reader.
*/
const int potentiometerPin = A2;
const int ledPin = 12;

void setup() {
  pinMode(ledPin, OUTPUT);
}

int potReading;
int flashDelay;

void loop() {
  potReading = analogRead(A2);
  flashDelay = map(potReading, 0, 1023, 0, 6000);
  delay(flashDelay);

  digitalWrite(ledPin, HIGH);
  delay(10);
  digitalWrite(ledPin, LOW);
}