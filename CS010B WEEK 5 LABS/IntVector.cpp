#include <iostream>
#include <stdexcept>
using namespace std;

#include "IntVector.h"

/*Sets both the size and capacity of the IntVector to the value of the capacity argument passed in or the default 
value of 0 if no argument is passed in for the capacity parameter. 
The constructor should dynamically allocate an array of this capacity value passed in. 
However, if the capacity is 0, then there is no array. Make sure you do not leave a dangling pointer. 
This function should initialize all elements (if any) of the array to the value of the 2nd argument passed in or to the default value of 0 if no argument passed in for the value parameter.*/


IntVector::IntVector(unsigned capacity = 0, int value = 0)
{
    _size = capacity;
    _capacity = capacity;

    if(_capacity > 0)
    {
        _data = new int[_capacity];
        for(int i = 0; i < _capacity; ++i)
        {
            _data[i] = value;
        }
    }
}



IntVector:: ~IntVector()
{
    delete _data;
}

unsigned IntVector:: size() const
{
    return _size;
}

unsigned IntVector:: capacity() const
{
    return _capacity;
}

bool IntVector:: empty() const
{
    if(_size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

const int& IntVector:: at(unsigned index) const
{
    if(index >= _size)
    {
        throw out_of_range("IntVector::at_range_check");
    }
    else
    {
        return _data[index];
    }
}

const int& IntVector:: front() const
{
    return _data[0];
}

const int& IntVector:: back() const
{
    return _data[_size -1];
}