#ifndef SORTEDSET_H
#define SORTEDSET_H

//#include <ostream>

//using namespace std;
#include "IntList.h"
class SortedSet : public IntList{

    //protected:

    public:
    SortedSet();
    SortedSet(const SortedSet &);
    SortedSet(const IntList &);
    ~SortedSet();
    SortedSet operator|(const SortedSet&) const;
    SortedSet operator&(const SortedSet&) const;
    bool in(int ) const;
    void add(int );
    void push_front(int );
    void push_back(int);
    void insert_ordered(int );
    SortedSet& operator |=(const SortedSet&);
    SortedSet& operator&=(const SortedSet&);
    


};
#endif