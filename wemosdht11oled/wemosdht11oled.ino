//Various libraries required - you can install these via the library manager, here are links to them 

//https://github.com/adafruit/DHT-sensor-library 
//https://github.com/adafruit/Adafruit_Sensor 
//https://github.com/sparkfun/SparkFun_Micro_OLED_Arduino_Library   

#include "DHT.h"
#include <Wire.h>  // Include Wire if you're using I2C
#include <SFE_MicroOLED.h>  // Include the SFE_MicroOLED library

#define DHTPIN D4     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
#define PIN_RESET 255  //
#define DC_JUMPER 0  // I2C Addres: 0 - 0x3C, 1 - 0x3D

MicroOLED oled(PIN_RESET, DC_JUMPER); // Example I2C declaration
DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
  Serial.begin(9600);
  dht.begin();
  oled.begin();
  oled.clear(ALL);  // Clear the display's memory (gets rid of artifacts)
  oled.display();  
}

void loop() 
{
  // Wait a few seconds between measurements.
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) 
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  oled.clear(PAGE); 
  oled.setFontType(0); // set font type 0, please see declaration in SFE_MicroOLED.cpp
  oled.setCursor(1, 3);
  oled.print("Humidity: ");
  oled.setCursor(1, 12);
  oled.print(h);
  oled.print(" %\t");
  oled.setCursor(1, 21);
  oled.print("Temp :");
  oled.setCursor(1, 30);
  oled.print(t);
  oled.print(" *C ");
  oled.display();  
}

