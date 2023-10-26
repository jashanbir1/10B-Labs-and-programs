#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}
bool IntList:: exists(int num1) const
{
   IntNode* temp = head;
   if(head == nullptr)
   {
      return false;
   }
   // else if(head != nullptr)
   // {
      return exists(temp,num1);
      
   //}
}
bool IntList:: exists(IntNode *temp, int num1) const
{
   if(temp->value != num1)
   {
      if(temp->next == nullptr)
      {
         return false;
      }
      else
      {
         return exists(temp->next,num1);
      }
   }
   else
   {
      return true;
   }
}

ostream& operator<<(ostream& o, const IntList& listy)
{
   if (listy.head == nullptr)
   {
      return o;
   }
   o << listy.head->value;
   return operator<<(o, listy.head->next);
}
ostream & operator<<(ostream &o, IntNode *temp)
{
   if(temp == nullptr)
   {
      return o;
   }
   else
   {
      o << " ";
   }
   o << temp->value;
   return operator<<(o,temp->next);
}


