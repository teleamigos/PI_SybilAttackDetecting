/*------------------------------------------------------------------------------
--------------------------Class node implementation.......----------------------
------------------------------------------------------------------------------*/
#include "Node.hpp"
/*Constructors*/
Node::Node(uint8_t id, uint8_t mtype): ID(id), messagetype(mtype)
{
  //Exceptions
}

Node::Node(const Node &nodo)
{
  this->ID=nodo.ID;
  this->messagetype=nodo.messagetype;
}
/*Getters*/
uint8_t Node::GetID()const
{
  return this->ID;
}
uint8_t Node::GetMessageType()const
{
  return this->messagetype;
}
/*Setters*/
void Node::SetID(uint8_t id)
{
  this->ID=id;
}
void Node::SetMessageType(uint8_t mtype)
{
  this->messagetype=mtype;
}
/*Overt*/

/*Others*/
void Node::Print()const
{
  //Exceptions
}
