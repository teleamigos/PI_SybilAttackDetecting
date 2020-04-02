/*

                    Test_Node_Main.cpp

*/

#include "Node.hpp"
#include "Device.hpp"
#include <string>
int main()
{
  Node n,n2;
  Device d1,d2;
  Device d3(d2);
  uint8_t id=0x10;
  n.SetID(id);
  return 0;
}
