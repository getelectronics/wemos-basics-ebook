//Very simple stuff here, we will output via the serial monitor.

const int PIR = D3;
int PIRState = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(PIR, INPUT);
}

void loop() 
{
  PIRState = digitalRead(PIR);

  if (PIRState == HIGH) 
  {
    Serial.write("INTRUDER DETECTED\n");
  } 
  else 
  {
    Serial.write("NOWT GOING ON\n");
  }
  delay(1000);
}


