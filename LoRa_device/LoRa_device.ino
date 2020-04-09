#include "heltec.h"
#include "Node.hpp"
#define BAND    433E6  //you can set band here directly,e.g. 868E6,915E6

  
byte type_message=0x0;      
char id='1';             
byte msgCount = 0;            
long lastSendTime = 0;        
int interval = 2000;

Node n;
          
void setup()
{
  
  Heltec.begin(true , true , true , true, BAND );
  LoRa.onReceive(onReceive);
  LoRa.receive();
  Serial.println("Heltec.LoRa init succeeded.");
  n.setID(id);
}

void loop()
{
  
  
  if (millis() - lastSendTime > interval)
  {
    n.setMessage_Type(type_message);
    n.setPacket_Nuber(msgCount);
    sendMessage(n);
    Serial.println("Sending ");
    Serial.println(id);
    lastSendTime = millis();            
    interval = random(2000) + 1000;     
    LoRa.receive();                     
  }
}

void sendMessage(Node sender)
{
  LoRa.beginPacket();                   // start packet
  LoRa.write(sender.getMessage_Type());
  LoRa.write(sender.getPacket_Number());
  LoRa.print(sender.getID());                 
  LoRa.endPacket();                     
  msgCount++;                           
}

void onReceive(int packetSize)
{
  if (packetSize == 0) return;          // if there's no packet, return
           
  byte tm = LoRa.read();     
  byte counter = LoRa.read();    

  //String incoming = "";                 
  char incoming;

  incoming =LoRa.read();      

  n.Unpack(tm,counter,incoming,LoRa.packetRssi());
  

  Serial.println("hello received!");
  Serial.println(incoming);
  Serial.println("RSSI: " + String(LoRa.packetRssi()));
  Serial.println("Snr: " + String(LoRa.packetSnr()));

  if (counter==10)
  {
    Serial.println("discard...");
    n.Discard();
    n.GenerateDocument();
    n.Clear_List();
  }
  //Serial.println();
}
