//kjøres på mega 11.05. sender signal herifra til nano
//alt her fungerer som forventet
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(12, 13);

//variables
byte data;  // serial write sends bytes.
byte data1;
byte data2;

void setup()
{
  BTSerial.begin(38400);
  Serial.begin(115200);  // speed up the Serial baud rate
}

void loop()
{
  static unsigned long timer = 0;
  unsigned long interval = 10; // send 100 samples/second
  if (millis() - timer >= interval)
  {
    timer = millis();
    data += 1;
    BTSerial.write(data);
  }
}
