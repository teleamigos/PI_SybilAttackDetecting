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
void Sybil::AddSybilNodes(uint8_t id,uint8_t packet_n){
  Node temp (id,packet_n);
  this->sybil_nodes.push_back(id);
  this->N++;
}
