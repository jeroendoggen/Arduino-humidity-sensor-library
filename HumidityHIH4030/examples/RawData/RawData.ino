#include "HumidityHIH4030.h"

HumidityHIH4030 Humidity;
int humidity;

void setup()
{
  Serial.begin(115200);
  Humidity.begin(A0);
}

void loop()
{
  humidity = Humidity.getHumidityRaw();
  Serial.print("ADC Raw: ");
  Serial.println(humidity);
  delay(500); //make it readable
}