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
  vector<float> range_tol{
    0.1182,
    0.155,
    0.1593,
    0.0882,
    0.1265,
    0.1003,
    0.1511,
    0.0471
    };
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
  vector<uint8_t> getFake_Nodes()const;
  vector<float> getRange_Tol()const;
  /*Setters*/
  void setID(uint8_t id);
  void setMessage_Type(uint8_t messaget);
  void setPacket_Number(uint8_t packet_n);
  void Message(uint32_t msj);
  void setRange_Tol(vector<float> new_range);
  /*Methods*/
  void Pack();
  uint8_t Unpack(uint32_t received,float RSSI);
  void Discard();
  void GenerateDocument();
  void Clear_List();
};
#endif
