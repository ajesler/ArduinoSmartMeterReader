#include "SmartMeterReader.h"

SmartMeterReader::SmartMeterReader(int pin) {
  _inputPin = pin;
  _impressionsPerkWh = 1000;
  _startMillis = 0;

  // set the pin mode
  pinMode(_inputPin, INPUT);
}

void SmartMeterReader::setImpressionsPerkWh(int impressions) {
  _impressionsPerkWh = impressions;
}

void SmartMeterReader::recordFlash() {
  _hasReading = _startMillis != 0 && _startMillis < _endMillis; // millis will overflow after ~50 days

  _startMillis = _endMillis;
  _endMillis = millis();
}

bool SmartMeterReader::hasReading() {
  return _hasReading;
}

float SmartMeterReader::reading() {
  long delta = _endMillis - _startMillis;
  float flashesPerSecond = (float)delta / 1000;
  float skWh = flashesPerSecond * _impressionsPerkWh;
  _latestReading = SECONDS_PER_HOUR / skWh;
  _hasReading = false;

  return _latestReading;
}
