/*------------------------------------------------------------------------------
                          Class Node Definition
------------------------------------------------------------------------------*/
#ifndef Node_hpp
#define Node_hpp
#include <iostream>
#include <vector>
using namespace std;
class Node
{
private:
  uint8_t ID;
  uint8_t message_type=0x00;
  uint8_t packet_number;
  uint32_t message=0x00;
  vector<uint8_t> Neighboors;
  vector<float> RSSI_Neighboors;
  vector<uint8_t> Fake_nodes;
public:
  /*Constructors*/
  Node()=default;
  Node(uint8_t id,uint8_t packet_n);
  Node(uint8_t id,uint8_t messaget,uint8_t packet_n,uint32_t msj);
  Node(const Node &nodo);
  /*Getters*/
  uint8_t getID()const;
  uint8_t getMessate_Type()const;
  uint8_t getPacket_Number()const;
  uint32_t getMessage();
  vector<uint8_t> getNeighboors()const;
  vector<float> getRSSI_Neighboors()const;
  vector<float> getFake_Nodes()const;
  /*Setters*/
  void setID(uint8_t id);
  void setMessage_Type(uint8_t messaget);
  void setPacket_Number(uint8_t packet_n);
  void Message(uint32_t msj);
  /*Methods*/
  void Pack();
  uint8_t Unpack(uint32_t received,float RSSI);
  void Discard();
  void GenerateDocument();
  void Clear_List();
};
#endif
