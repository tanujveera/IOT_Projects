void setup() {
  // put your setup code here, to run once:
pinMode(D4,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
while(Serial.available())
{
  char c= Serial.read();
  if(c=='0')
  {
    Serial.print("IN LO");
  digitalWrite(D4,HIGH);
  
  }
  
  else if(c == '1')
  {Serial.print("in h");
  digitalWrite(D4,LOW);
  }
}
}
