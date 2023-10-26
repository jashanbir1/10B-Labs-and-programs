#include <iostream>
#include <ostream> 
#include <algorithm>


using namespace std;

#include "SortedSet.h"

SortedSet::SortedSet():IntList(){}

SortedSet::SortedSet(const SortedSet &set):IntList(set) {}

SortedSet::SortedSet(const IntList &listy): IntList(listy) 
{
    IntList::remove_duplicates();
    IntList::selection_sort();
}
SortedSet:: ~SortedSet() {}

SortedSet SortedSet::operator|(const SortedSet& sett1) const// NEED HELP
{
    SortedSet obj(*this);

    for(IntNode* temp = sett1.head; temp != nullptr; temp = temp->next)
    {
         obj.add(temp->value);
    }
    return obj;
    
    // SortedSet obj(sett1);
    
    // IntNode *temp= sett1.head;

    // while(temp!=nullptr){
    //     obj.add(temp->value);
    //     temp=temp->next;
    // }

    
    // return obj;
    
}
SortedSet SortedSet::operator&(const SortedSet& sett1) const // NEED HELP
{
    SortedSet obj;
    
    for(IntNode* temp = head; temp != nullptr; temp = temp->next)
    {
        if(sett1.in(temp->value))
        {
            obj.add(temp->value);
        }
    }
    return obj;
}
bool SortedSet:: in(int val) const
{
    
   // IntNode *temp = nullptr;
    bool torf = false;
    for(IntNode* temp = head; temp != nullptr; temp = temp->next)
    {
        if(temp->value == val)
        {
            torf = true;
            return torf;
        }
        else{
            torf = false;
        }
    }
    return torf;
}
void SortedSet:: add(int val)// NEED HELP
{
   if(!in(val))
   {
    IntList::insert_ordered(val);
   }
}
void SortedSet::push_front(int value)
{
    add(value);
    //insert_ordered(value);
}
void SortedSet:: push_back(int value)
{
    //insert_ordered(value);
    add(value);
}
void SortedSet:: insert_ordered(int value)
{
    add(value);
}
SortedSet& SortedSet:: operator |=(const SortedSet& sett1)// NEED HELP
{
    //*this |= *this | sett;
    //*this |= sett;
    SortedSet obj(*this);

    for(IntNode* temp = sett1.head; temp != nullptr; temp = temp->next)
    {
         obj.add(temp->value);
    }
    *this = obj;
    return *this;
}
SortedSet& SortedSet:: operator &=(const SortedSet& sett) 
{
    //*this = *this | sett;
    //*this &= sett;
    SortedSet obj;
    
    for(IntNode* temp = head; temp != nullptr; temp = temp->next)
    {
        if(sett.in(temp->value))
        {
            obj.add(temp->value);
        }
    }
    *this = obj;
    return *this;
}
