#include <iostream>
#include "Audi.h"

Audi::Audi()
{
    std::cout<<"Audi constructor"<<std::endl;
}

Audi::Audi(std::string  &VIN) : Car(VIN)
{
    std::cout<<"Audi param constructor"<<std::endl;
}

Audi::Audi(const Audi &obj)
{
    std::cout<<"Audi(const Audi&)"<<std::endl;
    _VIN = new std::string(*obj._VIN);
}

Audi::Audi(Audi &&obj)
{   
    std::cout<<"Audi(Audi &&)"<<std::endl;
    _VIN = obj._VIN;
    obj._VIN = nullptr;
}

Audi &Audi::operator=(const Audi &obj)
{
    std::cout<<"operator=(const Audi &obj)"<<std::endl;
    if(this != &obj)
    {
        delete _VIN;
        _VIN = new std::string(*obj._VIN);
    }
    return *this;
}

Audi &Audi::operator=(Audi &&obj)
{
    std::cout<<"operator=(Audi &&obj)"<<std::endl;
    if(this != &obj)
    {
        delete _VIN;
        _VIN = obj._VIN;
        obj._VIN = nullptr;
    }
    return *this;
}
void Audi::accelerate()
{
    std::cout<<"Audi acceleration"<<std::endl;
}

Audi::~Audi()
{
    std::cout<<"Audi destructor"<<std::endl;
    delete _VIN;
}