/*------------------------------------------------------------------------------
                          Class Node Implementation
------------------------------------------------------------------------------*/
#include "Node.hpp"
/*Constructors*/
Node::Node(char id,uint8_t packet_n):ID(id),packet_number(packet_n)
{
        //Exceptions
}
Node::Node(char id,uint8_t type_message,uint8_t packet_n):ID(id),message_type(type_message),
      packet_number(packet_n)
{
          //Exceptions
}

Node::Node(const Node &nodo)
{
  this->ID=nodo.ID;
  this->message_type=nodo.message_type;
  this->packet_number=nodo.packet_number;
}

/*Getters*/
char Node::getID()const
{
  return this->ID;
}
uint8_t Node::getMessage_Type()const
{
    return this->message_type;
}
uint8_t Node::getPacket_Number()const
{
  return this->packet_number;
}
vector<char> Node::getNeighboors()const
{
  return this->Neighboors;
}
vector<int> Node::getRSSI_Neighboors()const
{
  return this->RSSI_Neighboors;
}
vector<char> Node::getFake_Nodes()const
{
  return this->Fake_nodes;
}
vector<float> Node::getRange_Tol()const
{
  return this->range_tol;
}
/*Setters*/
void Node::setID(char id)
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
void Node::setRange_Tol(vector<float>  new_range)
{
  //
}
/*Methods*/
void Node::Unpack(char id,int RSSI)
{
       this->Neighboors.push_back(id);
       this->RSSI_Neighboors.push_back(RSSI);
}

vector<char> Node::makeList()
{
  int i,j;
  bool aux;
  size_t tam;
  vector<char> id_list;
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
  return id_list;
}
bool Node::Discard(vector<char> id_list)
{
  //In order to discard fake nodes, this method compare a RSSI received with
  // a RSSI standar for many distances.

  int i,j;
  vector<int> rssi_prom;
  int rssi_aux,r_error;
  float c;
  int a,b;
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
  if(rssi_prom.size()>1)
  {
      r_error=rssi_prom.at(0)-rssi_prom.at(1);
//define distance
//GetDistance
  if (r_error>this->range_tol.at(0))
  {
       this->Fake_nodes=id_list;
       return true;
  }
  else{
    return false;
  }
  }
  else{
    return false;
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
