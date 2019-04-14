//You need to install the following library for this example : https://github.com/claws/BH1750

#include <Wire.h>
#include <BH1750.h>


BH1750 lightMeter(0x23);

void setup(){

  Serial.begin(9600);

  // Initialize the I2C bus
  Wire.begin();

  if (lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)) 
  {
    Serial.println(F("BH1750 Advanced begin"));
  }
  else 
  {
    Serial.println(F("Error initialising BH1750"));
  }

}

void loop() 
{
  uint16_t lux = lightMeter.readLightLevel();
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lx");
  delay(1000);
}


