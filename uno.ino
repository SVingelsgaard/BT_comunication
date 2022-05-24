//11.05 kjøres denne på nano. sender signal hit.
//fungerer perfekt.

#include <SoftwareSerial.h>
SoftwareSerial BTSerial(11, 12);

//variables
int data;
int data1;
int data2;
int data3;
int data4;

void setup() {
  BTSerial.begin(38400);
  Serial.begin(115200);
}

void loop() {
  //BTSerial.write('test');

  if (BTSerial.available() > 0) {
    data = int(BTSerial.read());
    if (data > 192){
      data4 = data;
    }else if(data > 128){
      data3 = data;
    }else if(data > 64){
      data2 = data;
    }else{
      data1 = data;
    }

  }
  //Serial.print("data1: ");
  Serial.print(" ");
  Serial.print(data1);
  //Serial.print("data2: ");
  Serial.print(" ");
  Serial.print(data2);
  //Serial.print("data3: ");
  Serial.print(" ");
  Serial.print(data3);
  //Serial.print("data4: ");
  Serial.print(" ");
  Serial.print(data4);
  
  static unsigned long timer = 0;
  unsigned long interval = 10; // send 100 samples/second
  if (millis() - timer >= interval)
  {
    timer = millis();
    //Serial.print("data1: ");
    
  }
}
