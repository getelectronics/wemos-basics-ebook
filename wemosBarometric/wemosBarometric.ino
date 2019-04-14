//The example requires the https://github.com/wemos/LOLIN_HP303B_Library

#include <LOLIN_HP303B.h>

// HP303B Opject
LOLIN_HP303B HP303BPressureSensor;


void setup()
{
  Serial.begin(115200);
  while (!Serial);
  HP303BPressureSensor.begin();
  Serial.println("Init complete!");
}


void loop()
{
  int32_t temperature;
  int32_t pressure;
  int16_t oversampling = 7;
  int16_t ret;
  Serial.println();
  
  ret = HP303BPressureSensor.measureTempOnce(temperature, oversampling);

  if (ret != 0)
  {
    //Something went wrong.
    //Look at the library code for more information about return codes
    Serial.print("FAIL! ret = ");
    Serial.println(ret);
  }
  else
  {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" degrees of Celsius");
  }

  //Pressure measurement behaves like temperature measurement
  //ret = HP303BPressureSensor.measurePressureOnce(pressure);
  ret = HP303BPressureSensor.measurePressureOnce(pressure, oversampling);
  if (ret != 0)
  {
    //Something went wrong.
    //Look at the library code for more information about return codes
    Serial.print("FAIL! ret = ");
    Serial.println(ret);
  }
  else
  {
    Serial.print("Pressure: ");
    Serial.print(pressure);
    Serial.println(" Pascal");
  }

  //Wait some time
  delay(500);
}


