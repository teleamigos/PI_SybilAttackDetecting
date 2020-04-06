/*------------------------------------------------------------------------------
                          Class Node Implementation
------------------------------------------------------------------------------*/
#include "Node.hpp"
/*Constructors*/
Node::Node(uint8_t id,uint8_t packet_n):ID(id),packet_number(packet_n)
{
        //Exceptions
}
Node::Node(uint8_t id,uint8_t messaget,uint8_t packet_n ,uint32_t msj):ID(id),message_type(messaget),
      packet_number(packet_n),message(msj)
{
          //Exceptions
}

Node::Node(const Node &nodo)
{
  this->ID=nodo.ID;
  this->message_type=nodo.message_type;
  this->packet_number=nodo.packet_number;
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
uint8_t Node::getPacket_Number()const
{
  return this->packet_number;
}
uint32_t Node::getMessage()
{
  return this->message;
}
vector<uint8_t> Node::getNeighboors()const
{
  return this->Neighboors;
}
vector<float> Node::getRSSI_Neighboors()const
{
  return this->RSSI_Neighboors;
}
/*Setters*/
void Node::setID(uint8_t id)
{
  this->ID=id;
}
void Node::setMessage_Type(uint8_t messaget)
{
  this->message_type=messaget;
}
void Node::setPacket_Number(uint8_t packet_n)
{
  this->packet_number=packet_n;
}
void Node::Message(uint32_t msj)
{
  this->message=msj;
}
/*Methods*/
void Node::Pack()
{
  if(this->message_type==0x2)
  {
    this->message=(this->message_type<<24)+(this->packet_number<<16)+(this->ID<<8);
  }
}
uint8_t Node::Unpack(uint32_t received,float RSSI)
{
    uint8_t type = (received >> 24);
    uint8_t id,c;
    if(type ==0x2)
    {
       c=(received>>16);
       id=(received>>8);
       this->Neighboors.push_back(id);
       this->RSSI_Neighboors.push_back(RSSI);
    }
    retunr c;
}
void Node::Discard()
{
  //In order to discard fake nodes, this method compare a RSSI received with
  // a RSSI standar for many distances.

}
void Node::GenerateDocument()
{
  //
}
