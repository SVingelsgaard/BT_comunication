//11.05 kjøres denne på nano. sender signal hit.
//fungerer perfekt.

#include <SoftwareSerial.h>
SoftwareSerial BTSerial(11, 12);

//variables
int data;
void setup() {
  BTSerial.begin(38400);
  Serial.begin(115200);
}

void loop() {
  //BTSerial.write('test');

  if (BTSerial.available() > 0) {
    data = int(BTSerial.read());

  }

  static unsigned long timer = 0;
  unsigned long interval = 10; // send 100 samples/second
  if (millis() - timer >= interval)
  {
    timer = millis();
    Serial.println(data);
  }
}
