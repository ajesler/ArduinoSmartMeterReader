#include "SmartMeterReader.h"
#include "Arduino.h"

SmartMeterReader::SmartMeterReader(int pin) {
  _inputPin = pin;
  _impressionsPerkWh = 1000; // this should be configurable

  // set the pin mode
  pinMode(_inputPin, INPUT);
}

void SmartMeterReader::setImpressionsPerkWh(int impressions) {
  _impressionsPerkWh = impressions;
}

void SmartMeterReader::recordFlash() {
  _hasReading = _startMillis != 0;

  _startMillis = _endMillis;
  _endMillis = millis();
}

bool SmartMeterReader::hasReading() {
  return _hasReading;
}

float SmartMeterReader::reading() {
  long delta = _endMillis - _startMillis; // disable interrupt here?
  float flashesPerSecond = (float)delta / 1000;
  _latestReading = SECONDS_PER_HOUR / (flashesPerSecond * _impressionsPerkWh);
  _hasReading = false;

  return _latestReading;
}
