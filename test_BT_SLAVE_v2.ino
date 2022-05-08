#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11);

//variables
int data;
void setup() {
  BTSerial.begin(38400);
}

void loop() {
  if (data < 180){
    data = data + .1;
  }else{
    data = 0;
  }
  BTSerial.write(data);
 delay(1);

}
