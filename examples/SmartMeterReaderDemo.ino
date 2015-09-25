#include "SmartMeterReader.h"

#define D3 3
const int pulseLedPin = 4;

SmartMeterReader smartMeterReader(D3);
float reading;

void recordFlashISR() {
  smartMeterReader.recordFlash();
}

void setup() {
  Serial.begin(115200);
  smartMeterReader.setImpressionsPerkWh(800); // only required if the meter is not 1000 imp/kWh
  pinMode(pulseLedPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(D3), recordFlashISR, RISING);
}

void loop() {
  if (smartMeterReader.hasReading()) {
    reading = smartMeterReader.reading();

    Serial.print("Latest reading is ");
    Serial.print(reading);
    Serial.println(" kW");

    digitalWrite(pulseLedPin, HIGH);
    delay(10);
    digitalWrite(pulseLedPin, LOW);
  }

  delay(10);
}

