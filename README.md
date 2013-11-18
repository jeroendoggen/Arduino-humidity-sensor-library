Arduino library for analog Honeywell humidity sensors.

The library provides simplifies the usage of this sensor in Arduino projects.

The sensor is preconfigured for use at room temperature, but can be reconfigured at runtime.

## Library Usage
 * Download the source
 * Place the HIH4030Humidity folder in your Arduino1.0+ "libraries" folder
 * Open example sketch: "file", "Examples", "HIH4030Humidity", "HumidityPercentage" (or "RawData")
 * Connect the analog sensor to port A0 (and connect Vcc and GND)
 * Compile & upload code
 * Sensor data should be arriving over the serial port

## How the Sensor Works:
 * todo

## Screenshot:
![Serial monitor screenshot](Images/screenshot.png?raw=true)


## Version History:                                                                                    
 * Version 0.1: getHumidityRaw, getHumidityPercentage
 * Version 0.2: setTemperature

## Roadmap:                                                                                           
 * Version 0.3: Compensation for Vcc variance?
