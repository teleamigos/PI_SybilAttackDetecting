 /*------------------------------------------------------------------------------
                          Class Node Definition
------------------------------------------------------------------------------*/
#ifndef Node_hpp
#define Node_hpp

#include "Documentable.hpp"
#include "sha256.hpp"
#include "PoW.hpp"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
class Node : public Documentable,public SHA256,public PoW
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
    string archivo="sybil_report.txt";
    string hash;
    //std::ofstream output;
public:
  /*Constructors*/
  Node();
  explicit Node(char id,uint8_t packet_n);
  explicit Node(char id,uint8_t type_message,uint8_t packet_n);
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
  virtual void GenerateDocument()override;
  void Clear_List();
  virtual string GenerateTarget(int difficulty)override;
  virtual string packto_hash(char ID,string timestamp,string nonce)override;
  virtual string proofOfWork(int difficulty)override;
};
#endif
