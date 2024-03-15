#include <iostream>
#include "Integer.h"

Integer::Integer()
{
    _int = new int;
}

Integer::Integer(int value)
{
    std::cout<<"Integer constructor\n";
    _int = new int(value);  
}

Integer::Integer(const Integer& other)
{
    std::cout<<"Integer copy constructor\n";
    _int = new int(*other._int);
}

Integer& Integer::operator=(const Integer& other)
{
    std::cout<<"Integer copy assignment\n";
    if(&other == this)
    {
        return *this;
    }
    delete _int;
    _int = new int(*other._int);
    return *this;
}

Integer::Integer(Integer&& other)
{
    std::cout<<"Integer move constructor\n";
    _int = other._int;
    other._int = nullptr;
}

Integer& Integer::operator=(Integer&& other)
{
    std::cout<<"Integer move assignment\n";
    if(this == &other)
    {
        return *this;
    }
    delete _int;
    _int = other._int;
    other._int = nullptr;
    return *this;
}

int Integer::getValue()const
{
    return *_int;
}

void Integer::setValue(int value)
{
    *_int = value;
}

Integer::~Integer()
{
    std::cout<<"Integer destructor\n";
    delete _int;
}