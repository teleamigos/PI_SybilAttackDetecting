/*------------------------------------------------------------------------------
--------------------------Class Device definition-------------------------------
------------------------------------------------------------------------------*/

#include "Device.hpp"
#include "Node.hpp"
#include <vector>
#include <iostream>

using namespace std;

class Sybil_Node : public Device
{
private:
  int N;
  vector<Nodes> snodes;
public:
  Sybil_Node()=default;
};
