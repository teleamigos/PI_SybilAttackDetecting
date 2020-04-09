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
  char ID;
  uint8_t message_type=0x00;
  uint8_t packet_number;
  //uint32_t message=0x00;
  vector<char> Neighboors;
  vector<float> RSSI_Neighboors;
  vector<char> Fake_nodes;
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
  Node(char id,uint8_t packet_n);
  Node(char id,uint8_t type_message,uint8_t packet_n);
  Node(const Node &nodo);
  /*Getters*/
  char getID()const;
  uint8_t getMessate_Type()const;
  uint8_t getPacket_Number()const;
  vector<char> getNeighboors()const;
  vector<float> getRSSI_Neighboors()const;
  vector<char> getFake_Nodes()const;
  vector<float> getRange_Tol()const;
  /*Setters*/
  void setID(char id);
  void setMessage_Type(uint8_t messaget);
  void setPacket_Number(uint8_t packet_n);
  void setRange_Tol(vector<float> new_range);
  /*Methods*/
  //void Pack();
  uint8_t Unpack(uint8_t type_message,uint8_t msg_counter,char id,float RSSI);
  void Discard();
  void GenerateDocument();
  void Clear_List();
};
#endif
