// HIH4030Humidity.cpp - Arduino library for retrieving data from the analog GP2Y0A21YK IR Humidity sensor
// Copyright 2012 Jeroen Doggen (jeroendoggen@gmail.com)
// For more information: variable declaration, changelog,... see HIH4030Humidity.h
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

/// <summary>
/// Constructor
/// </summary>
HIH4030Humidity::HIH4030Humidity()
{
}

/// <summary>
/// Begin function to set pins: humidityPin = A0.
/// </summary>
void
HIH4030Humidity::begin()
{                            // default value: 20° Celcius
  begin (A0);
}

/// <summary>
/// Begin variables
/// - int _humidityPin: number indicating the humidity to an object: ANALOG IN
/// When you use begin() without variables standard values are loaded: A0
/// </summary>
void HIH4030Humidity::begin(int humidityPin)
{
  pinMode(humidityPin, INPUT);
  _humidityPin=humidityPin;
   setTemperature(20) ;
}

/// <summary>
/// setTemperature(int temperature): Sets the temperature.
/// </summary>
void HIH4030Humidity::setTemperature(int temperature)
{
  _temperature=temperature;
  _maxVoltage = ( 3.27 -  (0.006706 * _temperature ));
}

/// <summary>
/// getHumidityRaw(): Returns the humidity as a raw value: ADC output: 0 -> 1023
/// </summary>
int HIH4030Humidity::getHumidityRaw()
{
  return (analogRead(_humidityPin));
}

/// <summary>
/// getHumidityPercentage(): Returns the humidity percentage
/// </summary>
float HIH4030Humidity::getHumidityPercentage()
{
  return ( (((float(getHumidityRaw())/1023)*5) - ZEROPERCENTVOLTAGE )) / _maxVoltage * 100;
}

