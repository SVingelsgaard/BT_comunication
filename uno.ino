//09.05 kjøres denne på nano. sender signal hit. 
//fungerer i en pulsbredde på ca 30% ved .8 Hz. aner ikke hvorfor.

#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11);

//variables
int data;
void setup() {
  BTSerial.begin(38400);
  Serial.begin(9600);
}

void loop() {
  //BTSerial.write('test');

  //if(BTSerial.available() > 0){
    data = BTSerial.read();
  //}
  Serial.println(data);
  
}
