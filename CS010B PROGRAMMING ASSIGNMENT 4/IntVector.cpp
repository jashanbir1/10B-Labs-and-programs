//#include <iostream>
#include <stdexcept>
using namespace std;

#include "IntVector.h"


IntVector:: IntVector (unsigned capacity, int value)
{
    //_size = capacity;
    _size = capacity;
    //_capacity = capacity;
    _capacity = capacity;
    _data = nullptr;
    if(capacity > 0)
    {
        _data = new int[_capacity];
        for(unsigned int i = 0; i < _size; ++i)
        {
            //_data[i] = value;
            _data[i] = value;
        }
    }


}
IntVector:: ~IntVector()
{
    //delete[] _data;
    delete[] _data;
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
const int& IntVector:: at (unsigned index) const
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
int& IntVector:: at(unsigned index)
{
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
}
void IntVector:: insert(unsigned index, int value)
{
    if (index > _size)
    {
        throw out_of_range("IntVector::insert_range_check");
    }
    if (_size >= _capacity)
    {
        expand();
    }
    for(unsigned i = _size; i > index;--i)
    {
        _data[i] = _data[i - 1];
        
    }
    _data[index] = value;
    ++_size;

}
void IntVector:: erase(unsigned index)
{
    if (index >= _size)
    {
        throw out_of_range("IntVector::erase_range_check");
    }
    for (unsigned i = index; i < _size; ++i)
    {
        _data[i] = _data[i + 1]; 
    }
    --_size;
}
const int& IntVector:: front() const
{
    return _data[0];
}
int& IntVector::front()
{
    return _data[0];
}
const int& IntVector::back() const
{
    return _data[_size -1];
}
int& IntVector::back()
{
    return _data[_size - 1];
}
void IntVector:: assign(unsigned n, int value) // GET HELP
{
    //_size = n;
    if(n > 2 * _capacity)
    {
        expand(n - _capacity);
    }
    else if (n > _capacity)
    {
        expand();
    }
    _size = n;
    for (unsigned i = 0; i < _size; ++i)
    {
        _data[i] = value;
    }
    
}
void IntVector::push_back(int value)
{
    //++_size;
    if(_size >= _capacity)
    {
        expand();
    }
    ++_size;
    _data[_size - 1] = value;
}
void IntVector::pop_back()
{
    --_size;
}
void IntVector::clear()
{
    _size = 0;
}
void IntVector::resize(unsigned size, int value) //*
{
    if(size < _size)
    {
        _size = size;
    }
    else if (size > _size)
    {
    
        if (size > 2 * _capacity)
        {
            expand(size - _capacity);
        }
        else if (size > _capacity)
        {
            expand();
        }
        for( unsigned i = _size; i < size; ++i)
        {
            _data[i] = value;
        }
        _size = size;
    }
    
}
void IntVector:: reserve(unsigned n)
{
    if (n > _capacity)
    {
        expand(n - _capacity);
    }
   
}
void IntVector::expand() // GET HELP
{
    _capacity *= 2;
    if (_capacity == 0)
    {
        _capacity = 1;
        _data = new int[_capacity];
        return;
    }

    int* temp = new int[_capacity];
    for (unsigned i = 0; i < _size; ++i)
    {

        temp[i] = _data[i];
    }
    //int* _temp = new int[_capacity];
    delete[] _data;
    _data = temp;
    temp = nullptr;
    // else
    // {
    //     __data = new int[_capacity];
    // }
}
void IntVector:: expand(unsigned amount) // GET HELP
{
    _capacity += amount;
    int* temp = new int[_capacity];
    for (unsigned i = 0; i < _size; ++i)
    {

        temp[i] = _data[i];
    }
    delete[] _data;
    _data = temp;
    temp = nullptr;
}
