#include <Adafruit_NeoPixel.h>

#define PIN            D2

long randomRed;
long randomGreen;
long randomBlue;
// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(1, PIN, NEO_GRB + NEO_KHZ800);

void setup() 
{
  pixels.begin(); // This initializes the NeoPixel library.
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() 
{
  // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
  randomRed = random(0, 4);
  randomGreen = random(0, 4);
  randomBlue = random(0, 4);
  pixels.setPixelColor(0, pixels.Color(randomRed, randomGreen, randomBlue)); // red
  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(1000); // Delay for a period of time (in milliseconds).
}
