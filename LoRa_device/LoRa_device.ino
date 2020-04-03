
#include "heltec.h"
#include "Node.hpp"

#define BAND 433E6

int interval=2000;
long lastSendTime=0;
uint32_t message;

Node this_node;

void setup() {
  // put your setup code here, to run once:
  Heltec.begin(true,true,true,true,BAND);
  LoRa.setSpreadingFactor(7);
  LoRa.onReceive(onReceive);
  LoRa.receive();
  
  this_node.setID(0x03);
  this_node.Pack();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(millis()-lastSendTime>interval)
  {
    message=this_node.getMessage();
    sendMessage(message);
    lastSendTime=millis();
    interval=random(2000)+1000;
    LoRa.receive();
  }
  
}

void sendMessage(uint32_t outgoing)
{
  LoRa.beginPacket();
  LoRa.write(outgoing);
  LoRa.print(outgoing);  
  LoRa.endPacket();
}

void onReceive(int packetsize)
{
  if(packetsize==0) 
    {
      return;
    }
    else{
      uint32_t incoming = LoRa.read();
      this_node.Unpack();
      Serial.println("Message received");
    }
  
  
  
}
