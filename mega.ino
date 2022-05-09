//kjøres på mega 09.05. sender signal herifra til nano
//alt her fungerer som forventet

#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11);

//variables
int data;
int pot;

void setup() {
  BTSerial.begin(38400);
  Serial.begin(9600);
}

void loop() {
  //read pot
  pot = map(analogRead(A0),0,1023,0,100);
  data = pot;
  BTSerial.write(data);
  Serial.println(data);
}
