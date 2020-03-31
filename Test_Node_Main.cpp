/*

                    Test_Node_Main.cpp

*/

#include "Node.hpp"
#include <iostream>
#include <string>
int main()
{
  uint8_t ID=0x2;
  uint8_t m=0x1;
  uint16_t message;
  message=(ID<<8)+m;
  std::string *i;
  uint8_t r;
  Node n1,n2,n3;
  Node n4(ID,m);
  ID=0x02;
  n2.SetID(ID);
  n3.SetMessageType(m);
  r=n2.GetID();
  i=(std::string *)message;
  cout<<i<<endl;

  return 0;
}
