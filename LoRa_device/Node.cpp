/*------------------------------------------------------------------------------
                          Class Node Implementation
------------------------------------------------------------------------------*/
#include "Node.hpp"
/*Constructors*/
Node::Node(uint8_t id):ID(id)
{
        //Exceptions
}
Node::Node(uint8_t id,uint8_t messaget, uint32_t msj):ID(id),message_type(messaget),
      message(msj)
{
          //Exceptions
}

Node::Node(const Node &nodo)
{
  this->ID=nodo.ID;
  this->message_type=nodo.message_type;
  this->message=nodo.message;
}

/*Getters*/
uint8_t Node::getID()const
{
  return this->ID;
}
uint8_t Node::getMessate_Type()const
{
    return this->message_type;
}
uint32_t Node::getMessage()
{
  return this->message;
}
/*Setters*/
void Node::setID(uint8_t id)
{
  this->ID=id;
}
void Node::Messate_Type(uint8_t messaget)
{
  this->message_type=messaget;
}
void Node::Message(uint32_t msj)
{
  this->message=msj;
}
/*Methods*/
void Node::Pack()
{
  if(this->message_type==0x00)
  {
    this->message=(this->message_type<<8)+this->ID;
  }
}
//void Unpack();
//void Discard();
//void GenerateDocument();
