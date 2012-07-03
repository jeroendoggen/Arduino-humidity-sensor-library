#include <HIH4030Humidity.h>

HIH4030Humidity Humidity;
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