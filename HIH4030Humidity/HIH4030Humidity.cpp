/// HIH4030Humidity.cpp - Arduino library for retrieving data from the analog GP2Y0A21YK IR Humidity sensor
/// Copyright 2012 Jeroen Doggen (jeroendoggen@gmail.com)
/// For more information: variable declaration, changelog,... see HIH4030Humidity.h
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

#include <Arduino.h>
#include <HIH4030Humidity.h>

#define ZEROPERCENTVOLTAGE 0.8

/// Default constructor.
HIH4030Humidity::HIH4030Humidity()
{
}

///Begin using default values: humidityPin = A0.
void
HIH4030Humidity::begin()
{                            // default value: 20° Celcius
  begin (A0);
}

/// Begin with user selected analog inputpin.
void HIH4030Humidity::begin(int humidityPin)
{
  pinMode(humidityPin, INPUT);
  _humidityPin=humidityPin;
   setTemperature(20) ;
}


/// setTemperature: set the room temperature (used in humidity calculation)(default value: 20° Celsius).
void HIH4030Humidity::setTemperature(int temperature)
{
  _temperature=temperature;
  _maxVoltage = ( 3.27 -  (0.006706 * _temperature ));
}

/// Returns the humidity as a raw value: ADC output: 0 -> 1023.
int HIH4030Humidity::getHumidityRaw()
{
  return (analogRead(_humidityPin));
}

/// Returns the relative humidity percentage. Should be between 0% and 100%
float HIH4030Humidity::getHumidityPercentage()
{
  /// @todo Check the output for invalid data: over or under 100 (how to report?)
  return ( (((float(getHumidityRaw())/1023)*5) - ZEROPERCENTVOLTAGE )) / _maxVoltage * 100;
}
