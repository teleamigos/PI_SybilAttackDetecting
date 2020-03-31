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
public:
  /*Constructors*/
  Node()=default;
  Node(uint8_t id);
  Node(const Node &nodo);
  /*Getters*/
  uint8_t GetID()const;
  /*Setters*/
  void SetID(uint8_t id);
  /*Overt*/

  /*Others*/
  void Print()const;
};
#endif
