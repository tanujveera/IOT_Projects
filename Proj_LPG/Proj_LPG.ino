#include <ESP8266WiFi.h>
const char *ssid =  "Galaxy-M20";     // Enter your WiFi Name
const char *pass =  "ac312124"; // Enter your WiFi Password
const int sensorPin= 2;
const int buzzer= 0;
int lpg;
void send_event(const char *event);
const char *host = "maker.ifttt.com";
const char *privateKey = "hUAAAz0AVvc6-NW1UmqWXXv6VQWmpiGFxx3sV5rnaM9";
WiFiClient client;
void setup() 
{
       Serial.begin(115200); 
       delay(10);
       pinMode(buzzer, OUTPUT);
       Serial.println("Connecting to ");
       Serial.println(ssid);
       WiFi.begin(ssid, pass); 
       while (WiFi.status() != WL_CONNECTED) 
     {
            delay(550);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");
 }
void loop() 
{
     lpg = !digitalRead(sensorPin);
     Serial.print("Air:");
     Serial.println(lpg);   
     if (lpg == 1)
     {
     digitalWrite(buzzer, HIGH);
     delay(1000); 
     digitalWrite(buzzer, LOW);
     send_event("LPG_event");                 
     }
}
void send_event(const char *event)
{
  Serial.print("Connecting to ");
  Serial.println(host);  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("Connection failed");
    return;
  }  
  // We now create a URI for the request
  String url = "/trigger/";
  url += event;
  url += "/with/key/";
  url += privateKey;  
  Serial.print("Requesting URL: ");
  Serial.println(url);  
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  while(client.connected())
  {
    if(client.available())
    {
      String line = client.readStringUntil('\r');
      Serial.print(line);
    } else {
      // No data yet, wait a bit
      delay(50);
    };
  }
  Serial.println();
  Serial.println("closing connection");
  client.stop();
}
