/*------------------------------------------------------------------------------
                                      Test Main
------------------------------------------------------------------------------*/

#include <iostream>

#include "Sybil.hpp"
#include "Node.hpp"
#include <vector>
#include <string>
#include <time.h>

using namespace std;

int main(int argc, char const *argv[]) {
  /* code */
  char id1,id2,id3;
  id1='1';
  id2='2';
  id3='3';
  uint8_t tm,c;
  string texto;
  tm=0x00;
  c=0x00;
  bool ans;
  Node n1,node_test;
  Node n2(id2,tm,c);
  Node n3(n1);
  n1.setID(id1);
  n1.setMessage_Type(tm);
  n1.setPacket_Number(c);
  n3.setID(id3);
  n3.setMessage_Type(tm);
  n3.setPacket_Number(c);
  vector<Node> sybil_nodes{n2,n3};
  std::vector<char> v;
  int tam;
  tam = sybil_nodes.size();
  Sybil s;
  Sybil s2(sybil_nodes,tam);
  node_test=s2.S_Pack(0,0x00);
  texto ="Nodos :";
  texto+=id1;
  texto+=id3;
  cout<<texto;
  n1.Unpack(id2,-30);
  n1.Unpack(id3,-31);
  n1.Unpack(id2,-30);
  n1.Unpack(id3,-31);
  n1.Unpack(id2,-30);
  n1.Unpack(id3,-32);
  n1.Unpack(id2,-35);
  n1.Unpack(id3,-31);
  n1.Unpack(id2,-34);
  n1.Unpack(id3,-31);
  n1.Unpack(id2,-36);
  n1.Unpack(id3,-40);
  n1.Unpack(id2,-31);
  n1.Unpack(id3,-31);
  n1.Unpack(id2,-29);
  n1.Unpack(id3,-31);
  n1.Unpack(id2,-31);
  n1.Unpack(id3,-31);
  n1.Unpack(id2,-32);
  n1.Unpack(id3,-31);
  v=n1.makeList();
  cout<<"Generating document"<<endl;
  for(int i=0;i<v.size();i++){
    cout<<v.at(i)<<endl;
    cout<<"size"<<v.size()<<endl;
  }
  ans=n1.Discard(v);
  n1.Unpack(id2,-30);
  n1.Unpack(id3,-31);
  n1.Unpack(id2,-30);
  n1.Unpack(id3,-31);
  n1.Unpack(id2,-30);
  n1.Unpack(id3,-32);
  n1.Unpack(id2,-35);
  n1.Unpack(id3,-31);
  n1.Unpack(id2,-34);
  n1.Unpack(id3,-31);
  n1.Unpack(id2,-36);
  n1.Unpack(id3,-40);
  n1.Unpack(id2,-31);
  n1.Unpack(id3,-31);
  n1.Unpack(id2,-29);
  n1.Unpack(id3,-31);
  n1.Unpack(id2,-31);
  n1.Unpack(id3,-31);
  n1.Unpack(id2,-32);
  n1.Unpack(id3,-31);
  v=n1.makeList();
  ans=n1.Discard(v);
  n1.setLast_msg(42);
  n1.GenerateDocument();
  /*
  Hash h(13872198);
  int i;
  h.computeHash();
  long int *hash;
  hash=h.getHash();
  int t;
  string semilla;
  //n1.proofOfWork(1,hashed);
  */
  int i_time,f_time;
  double time_process;
  i_time = clock();
  n1.proofOfWork(6);
  f_time = clock();
  time_process= (double)(f_time-i_time)/CLOCKS_PER_SEC;
  cout<<"Time of hashed : "<<time_process*1000<<endl;
  return 0;
}
