/*
  Detecting a Sybil Attack by Jorge Orlando Gonzalez Guzman
*/
#ifndef Node_hpp
#define Node_hpp
/*------------------------------------------------------------------------------
--------------------------Class node definition---------------------------------
------------------------------------------------------------------------------*/

/*

*/

#include <iostream>

using namespace std;



class Node
{
private:
  uint8_t ID;
  uint8_t messagetype=0x00;
public:
  /*Constructors*/
  Node()=default;
  Node(uint8_t id, uint8_t mtype);
  Node(const Node &nodo);
  /*Getters*/
  uint8_t GetID()const;
  uint8_t GetMessageType()const;
  /*Setters*/
  void SetID(uint8_t id);
  void SetMessageType(uint8_t mtype);
  /*Overt*/

  /*Others*/
  void Print()const;
};
#endif
