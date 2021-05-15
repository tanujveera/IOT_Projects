#include<SoftwareSerial.h>
SoftwareSerial s(0,1);
int a=3;
int data;
void setup() {
s.begin(115200); 
pinMode(a,INPUT);
  }
void loop() {
if(s.available()>0)
{
  data=digitalRead(a);
  s.write(data);
}
}
