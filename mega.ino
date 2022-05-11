//kjøres på mega 11.05. sender signal herifra til nano
//alt her fungerer som forventet
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(12, 13);

//variables
byte data;  // serial write sends bytes.
int pot;

void setup()
{
  BTSerial.begin(38400);
  Serial.begin(115200);  // speed up the Serial baud rate
}

void loop()
{
  //read pot

  static unsigned long timer = 0;
  unsigned long interval = 10; // send 100 samples/second
  if (millis() - timer >= interval)
  {
    timer = millis();
    pot = map(analogRead(A0), 0, 1023, 0, 100);
    data = pot;
    //communication

    Serial.println(data);

  }
  BTSerial.write(data);
}
