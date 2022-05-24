//kjøres på mega 11.05. sender signal herifra til nano
//alt her fungerer som forventet
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(12, 13);

//variables
byte data;
int data1;  // serial write sends bytes.
int data2;
int data3;
int data4;

int pot;
int datacount = 0;

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
    pot = map(analogRead(A0), 0, 1023, 0, 50);
    data1 = pot;
    data2 = pot + 64;
    data3 = pot + 128;
    data4 = pot + 192;
    
    //communication
    if (datacount == 0){
      data = data1;
    }else if (datacount == 1){
      data = data2;
    }else if (datacount == 2){
      data = data3;
    }else if (datacount == 3){
      data = data4;
    }

    datacount = datacount + 1;
    if (datacount > 3){
      datacount = 0;
    }
    Serial.print("1: ");
    Serial.println(data1);
    Serial.print("2: ");
    Serial.println(data2);
    Serial.print("3: ");
    Serial.println(data3);
    Serial.print("4: ");
    Serial.println(data4);
  
  }
  //data = 
  BTSerial.write(data);
  //Serial.println(data);
  
}
