#include "heltec.h"
#include "Node.hpp"
#include "Sybil.hpp"
#define BAND    433E6  //you can set band here directly,e.g. 868E6,915E6

  
byte type_message=0x0;      
char id='3';       
char id2='2';      
byte msgCount = 0;            
long lastSendTime = 0;        
int interval = 2000;
vector<Node> sybil;
Sybil sybil_nodes;
int tam;

Node n,n2;
          
void setup()
{
  
  Heltec.begin(true , true , true , true, BAND );
  LoRa.onReceive(onReceive);
  LoRa.receive();
  Serial.println("Heltec.LoRa init succeeded.");
  n.setID(id);
  n2.setID(id2);
  sybil.push_back(n);
  sybil.push_back(n2);
  tam=sybil.size();
  sybil_nodes.setSybilNodes(sybil);
  sybil_nodes.setN(tam);
}

void loop()
{
  Node sender;
  int i=0;
  if (millis() - lastSendTime > interval)
  {
    for(i=0;i<sybil_nodes.getN();i++)
    {
      sender=sybil_nodes.S_Pack(i,msgCount);
      sendMessage(sender);
    }
    
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
  Serial.println("RSSI: " + String(LoRa.packetRssi()));
  Serial.println("Snr: " + String(LoRa.packetSnr()));

  //Serial.println();
}
