# ArduinoSmartMeterReader

Arduino/Photon library to read realtime usage from smart electricity meters

Some smart meters have an LED that flashes to indicate how much electricity is currently being used.  
The meter will be labelled like `1000 imp/kWh` (impressions per kWh). An impression is a flash of the LED. For the meter in the image below, 1000 flashes of the LED indicates that 1 kWh of power has been used. Not all meters are 1000 imp/kWh.

[![Smart meter impressions led](docs/images/smart_meter_impressions_led.png)]

```
current power use = seconds per hour / (seconds between flashes * impressions per kWh)
```

For a meter with 1000 imp/kWh and a time of 3 seconds between flashes, the current power use is 1.2 kW.
```
3600 / (3 * 1000) = 1.2 kW
```

SmartMeterReader defaults to 1000 imp/kWh, but this can be changed by calling `setImpressionsPerkWh`.

The library is designed to be driven by an interrupt on the photoresistor pin to make sure every pulse is received.


## Example Usage

```c
#include "SmartMeterReader.h"
```

[SmartMeterReaderDemo.ino](examples/SmartMeterReaderDemo.ino) provides a more comprehensive example of use.  
[PhotonLiveUpdateDemo.ino](examples/PhotonLiveUpdateDemo.ino) shows how to get live updates of the readings over the internet.


## Documentation

The [docs](docs/) directory has a circuit diagram for the project, along with a bill of materials.

In order to test your project without a smart meter, a linear [potentiometer](https://www.adafruit.com/products/562) can be used to make an LED flash faster or slower. See [test circuit](docs/TestCircuit.md) for a circuit diagram and a bill of materials.

## Ideas for extension

* Use a [RGB LCD](https://www.adafruit.com/products/398) to display the current usage and change the background colour to indicate power usage at a glance.