#include <iostream>

using namespace std;

#include "IntList.h"

IntList:: IntList()
{
    head = nullptr;
    tail = nullptr;
}
IntList:: ~IntList()
{
    //REFERENCED FROM ZYBOOKS 7.5.3
    // delete head;
    // delete tail;
    while (head)
    {
    IntNode* temp = head->next;
    delete head;
    head = temp;
    }
}
void IntList:: clear()
{
    // delete head;
    // delete tail;
    // head = nullptr;
    // tail = nullptr;
    while (head != nullptr)
    {
        pop_front();
    }
}
void IntList:: push_front(int val)
{
    IntNode* temp = new IntNode(val);
    if(head == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {
    temp->next = head;
    head = temp;
    }
}
void IntList:: pop_front()
{
    if (!empty())
    {
        IntNode* temp = head->next;
        delete head;
        head = temp;
    }
    else
    {
        return;
    }
}
bool IntList:: empty() const
{
    if(head == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
const int& IntList::  front() const
{
    return head->value;
}
const int& IntList:: back() const
{
    return tail->value;
}
ostream& operator<<(ostream & o, const IntList & listy)
{
    IntNode* temp = listy.head;

    while (temp != nullptr)
    {
    o << temp->value;
    temp = temp->next;
        if(temp != nullptr)
        {
            o << " ";
        }
    }
    
    return o;
}