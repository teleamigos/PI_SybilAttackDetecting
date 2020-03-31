/*------------------------------------------------------------------------------
--------------------------Class Device definition-------------------------------
------------------------------------------------------------------------------*/
#ifndef Device_hpp
#define Device_hpp

#include "Node.hpp"
#include <iostream>

class Device: public Node
{
private:
  uint8_t message_t=0x00;
  uint16_t message;
public:
  Device()=default;
};

#endif
