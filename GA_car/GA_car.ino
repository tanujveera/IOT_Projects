#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "DCqZVRoRbHcsl5k3jEKWAJlIZlrfucXO";
char ssid[] = "Mi A2";
char pass[] = "Android one";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}


BLYNK_WRITE(V5) // Button Widget writes to Virtual Pin V5 
{ 
  if (param.asInt() == 1)
    fwd();
  else
    st0p();     
}

BLYNK_WRITE(V6) // Button Widget writes to Virtual Pin V5 
{ 
  if (param.asInt() == 1)
    rev();
  else
    st0p();     
}

BLYNK_WRITE(V7) // Button Widget writes to Virtual Pin V5 
{ 
  if (param.asInt() == 1)
    lef();
  else
    st0p();     
}

BLYNK_WRITE(V8) // Button Widget writes to Virtual Pin V5 
{ 
  if (param.asInt() == 1)
    rih();
  else
    st0p();     
}


BLYNK_WRITE(V9) // Button Widget writes to Virtual Pin V5 
{ 
  if (param.asInt() == 1)
    st0p(); 
  else
    st0p();     
}



void loop()
{
  Blynk.run();
   
}  
