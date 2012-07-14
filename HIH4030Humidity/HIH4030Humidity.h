// HIH4030Humidity.h - Arduino library for retrieving data from Honeywell's HIH4030 Humidity sensor.
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

#ifndef HIH4030Humidity_h
#define HIH4030Humidity_h
#include <Arduino.h>

/// Arduino library for retrieving data from Honeywell's HIH4030 Humidity sensor.
class HIH4030Humidity
{
  public:
    HIH4030Humidity();
    void begin();
    void begin(int humidityPin); 

    int getHumidityRaw();
    float getHumidityPercentage();

    void setTemperature(int temperature);

  private:
    int _humidityPin;
    int _temperature;
    float _maxVoltage;
};
#endif
