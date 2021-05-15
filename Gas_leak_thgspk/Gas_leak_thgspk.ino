
#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;
const char* ssid = "vivo1718"; //Your Network SSID
const char* password = "tanuj123";
int moto = D4;
int relay = D3;
int smokeA0 = A0;
// Your threshold value
int sensorThres = 450;
WiFiClient client;
unsigned long myChannelNumber = 990521; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "VHZ4SV6OF4QV2UMW"; //Your Write API Key


void setup()
{
  delay(10);

// Connect to WiFi network

WiFi.begin(ssid, password);

ThingSpeak.begin(client);
  pinMode(moto, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);

  ThingSpeak.writeField(myChannelNumber, 1,analogSensor, myWriteAPIKey); 
  delay(200);
  
  if (analogSensor > sensorThres)
  {
    digitalWrite(moto, HIGH);
    digitalWrite(relay, LOW);

    delay(100);
  }
 
  delay(100);
  
}
