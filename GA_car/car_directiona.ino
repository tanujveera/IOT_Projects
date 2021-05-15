int p1 =16; //D0 // left
int m1 =5; //D1
int p2 =4; //D2  //right
int m2 =0;  //D3

void fwd()
{
    // forward
digitalWrite(p1,HIGH);
digitalWrite(m1,LOW);
digitalWrite(p2,HIGH);
digitalWrite(m2,LOW);
}

void rev()
{
 // reverse
digitalWrite(m1,HIGH);
digitalWrite(p1,LOW);
digitalWrite(m2,HIGH);
digitalWrite(p2,LOW); 
}

void rih()
{
 // right
digitalWrite(p1,LOW);
digitalWrite(m1,HIGH);
digitalWrite(p2,HIGH);
digitalWrite(m2,LOW); 
}

void lef()
{
  // left
digitalWrite(p1,HIGH);
digitalWrite(m1,LOW);
digitalWrite(p2,LOW);
digitalWrite(m2,HIGH);
}

void st0p()
{
digitalWrite(p1,HIGH);
digitalWrite(m1,HIGH);
digitalWrite(p2,HIGH);
digitalWrite(m2,HIGH); 
}
