//OLED library required - you can install this via the library manager, here are links to them
//https://github.com/sparkfun/SparkFun_Micro_OLED_Arduino_Library   

#include <ESP8266WiFi.h>
#include <Wire.h>
#include <SFE_MicroOLED.h>
#include <ArduinoJson.h>

const char* ssid = "iainhendry";
const char* pass = "iain061271";
#define PIN_RESET 255 //
#define DC_JUMPER 0 // I2C Addres: 0 - 0x3C, 1 - 0x3D
String id;
String value;
String json;

MicroOLED oled(PIN_RESET, DC_JUMPER); // I2C Example

WiFiClient client;

// delay between updates
const unsigned long postingInterval = 60L * 1000L;
unsigned long lastConnectionTime = 0;

void setup()
{
delay(100);
Serial.begin(115200);
Serial.println();
Serial.println();
Serial.print("Connecting to ");
Serial.println(ssid);
WiFi.begin(ssid, pass);
while (WiFi.status() != WL_CONNECTED)
{
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());

Serial.print("Connecting to ");

oled.begin();
oled.clear(ALL);
oled.setCursor(0,0);
oled.display();
oled.clear(PAGE);
oled.clear(ALL);
oled.print("Bitcoin price");
oled.setCursor(0,1);
oled.print("loading..");
oled.display(); // Display what's in the buffer (splashscreen)
delay(50);

}

int check_connect = 0;

void httpRequest()
{
client.stop();

// if there's a successful connection:
if (client.connect("api.coindesk.com", 80))
{
Serial.println("connecting...");
client.println("GET /v1/bpi/currentprice.json HTTP/1.1");
client.println("Host: api.coindesk.com");
client.println("User-Agent: ESP8266/1.1");
client.println("Connection: close");
client.println();
lastConnectionTime = millis();
}
else
{
// if you couldn't make a connection:
Serial.println("connection failed");
}
}

void loop()
{
int cnt;

if (cnt++ == 10000)
{
cnt = 0;
if (check_connect++ == 50)
{
check_connect = 0;
if (WiFi.status() != WL_CONNECTED)
{
}
}
}

if (millis() - lastConnectionTime > postingInterval)
{
httpRequest();
unsigned int i = 0; //timeout counter
int n = 1; // char counter
char json[500] ="{";

while (!client.find("\"USD\":{")){}

while (i<20000)
{
if (client.available())
{
char c = client.read();
json[n]=c;
if (c=='}') break;
n++;
i=0;
}
i++;
}

StaticJsonBuffer<500> jsonBuffer;
JsonObject& root = jsonBuffer.parseObject(json);

String newjson = root["code"];
String value = root["rate"];
id = newjson.substring(9,12);

// value = newjson.substring(41,51);
oled.display();
oled.clear(PAGE); // Clear the display's internal memory
oled.clear(ALL); // Clear the library's display buffer
oled.setCursor(0,1);
oled.print(value);
oled.display();

id="";
value="";
}
}


