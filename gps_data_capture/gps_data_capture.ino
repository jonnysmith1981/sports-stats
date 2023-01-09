#include "TinyGPS++.h"
TinyGPSPlus gps;

void loop()
{
  while (Serial1.available())
  {
    int c = Serial1.read();
    if (gps.encode(c))
    {
      String latString = "Latitude: " + String(gps.location.lat());
      String lonString = "Longitude: " + String(gps.location.lng());
      String satString = "Satellite count: " + String(gps.satellites.value());
      Serial.println(latString);
      Serial.println(lonString);
      Serial.println(satString);
    }
  }
}

void setup()
{
  Serial1.begin(9600);            //GPS on this port
  Serial.begin(115200);
  Serial.println();
  Serial.println("GPS_Echo_Hardware_Serial Starting");
}