/*------------------------------------------------------------------------------
                      Class Sybil_Node Implementation
------------------------------------------------------------------------------*/

#include "Sybil.hpp"

/*Constructors*/
Sybil::Sybil(vector<Node> sn,int n):sybil_nodes(sn),N(n)
{
  //Exception
}
/*Getters*/
vector<Node> Sybil::getSybil_Nodes()const
{
  return this->sybil_nodes;
}
int Sybil::getN()const
{
  return this->N;
}
/*Setters*/
void Sybil::setSybilNodes(vector<Node> sn){
  this->sybil_nodes=sn;
}
void Sybil::setN(int n){
  this->N=n;
}
/*Methods*/
void Sybil::AddSybilNodes(char id,uint8_t packet_n,uint8_t type_message){
  Node temp (id,type_message,packet_n);
  this->sybil_nodes.push_back(temp);
  this->N++;
}
Node Sybil::S_Pack(int index,uint8_t packet_n)
{
  uint8_t tm=0x00;
  this->sybil_nodes.at(index).setPacket_Number(packet_n);
  this->sybil_nodes.at(index).setMessage_Type(tm);
  return this->sybil_nodes.at(index);
}
