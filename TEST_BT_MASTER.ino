
//servos
#include <Servo.h>
Servo M1;
Servo M2;

//BT communication
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10,11);

//variablkes
int data;

void setup() {
  BTSerial.begin(38400);
  M1.attach(3);
  //M2.attach(3);

}

void loop() {
  if(BTSerial.available() > 0){
    data = BTSerial.read();
  }
  M1.write(data);
    
  //M2.write(data);
}
