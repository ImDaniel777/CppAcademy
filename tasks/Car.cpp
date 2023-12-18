#include <iostream>
#include "Car.h"
#include <string>   

Car::Car()
{
    std::cout<<"Car constructor"<<std::endl;
}
Car::Car(std::string  &VIN)
{
    std::cout<<"Car params constructor"<<std::endl;

    _VIN = new std::string (VIN);
}

std::string Car::getVIN()const
{
    return *_VIN;
}

void Car::setVIN(std::string value)
{
    *_VIN = value;
}
Car::~Car()
{
    std::cout<<"Car destructor"<<std::endl;
}