/*
********************************************
14CORE ULTRASONIC DISTANCE SENSOR CODE TEST
********************************************
*/

#include "UbidotsMicroESP8266.h"

#define TOKEN  "BBFF-3FvNPYjLVeapqTfSMPiU89kamUYtFA"  // Put here your Ubidots TOKEN
#define ID_1 "5a883e41642ab636847dc421" // Put your variable ID here//
//#define ID_2 "Your_variable_ID_here" // Put your variable ID here
#define WIFISSID "lays" // Put here your Wi-Fi SSID
#define PASSWORD "Rajhans@1" // Put here your Wi-Fi password



#define TRIGGER D1
#define ECHO    D2
Ubidots client(TOKEN);
// NodeMCU Pin D1 > TRIGGER | Pin D2 > ECHO

void setup() {
  
  Serial.begin (115200);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUILTIN_LED, OUTPUT);

   client.wifiConnection(WIFISSID, PASSWORD);
}
int distance()
 {float duration, distance;
  digitalWrite(TRIGGER, LOW);  
  delayMicroseconds(2); 
  
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(12); 
  
  digitalWrite(TRIGGER, LOW);
  //yield();
  duration = pulseIn(ECHO, HIGH);
  //yield();
  distance = (duration/58.2);
  
  Serial.print("Centimeter:\t");
  Serial.println(distance);

  client.add(ID_1, distance);
    //client.add(ID_2, value2);
    client.sendAll();
  delay(10);
  return (distance);
  }

void loop() {
  
 distance();
}
