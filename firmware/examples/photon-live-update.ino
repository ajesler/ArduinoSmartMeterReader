#include "application.h"
#include "SmartMeterReader.h"

const int MIN_READING_GAP = 15; // upload a reading at most every 15 seconds.
const int photoresistorPin = D3;
const int pulseLedPin = D6;

SmartMeterReader smartMeterReader(photoresistorPin);
float reading;
String stringReading;
int lastUploadTime = 0;

void recordFlashISR() {
  smartMeterReader.recordFlash();
}

void uploadReading() {
    int now = Time.now();
    if (now - lastUploadTime > MIN_READING_GAP) {
        stringReading = String(reading, 2);
        Spark.publish("power-usage", stringReading, 60, PRIVATE);
        lastUploadTime = now;
    }
}

void setup() {
  Serial.begin(115200);
  pinMode(pulseLedPin, OUTPUT);
  attachInterrupt(photoresistorPin, recordFlashISR, RISING);
}

void loop() {
  if (smartMeterReader.hasReading()) {
    reading = smartMeterReader.reading();

    Serial.print("Latest reading is ");
    Serial.print(reading, 2);
    Serial.println(" kW");

    // flash the led to indicate a meter flash has been recorded
    digitalWrite(pulseLedPin, HIGH);
    delay(10);
    digitalWrite(pulseLedPin, LOW);

    uploadReading();
  } else {
    delay(30);
  }
}
