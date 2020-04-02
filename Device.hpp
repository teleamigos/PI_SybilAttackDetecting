/*------------------------------------------------------------------------------
--------------------------Class Device definition-------------------------------
------------------------------------------------------------------------------*/
#ifndef Device_hpp
#define Device_hpp

#include "Node.hpp"
#include <iostream>

using namespace std;
class Device
{
private:
  uint8_t message_t=0x00;
  uint32_t message;
  Node selfnode;
public:
  /*Constructors*/
  Device()=default;
  //Device(const Node &nodo);
  Device(uint8_t mtype,uint16_t m,const Node &n);
  Device(const Device &device);
  /*Getters*/
  uint8_t getMessageType()const;
  uint16_t getMessage()const;
  Node getNode()const;
  /*Setters*/
  void setMessageType(uint8_t mt);
  void setMessage(uint16_t m);
  void setNode(const Node &n);
  /*Overt*/
  void Pack();
  void Unpack(uint32_t received);
  /*Others*/

};

#endif
