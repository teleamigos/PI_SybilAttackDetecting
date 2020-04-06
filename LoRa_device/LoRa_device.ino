#include "heltec.h"
#include "Node.hpp"

#define BAND 433E6

uint8_t ID=0x01;
uint8_t C=0x0;
uint8_t tm=0x00;
uint32_t message;

Node node;

void setup() {
  //LoRa init
  Heltec.begin(true,true,true,true,BAND);
  LoRa.setSpreadingFactor(7);
  LoRa.onReceive(onReceive);
  LoRa.receive();
  //Node init
  node.setID(ID);
  
}


void loop() {

  while (C<=0x10){
    //Empaqueta
    node.setPacket_Number(C);
    node.setMessage_Type(tm);
    node.Pack();
    message=node.getMessage();
    //Envia
    
    //Recibe
  }

  c=0x00;
  
}

void sendMessage(uint32_t outgoing)
{
  LoRa.beginPacket();
  LoRa.write(outgoing);
  LoRa.print(outgoing);
  LoRa.endPacket();

  C++;
}

void onReceive(int packetsize)
{
  uint8_t pac_n;
  if(packetsize==0)
  {
    return;
  }
  else{
    uint32_t incoming = LoRa.read();
    pac_n=this_node.Unpack();
    Serial.println("Message received");
  }
  if(pac_n>=10)
  {
    node.Discard();
    node.GenerateDocument();
    node.Clear_List();
  }
  
}

