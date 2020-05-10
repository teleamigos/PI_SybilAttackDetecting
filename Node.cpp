/*------------------------------------------------------------------------------
                          Class Node Implementation
------------------------------------------------------------------------------*/
#include "Node.hpp"
/*Constructors*/
Node::Node() : Hash()
{

}
Node::Node(char id,uint8_t packet_n):ID(id),packet_number(packet_n), Hash()
{
        //

}
Node::Node(char id,uint8_t type_message,uint8_t packet_n):ID(id),message_type(type_message),
      packet_number(packet_n), Hash()
{
          //Exceptions
}

Node::Node(const Node &nodo) : Hash(nodo)
{
  this->ID=nodo.ID;
  this->message_type=nodo.message_type;
  this->packet_number=nodo.packet_number;
}

/*Getters*/
char Node::getID()const
{
  return this->ID;
}
uint8_t Node::getMessage_Type()const
{
    return this->message_type;
}
uint8_t Node::getPacket_Number()const
{
  return this->packet_number;
}
vector<char> Node::getNeighboors()const
{
  return this->Neighboors;
}
vector<int> Node::getRSSI_Neighboors()const
{
  return this->RSSI_Neighboors;
}
vector<char> Node::getFake_Nodes()const
{
  return this->Fake_nodes;
}
vector<float> Node::getRange_Tol()const
{
  return this->range_tol;
}
uint8_t Node::getMsgCounter()const
{
  return this->msgCounter;
}
uint8_t Node::getLast_msg()const
{
  return this->last_msg;
}
int Node::getN_detected()const
{
  return this->N_detected;
}
/*Setters*/
void Node::setID(char id)
{
  this->ID=id;
}
void Node::setMessage_Type(uint8_t messaget)
{
  this->message_type=messaget;
}
void Node::setPacket_Number(uint8_t packet_n)
{
  this->packet_number=packet_n;
}
void Node::setRange_Tol(vector<float>  new_range)
{
  //
}
void Node::setMsg_Counter(uint8_t counter)
{
  this->msgCounter=counter;
}
void Node::setLast_msg(uint8_t last)
{
  this->last_msg=last;
}
void Node::setN_detected(int c)
{
  this->N_detected=c;
}
/*Methods*/
void Node::Unpack(char id,int RSSI)
{
       this->Neighboors.push_back(id);
       this->RSSI_Neighboors.push_back(RSSI);
      this->msgCounter++;
}

vector<char> Node::makeList()
{
  int i,j;
  bool aux;
  size_t tam;
  vector<char> id_list;
  for (i=0;i<this->Neighboors.size();i++)
  {
       /*Resume ID list*/
       aux=false;
       if(id_list.size()==0)
       {
           /*If is empty, add the first id*/
           id_list.push_back(this->Neighboors.at(i));

        }
       else
       {
           /*In other way, find the currently ID in the list and only add it if it is not yet*/
           tam=id_list.size();
           for(j=0;j<tam;j++)
           {
               if(this->Neighboors.at(i)==id_list.at(j))
               {
                   aux=true;
               }
           }
           if(aux==false)
           {
               id_list.push_back(this->Neighboors.at(i));
           }
       }
  }
  return id_list;
}
bool Node::Discard(vector<char> id_list)
{
  //In order to discard fake nodes, this method compare a RSSI received with
  // a RSSI standar for many distances.

  int i,j;
  vector<int> rssi_prom;
  int rssi_aux,r_error;
  float c;
  int a,b;
  for(i=0;i<id_list.size();i++)
  {
      rssi_aux=0;
      c=0;
      for(j=0;j<this->Neighboors.size();j++)
      {
        if(id_list.at(i)==this->Neighboors.at(j))
        {
          rssi_aux+=this->RSSI_Neighboors.at(j);
          c++;
        }
      }
      rssi_prom.push_back(rssi_aux/c);
  }
  if(rssi_prom.size()>1)
  {
      r_error=rssi_prom.at(0)-rssi_prom.at(1);
//define distance
//GetDistance
  if (r_error>this->range_tol.at(0))
  {
       for(i=0;i<id_list.size();i++)
       {
         this->Fake_nodes.push_back(id_list.at(i));
         //this->msgCounter++;
         this->N_detected++;
       }
       return true;
  }
  else{
    return false;
  }
  }
  else{
    return false;
  }

}
int Node::LossPacket()
{
  int prom;
  prom=(this->msgCounter*100)/this->last_msg;
  return prom;
}
void Node::GenerateDocument()
{
  //This function implemets a way to generate a document.
  ofstream output;
  bool isOpen;
  string title,head,body,document;
  string id;
  int i,l;
  output.open(this->archivo);
  isOpen= not output ? false:true;
  if(not isOpen)
  {
    cout<<"Error";
  }
  title = "------------------------------Report------------------------------";
  head="Nodes detected as sybil nodes";
  body = "\tNo.\t\tID node\t\n";
  for(i=0;i<this->Fake_nodes.size();i++)
  {
    id=this->Fake_nodes.at(i);
    body+="\t"+to_string(i+1)+"\t";
    body+="\t\t\t"+id+"\t";
    body+="\n";
  }
  l=100-LossPacket();
  body+="\n\t\tOccurrences : \t"+to_string(this->N_detected)+"\n";
  body+="\n\t\tPacket loss : \t"+to_string(l)+"%\n";
  document=title+"\n";
  document+="\t\t\t\t\t\t\t\t"+head+"\n";
  document+=body;
  output<<document;
  output.clear();
}

void Node::Clear_List()
{
  this->Neighboors.clear();
  this->RSSI_Neighboors.clear();
  //this->Fake_nodes.clear();
}

int Node::MakeTarget(string timestamp)
{
  string target;
  target = this->ID + timestamp;
  int target_out;
  target_out = stoi(target);
  return target_out;
}

string Node::GenerateHash(int input)
{
  int i;
  setInput(input);
  computeHash();
  long int *ihash;
  ihash=getHash();
    string hashed;
    stringstream h;
    h<<hex<<ihash[0];
    h<<hex<<ihash[1];
    h<<hex<<ihash[2];
    h<<hex<<ihash[3];
    h<<hex<<ihash[4];
    h<<hex<<ihash[5];
    h<<hex<<ihash[6];
    h<<hex<<ihash[7];
    hashed=h.str();
    return hashed;
}

void Node::proofOfWork(int difficulty)
{

}
