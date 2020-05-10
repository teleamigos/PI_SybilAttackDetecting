//
//  Hash.cpp
//  PI_SybilAttackDetecting
//
//  Created by <author> on 09/05/2020.
//
//

#include "Hash.hpp"

//Hash::Hash()  {}
//Hash::~Hash() {}
/*Constructor*/
Hash::Hash(int value): input(value)
{
  //
}

/*Getters and setters*/
/*
long int* Hash::getK()const
{
  return this->k;
}
long int* Hash::getHash()const
{
  return this->hash;
}
int Hash::getInput()const
{
  return this->input;
}
void Hash::setK(int k){
  //this->k
}
void Hash::setHash(int hash)
{

}
void Hash::setInput(int value)
{
  this->input=value;
}
*/

long int* Hash::getHash()
{
  return this->hash;
}
int Hash::getInput()const
{
  return this->input;
}
void Hash::setInput(int value)
{
  this->input=value;
}
/*methods*/

void Hash::computeHash()
{
  long int a,b,c,d,e,f,g,h,s0,s1,S0,S1,ch,temp1,maj,temp2;
  int i;
  a=this->hash[0];
  b=this->hash[1];
  c=this->hash[2];
  d=this->hash[3];
  e=this->hash[4];
  f=this->hash[5];
  g=this->hash[6];
  h=this->hash[7];
  for (i=0;i<64;i++)
  {
    s0 = (ROTRIGHT(this->input,7))^(ROTRIGHT(this->input,18))^(this->input>>3);
    s1 = (ROTRIGHT(this->input,17))^(ROTRIGHT(this->input,19))^(this->input>>10);
    this->input = this->input + s0 + s1;
    S1 = (ROTRIGHT(e,6))^(ROTRIGHT(e,11))^(ROTRIGHT(e,25));
    ch = (e&f)^((~e)&g);
    temp1 = h + S1 + ch + this->k[i] + this->input;
    S0 = (ROTRIGHT(a,2))^(ROTRIGHT(a,13))^(ROTRIGHT(a,22));
    maj = (a&b)^(a&c)^(b&c);
    temp2 = S0 + maj;
    h = g;
    g = f;
    f = e;
    e = d + temp1;
    d = c;
    c = b;
    b = a;
    a = temp1 + temp2;
  }
  this->hash[0] = a + this->hash[0];
  this->hash[1] = b + this->hash[1];
  this->hash[2] = c + this->hash[2];
  this->hash[3] = d + this->hash[3];
  this->hash[4] = e + this->hash[4];
  this->hash[5] = f + this->hash[5];
  this->hash[6] = g + this->hash[6];
  this->hash[7] = h + this->hash[7];

}

int Hash::ROTRIGHT(int value,int num)
{
  int output;
  // Los caracteres >> representan un corrimiento, y | es un or
  output = (((input) >> (num)) | ((input) << (32-(num))));
  return output;
}
