/*------------------------------------------------------------------------------
--------------------------Class Device definition-------------------------------
------------------------------------------------------------------------------*/
#ifndef Device_hpp
#define Device_hpp

#include "Node.hpp"
#include <iostream>

using namespace std;
class Device: public Node
{
private:
  uint8_t message_t=0x00;
  uint32_t message;
public:
  /*Constructors*/
  Device()=default;
  //Device(const Node &nodo);
  Device(uint8_t mtype,uint16_t m);
  Device(const Device &device);
  /*Getters*/
  uint8_t getMessageType()const;
  uint16_t getMessage()const;
  /*Setters*/
  void setMessageType(uint8_t mt);
  void setMessage(uint16_t m);
  /*Overt*/
  void Pack();
  /*Others*/

};

#endif
