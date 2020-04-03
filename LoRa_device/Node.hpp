/*------------------------------------------------------------------------------
                          Class Node Definition
------------------------------------------------------------------------------*/
#ifndef Node_hpp
#define Node_hpp
#include <iostream>
using namespace std;
class Node
{
private:
  uint8_t ID;
  uint8_t message_type=0x00;
  uint32_t message=0x00;
  //vector<uint8_t> Neighboors;
  //vector<uint8_t> Fake_nodes;
public:
  /*Constructors*/
  Node()=default;
  Node(uint8_t id);
  Node(uint8_t id,uint8_t messaget,uint32_t msj);
  Node(const Node &nodo);
  /*Getters*/
  uint8_t getID()const;
  uint8_t getMessate_Type()const;
  uint32_t getMessage();
  /*Setters*/
  void setID(uint8_t id);
  void Messate_Type(uint8_t messaget);
  void Message(uint32_t msj);
  /*Methods*/
  void Pack();
  void Unpack();
  void Discard();
  void GenerateDocument();
};
#endif
