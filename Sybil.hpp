/*------------------------------------------------------------------------------
                          Class Node Definition
------------------------------------------------------------------------------*/
#ifndef Sybil_hpp
#def Sybil_hpp
#include <iostream>
#include <vector>
#include "Node.hpp"
using namespace std;
class Sybil
{
private:
  vector<Node> sybil_nodes;
  int N;
public:
  /*Constructors*/
  Sybil()=default;
  Sybil(vector<Node> sn,int n);
  /*Getters*/
  vector<Node> getSybil_Nodes()const;
  int getN()const;
  /*Setters*/
  void setSybilNodes(vector<Node> sn);
  void setN(int n);
  /*Methods*/
  void AddSybilNodes(uint8_t id);
};
#endif