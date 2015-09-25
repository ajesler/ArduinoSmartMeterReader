# Smart Meter Simulator

This document shows how to make a circuit with an easily adjustable LED flashing rate. This is useful for testing your meter reader circuit without having to use an acutal smart meter. A second Arduino is required to run the meter simulator.


## Bill of Materials

* (1) Arduino
* (1) [10K linear potentiometer](https://www.adafruit.com/products/562)
* (1) LED, any colour
* (1) 220Ω resistor


## Circuit Diagram

![smart meter simulator circuit diagram](docs/images/smart-meter-simulator-circuit-diagram.png)


## Testing in action

A post-it note made an excellent tube to hold the meter reader sensor and simulator LED together, but still allows the flash of the simulator to be seen through the paper. There have been no issues with false triggering due to ambient light with this setup.  
By turning the potentiometer, the LED flash rate changes.

![testing the reader](docs/images/testing-the-reader.jpg)