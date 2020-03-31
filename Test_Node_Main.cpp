/*

                    Test_Node_Main.cpp

*/

#include "Node.hpp"
#include <string>
int main()
{
  Node n;
  uint8_t id=0x10;
  n.SetID(id);
  cout<<(std::string *)n.GetID()<<endl;
  return 0;
}
