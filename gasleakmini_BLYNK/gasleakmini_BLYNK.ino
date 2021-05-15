/* mq-2 with buzzer
and led */
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
SimpleTimer timer;
#define BLYNK_READ
char auth[]="R2KsHFTFOV6wMye9uSUIry2hjmMT2rvg";
char ssid[]="iPhone";
char pass[]="Vijay@1244";
int redLed = D2   ;
int greenLed = D1;
int buzzer = D3;
int smokeA0 = A0;
int relay_Pin=D4;
// Your threshold value
int sensorThre = 340;
int analogSensor;
void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  pinMode(relay_Pin, OUTPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  digitalWrite(relay_Pin,LOW);
  timer.setInterval(20000,Blynk_email);
  timer.setInterval(100,run_again);
}
void Blynk_email()
{
  Blynk.virtualWrite(V0,100-analogSensor);
  Blynk.email("tanuj.veera@gmail.com","Subject:ESP8266","Gas Leak! Please Turn off Gas");
}
void run_again()
{
  int analogSensor = analogRead(smokeA0);
  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThre)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(relay_Pin,HIGH);
    tone(buzzer, 1000, 200);
    delay(1000); 
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    noTone(buzzer);
    digitalWrite(relay_Pin,LOW);
  }
  delay(100);
}
  
void loop() {
    Blynk.run();
    timer.run();
}  
