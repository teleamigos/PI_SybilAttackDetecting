#include "heltec.h"
#include "Node.hpp"
#define BAND    433E6  //you can set band here directly,e.g. 868E6,915E6

  
byte type_message=0x0;      
char id='1';             
byte msgCount = 0;            
long lastSendTime = 0;        
int interval = 4000;
char ID[10];
int rssi[10];
uint8_t type[10];
int i;
vector<char> fakes,lista;

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
  int j;
  if (i>=10)
  {
    for(j=0;j<10;j++)
    {
      //n.Unpack(type[j],msgCount,ID[j],rssi[j]);
      n.Unpack(ID[j],rssi[j]);
    }
    Serial.println("unpacked succesful");
    lista=n.makeList();
    //discard(n,lista);
    Serial.println("tam"+String(lista.size()));
    boolean ans=n.Discard(lista);
    if(ans){
      fakes=n.getFake_Nodes();
      Serial.println("tam nodes"+String(fakes.size()));
      for(j=0;j<fakes.size();j++)
      {
        Serial.println("detected");
        Serial.println(fakes.at(j));
        
      }
    }
    else{
      Serial.println("fake nodes not detected!"); 
    }
    //n.Generate();
    n.clear();
    i=0;
  }
  if (millis() - lastSendTime > interval)
  {
    n.setMessage_Type(type_message);
    n.setPacket_Number(msgCount);
    sendMessage(n);

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
  Serial.println("Sending ");
  Serial.println(id);                     
  msgCount++;                           
}

void discard(Node n,vector<char> list)
{
  int i,j;
  int rssi_aux;
  float c;
  vector<char> neigh;
  vector<int> r;
  vector<float> rssi_prom;
  neigh=n.getNeighboors();
  r=n.getRSSI_Neighboors();
  for(i=0;i<list.size();i++)
  {
    rssi_aux=0;
    c=0;
    for(j=0;j<neigh.size();j++)
    {
      if(list.at(i)==neigh.at(j))
      {
        rssi_aux+=r.at(j);
        c++;
      }
    }
    rssi_prom.push_back(rssi_aux/c);
  }
  
}

void onReceive(int packetSize)
{
 
  if (packetSize == 0) return;          // if there's no packet, return        
  uint8_t tm = LoRa.read();    
  uint8_t counter = LoRa.read();                     
  char incoming;
  incoming =LoRa.read();     
  int r=LoRa.packetRssi();
  Serial.println("hello received!");
  Serial.println(incoming);
  Serial.println("RSSI: " + String(LoRa.packetRssi()));
    rssi[i]=r;
    //n.Unpack(tm,counter,incoming,r);
    ID[i]=incoming;
    i++;
}