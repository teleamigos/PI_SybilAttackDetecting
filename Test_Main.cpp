/*

                    Test_Main.cpp

*/

#include "Node.hpp"
#include "Device.hpp"

int main(int argc, char const *argv[]) {
  /* code */
  uint8_t ID,mtype,ID2,ID3;
  ID=0x11;
  ID2=0x01;
  ID3=0x03;
  mtype=0x00;
  uint32_t m=0x00;
  Node n;
  n.SetID(ID2);
  Node n1(ID);
  Node n2(n);
  Device d1;
  Device d2(mtype,m,n);
  d2.getNode();
  d1.setNode(n2);
  d1.Pack();
  d2.Pack();
  return 0;
}
