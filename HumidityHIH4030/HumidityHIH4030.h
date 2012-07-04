// HumidityHIH4030.h - Arduino library for retrieving data from the analog GP2Y0A21YK IR Humidity sensor
// Copyright 2012 Jeroen Doggen (jeroendoggen@gmail.com)
//
// Version History:
//  Version 0.1: getHumidityRaw, getHumidityPercentage
// Roadmap:
//  Version 0.2: Compensation for Vcc variance?
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

#ifndef HumidityHIH4030_h
#define HumidityHIH4030_h
#include <Arduino.h>

class HumidityHIH4030
{
  public:
    HumidityHIH4030();
    void begin();                                 // begin using default values
    void begin(int humidityPin);                  // begin using a user selected analog pin

    int getHumidityRaw();                         // get the humidity raw ADC value
    float getHumidityPercentage();                // get the humidity percentage

    void setTemperature(int temperature);         // set the room temperature (used in humidity calculation)(default value: 20° Celsius)

  private:
    int _humidityPin;                             // analog pin where the sensor is connected
    int _temperature;                             // current temperature
    float _maxVoltage;                            // maximum voltage
};
#endif
