#include "heltec.h"
#include "Node.hpp"
#define BAND    433E6  //you can set band here directly,e.g. 868E6,915E6

  
byte type_message;      
char id;             
byte msgCount = 0;            
long lastSendTime = 0;        
int interval = 2000;          
void setup()
{
  
  Heltec.begin(true , true , true , true, BAND );
  LoRa.onReceive(onReceive);
  LoRa.receive();
  Serial.println("Heltec.LoRa init succeeded.");
}

void loop()
{
  
  
  if (millis() - lastSendTime > interval)
  {
    id='1';
    sendMessage(id);
    Serial.println("Sending ");
    Serial.println(id);
    lastSendTime = millis();            
    interval = random(2000) + 1000;     
    LoRa.receive();                     
  }
}

void sendMessage(char outgoing)
{
  LoRa.beginPacket();                   // start packet
  LoRa.write(type_message);
  LoRa.write(msgCount);
  LoRa.print(outgoing);                 
  LoRa.endPacket();                     
  msgCount++;                           
}

void onReceive(int packetSize)
{
  if (packetSize == 0) return;          // if there's no packet, return

  // read packet header bytes:
  //int recipient = LoRa.read();          
  //byte sender = LoRa.read();            
  byte tm = LoRa.read();     
  byte counter = LoRa.read();    

  //String incoming = "";                 
 char incoming;

    incoming =LoRa.read();      

  Serial.println("hello received!");
  Serial.println(incoming);
  Serial.println("RSSI: " + String(LoRa.packetRssi()));
  Serial.println("Snr: " + String(LoRa.packetSnr()));


  // if message is for this device, or broadcast, print details:
  //Serial.println("Received from: 0x" + String(sender, HEX));
  //Serial.println("Sent to: 0x" + String(recipient, HEX));
  //Serial.println("Message ID: " + String(incomingMsgId));
  //Serial.println("Message length: " + String(incomingLength));
  //Serial.println("Message: " + incoming);

  //Serial.println();
}
