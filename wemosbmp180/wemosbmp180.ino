//We had a previous code example for this module, this was tested and worked with the shield perfectly. As you can see the Adafruit library is required

#include <Wire.h>
#include <Adafruit_BMP085.h>

Adafruit_BMP085 bmp;

void setup() 
{
  Serial.begin(9600);
  //Wire.begin (4, 5);
  if (!bmp.begin()) 
  {
    Serial.println("Could not find BMP180 or BMP085 sensor at 0x77");
    while (1) {}
  }
}

void loop() 
{
  Serial.print("Temperature = ");
  Serial.print(bmp.readTemperature());
  Serial.println(" Celsius");

  Serial.print("Pressure = ");
  Serial.print(bmp.readPressure());
  Serial.println(" Pascal");


  Serial.println();
  delay(5000);
}


