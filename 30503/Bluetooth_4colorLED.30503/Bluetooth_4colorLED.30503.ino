#include <SoftwareSerial.h>
SoftwareSerial btSerial = SoftwareSerial(9,10);

void setup() {
  //Serial.begin(9600);
  btSerial.begin(9600);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
}

void loop() {
  if (btSerial.available() > 0) {
    char sData = btSerial.read();
    if(sData == 'r')
    {
      digitalWrite(7,LOW);
      digitalWrite(6,LOW);
      digitalWrite(5,LOW);
      digitalWrite(4,HIGH);
    }
    else if(sData == 'y')
    {
      digitalWrite(7,LOW);
      digitalWrite(6,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(4,LOW);
    }
    else if(sData == 'g')
    {
      digitalWrite(7,LOW);
      digitalWrite(6,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(4,LOW);
    }
    else if(sData == 'b')
    {
      digitalWrite(7,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(5,LOW);
      digitalWrite(4,LOW);
    }else if(sData == 'o')
    {
      digitalWrite(7,LOW);
      digitalWrite(6,LOW);
      digitalWrite(5,LOW);
      digitalWrite(4,LOW);
    }c:\Users\user\Downloads\Adafruit-Motor-Shield-library-master\Adafruit-Motor-Shield-library-master\README.txt
 

  }




}
