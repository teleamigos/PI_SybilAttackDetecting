#include "Heltec.h"
#include "Node.hpp"
#include "Sybil.hpp"

#define BAND 433E6

uint8_t C=0x0;
uint8_t id1,id2;
int n;
uint32_t message;
//vector<Node> sybil_nodes;
id1=0x02;
id2=0x03;
//Node fake1,fake2;
Sybil sybil_nodes;

void setup() {
  // put your setup code here, to run once:
  Heltec.begin(true,true,true,true,BAND);
  LoRa.setSpreadingFactor(7);
  LoRa.onReceive(onReceive);
  LoRa.receive();
  sybil_nodes.AddSybilNodes(id1,C);
  sybil_nodes.AddSybilNodes(id2,C);
}

void loop() {
  // put your main code here, to run repeatedly:
  n=sybil_nodes.getN();
  int i;
  while(C<=0x10)
  {
    for(i=0;i<n;i++)
    {
      message=sybil_nodes.S_Pack(i,C);
      SendMessage(message);
    }
    LoRa.receive();
  }

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
}

