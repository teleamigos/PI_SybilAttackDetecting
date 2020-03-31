/*------------------------------------------------------------------------------
--------------------------Class node implementation.......----------------------
------------------------------------------------------------------------------*/
#include "Node.hpp"
/*Constructors*/
Node::Node(uint8_t id): ID(id)
{
  //Exceptions
}

Node::Node(const Node &nodo)
{
  this->ID=nodo.ID;
}
/*Getters*/
uint8_t Node::GetID()const
{
  return this->ID;
}
/*Setters*/
void Node::SetID(uint8_t id)
{
  this->ID=id;
}
/*Overt*/

/*Others*/
void Node::Print()const
{
  //Exceptions
}
