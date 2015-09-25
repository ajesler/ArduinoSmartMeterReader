#include "Arduino.h"
#include "SmartMeterReader.h"

const int photoresistorPin = 3;
const int pulseLedPin = 4;

SmartMeterReader smartMeterReader(photoresistorPin);
float reading;

void recordFlashISR() {
  smartMeterReader.recordFlash();
}

void setup() {
  Serial.begin(115200);
  smartMeterReader.setImpressionsPerkWh(800); // only required if the meter is not 1000 imp/kWh
  pinMode(pulseLedPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(photoresistorPin), recordFlashISR, RISING);
}

void loop() {
  if (smartMeterReader.hasReading()) {
    reading = smartMeterReader.reading();

    Serial.print("Latest reading is ");
    Serial.print(reading);
    Serial.println(" kW");

    // flash the led to indicate a meter flash has been recorded
    digitalWrite(pulseLedPin, HIGH);
    delay(10);
    digitalWrite(pulseLedPin, LOW);
  }

  // the higher this delay, the longer the the LED may flash after the meter flashes
  // using a small delay means the LED on pulsePinLed should flash at the same time as the meter LED.
  delay(10);
}

