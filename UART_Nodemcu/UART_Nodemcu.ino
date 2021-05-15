#include<SoftwareSerial.h>
SoftwareSerial s(D6,D5);
int data;
int led=D3;
void setup() {
s.begin(115200);
pinMode(led,OUTPUT);
Serial.begin(115200);
}

void loop() {
if(s.available()>0)
{
  data=s.read();
    
if(data==HIGH)
 {
  digitalWrite(led,LOW);
   Serial.println(" no obstacle");
  }
else
  {
    digitalWrite(led,HIGH);
     Serial.println("obstacle");
  }
  
}
}
