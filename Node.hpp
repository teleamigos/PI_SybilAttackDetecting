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
  vector<int> RSSI_Neighboors;
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
    uint8_t msgCounter;
    uint8_t last_msg;
    int N_detected=0;
public:
  /*Constructors*/
  Node()=default;
  Node(char id,uint8_t packet_n);
  Node(char id,uint8_t type_message,uint8_t packet_n);
  Node(const Node &nodo);
  /*Getters*/
  char getID()const;
  uint8_t getMessage_Type()const;
  uint8_t getPacket_Number()const;
  vector<char> getNeighboors()const;
  vector<int> getRSSI_Neighboors()const;
  vector<char> getFake_Nodes()const;
  vector<float> getRange_Tol()const;
  uint8_t getMsgCounter()const;
  uint8_t getLast_msg()const;
  int getN_detected()const;
  /*Setters*/
  void setID(char id);
  void setMessage_Type(uint8_t messaget);
  void setPacket_Number(uint8_t packet_n);
  void setRange_Tol(vector<float> new_range);
  void setMsg_Counter(uint8_t counter);
  void setLast_msg(uint8_t last);
  void setN_detected(int c);
  /*Methods*/
  //void Pack();
  void Unpack(char id,int RSSI);
  vector<char> makeList();
  bool Discard(vector<char> id_list);
  int LossPacket();
  void GenerateDocument();
  void Clear_List();
};
#endif
