#include <HIH4030Humidity.h>

HIH4030Humidity Humidity;
float humidity;

void setup()
{
  Serial.begin(115200);
  Humidity.begin(A0);
}

void loop()
{
  humidity = Humidity.getHumidityPercentage();
  Serial.print("Humidity: ");
  Serial.print(humidity,2);
  Serial.println(" %"); 
  delay(500); //make it readable
}