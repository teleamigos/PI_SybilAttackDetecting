#ifndef PoW_hpp
#define PoW_hpp

#include<string>
using namespace std;
class PoW{
public:
  virtual string GenerateTarget(int difficulty)=0;
  virtual string packto_hash(char ID,string timestamp,string nonce)=0;
  virtual string proofOfWork(int difficulty)=0;
};
#endif
