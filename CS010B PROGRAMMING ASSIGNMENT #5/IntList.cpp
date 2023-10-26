#include <iostream>

using namespace std;

#include "IntList.h"

IntList::IntList()
{
    head = nullptr;
    tail = nullptr;
}
IntList::~IntList()
{
    while (head)
    {
        IntNode *temp = head->next;
        delete head;
        head = temp;
    }
}
IntList::IntList(const IntList &cpy) // HELPPPPPP
{
    IntNode *curr = cpy.head;
    head = nullptr;
    tail = nullptr;
    if (!cpy.empty())
    {
        while (curr != nullptr)
        {
            push_back(curr->value);
            curr = curr->next;
        }
    }
}
IntList &IntList ::operator=(const IntList &rhs) // HELPPPPP
{
    // REFERENCED FROM LECTURE AND VIDEOS KRIS MILLER SHARED
    IntNode *curr = rhs.head;
    if (rhs.empty())
    {
        head = nullptr;
        tail = nullptr;
    }
    else if (this == &rhs)
    {
        return *this;
    }
    else if (!rhs.empty())
    {
        clear();
        while (curr != nullptr)
        {
            push_back(curr->value);
            curr = curr->next;
        }
    }
    return *this;
}
void IntList::push_back(int value)
{
    // REFERENCE FROM ZYBOOKS VIDOES PROFESSOR KRIS MILLER LINKED
    IntNode *temp = new IntNode(value);
    if (empty())
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}
void IntList::selection_sort()
{
    IntNode *i;
    IntNode *j;
    IntNode *minVal = head;
    if (!empty())
    {
        for (i = head; i->next != nullptr; i = i->next)
        {
            minVal = i;
            for (j = i->next; j != nullptr; j = j->next)
            {
                if (j->value < minVal->value)
                {
                    minVal = j;
                }
            }

            int temp = minVal->value;
            minVal->value = i->value;
            i->value = temp;
        }
    }
    else
    {
        return;
    }
}
void IntList::insert_ordered(int value)
{
    // REFERENCE INSERT ORDERED VIDEO
    if (empty()) // special case
    {
        push_back(value);
    }
    else if (value < head->value) // special case
    {
        push_front(value);
    }
    else if (value >= tail->value) // special case
    {
        push_back(value);
    }
    else
    {
        IntNode *temp = new IntNode(value);
        IntNode *previous = head;
        IntNode *current = head->next;
        while (head->next != nullptr)
        {
            if (value <= current->value)
            {
                previous->next = temp;
                temp->next = current;
                return;
            }
            previous = previous->next;
            current = current->next;
        }
        // previous = previous->next;
        // current = current->next;
    }
}
void IntList::remove_duplicates() // GET HELP
{
    // check if list is empty or list is one node
    if (empty())//|| (head == tail))
    {
        return;
    }
    for (IntNode *i = head; i != nullptr; i = i->next)
    {
        IntNode *prev = i;
        //cout << "i's value: " << i->value << endl;
        for (IntNode *j = i->next; j != nullptr; j = prev->next)
        {
            if (j->value == i->value)
            {
                prev->next = j->next;
                if (j->next == nullptr)
                {
                    tail = prev;
                }
                    //cout << "printin....." << endl;
                    //cout << tail->value << endl;
                    //cout << prev->value << endl;
                    //cout << "print done.." << endl;
                delete j;
                j = nullptr;
            }
            else
            {
                prev = j;
            }
        }

            //prev = prev->next;
    }
}

void IntList::clear()
{
    while (head != nullptr)
    {
        pop_front();
    }
}
void IntList::push_front(int val)
{
    IntNode *temp = new IntNode(val);
    if (head == nullptr)
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
void IntList::pop_front()
{
    // if (!empty())
    // {
        if(empty())
    {
        return;
    }
    IntNode *temp = head->next;
    delete head;
    head = temp;
    //}
    if(empty())
    {
        head = nullptr;
        tail = nullptr;
    }
    
}
bool IntList::empty() const
{
    if (head == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
const int &IntList::front() const
{
    return head->value;
}
const int &IntList::back() const
{
    return tail->value;
}

ostream &operator<<(ostream &o, const IntList &listy)
{
    IntNode *temp = listy.head;

    while (temp != nullptr)
    {
        o << temp->value;
        temp = temp->next;
        if (temp != nullptr)
        {
            o << " ";
        }
    }

    return o;
}