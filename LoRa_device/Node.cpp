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
vector<uint8_t> Node::getFake_Nodes()const
{
  return this->Fake_nodes;
}
vector<float> Node::getRange_Tol()const
{
  return this->range_tol;
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
void Node::setRange_Tol(vector<float>  new_range)
{
  //
}
/*Methods*/
void Node::Pack()
{
  if(this->message_type==0x0)
  {
    this->message=(this->message_type<<24)+(this->packet_number<<16)+(this->ID<<8);
  }
}
uint8_t Node::Unpack(uint32_t received,float RSSI)
{
    uint8_t type = (received >> 24);
    uint8_t id,c;
    if(type ==0x0)
    {
       c=(received>>16);
       id=(received>>8);
       this->Neighboors.push_back(id);
       this->RSSI_Neighboors.push_back(RSSI);
    }
    return c;
}
void Node::Discard()
{
  //In order to discard fake nodes, this method compare a RSSI received with
  // a RSSI standar for many distances.

  int i,j;
  vector<uint8_t> id_list;
  vector<float> rssi_prom;
  bool aux;
  size_t tam;
  float rssi_aux,c,r_error;
  for (i=0;i<this->Neighboors.size();i++)
  {
       /*Resume ID list*/
       aux=false;
       if(id_list.size()==0)
       {
           /*If is empty, add the first id*/
           id_list.push_back(this->Neighboors.at(i));

        }
       else
       {
           /*In other way, find the currently ID in the list and only add it if it is not yet*/
           tam=id_list.size();
           for(j=0;j<tam;j++)
           {
               if(this->Neighboors.at(i)==id_list.at(j))
               {
                   aux=true;
               }
           }
           if(aux==false)
           {
               id_list.push_back(this->Neighboors.at(i));
           }
       }
  }
  for(i=0;i<id_list.size();i++)
  {
      rssi_aux=0;
      c=0;
      for(j=0;j<this->Neighboors.size();j++)
      {
        if(id_list.at(i)==this->Neighboors.at(j))
        {
          rssi_aux+=this->RSSI_Neighboors.at(j);
          c++;
        }
      }
      rssi_prom.push_back(rssi_aux/c);
  }
  r_error=rssi_prom.at(0)-rssi_prom.at(1);
//define distance
//GetDistance
  if (r_error>this->range_tol.at(0))
  {
       this->Fake_nodes=id_list;
  }
}
void Node::GenerateDocument()
{
  //
}

void Node::Clear_List()
{
  this->Neighboors.clear();
  this->RSSI_Neighboors.clear();
  this->Fake_nodes.clear();
}
