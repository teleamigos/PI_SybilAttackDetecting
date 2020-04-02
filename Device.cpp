/*------------------------------------------------------------------------------
--------------------------Class Device definition-------------------------------
------------------------------------------------------------------------------*/

#include "Device.hpp"
/*Constructors*/
Device::Device(uint8_t mtype,uint16_t m):message_t(mtype),message(m)
{
  //
}

Device::Device(const Device & device):Node(device)
{
  this->message_t=device.message_t;
  this->message=device.message;
}
/*Getters*/
uint8_t Device::getMessageType()const
{
  return this->message_t;
}
uint16_t Device::getMessage()const{
  return this->message;
}
/*Setters*/
void Device::setMessageType(uint8_t mt){
  this->message_t=mt;
}
void Device::setMessage(uint16_t m){
  this->message=m;
}
/*Overt*/
void Device::Pack()
{
  if(this->message_t==0x00)
  {
    this->message=(this->message_t<<8)+GetID();
  }
}
/*Others*/
