#include <SPI.h>
#include <XPT2046_Touchscreen.h>

#define TS_CS D3 //for D1 mini or TFT I2C Connector Shield (V1.1.0 or later)
// #define TS_CS  12 //for D32 Pro

XPT2046_Touchscreen ts(TS_CS);

void setup()
{
  Serial.begin(115200);
  ts.begin();
  ts.setRotation(1);
  while (!Serial && (millis() <= 1000))
    ;
}

void loop()
{
  if (ts.touched())
  {
    TS_Point p = ts.getPoint();
    Serial.print("Pressure = ");
    Serial.print(p.z);
    Serial.print(", x = ");
    Serial.print(p.x);
    Serial.print(", y = ");
    Serial.print(p.y);
    delay(30);
    Serial.println();
  }
}

