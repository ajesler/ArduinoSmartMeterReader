#ifndef SmartMeterReader_H
#define SmartMeterReader_H

#ifdef SPARK
#include "application.h"
#else
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#endif

#define SECONDS_PER_HOUR 3600

class SmartMeterReader {

public:

  SmartMeterReader(int pin);

  void setImpressionsPerkWh(int impressions);
  void recordFlash();
  bool hasReading();
  float reading();

private:

  int _inputPin;
  int _impressionsPerkWh;

  float _latestReading;
  bool _hasReading;
  long _startMillis;
  long _endMillis;

};

#endif
