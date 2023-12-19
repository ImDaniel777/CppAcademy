#include <iostream>
#include "Car.h"
#include <string>   

#define HP_TO_KW(value) (value * 0.7457)
#define KW_TO_HP(value) (value / 0.7457)

Car::Car()
{
    // std::cout<<"Car constructor"<<std::endl;
}
Car::Car(std::string  &VIN)
{
    _VIN = new std::string (VIN);
}

int Car::getMileage()const
{
    return mileage;
}

void Car::setMileage(int value)
{
    mileage = value;
}
std::string Car::getVIN()const
{
    return *_VIN;
}

int Car::getHorsePower()const
{
    return horsePower;
}

void Car::setHorsePower(int value)
{
    horsePower = value;
    kwPower = static_cast<float>(HP_TO_KW(horsePower));
}

float Car::getKwPower()const
{
    return kwPower;
}

void Car::setKwPower(float value)
{
    kwPower = value;
    horsePower = static_cast<int>(KW_TO_HP(kwPower));
}

std::string Car::getChassisType()const
{
    return chassisType;
}

void Car::setChassisType(std::string &type)
{
    chassisType = type;
}

void Car::setVIN(std::string value)
{
    *_VIN = value;
}
Car::~Car()
{
    // std::cout<<"Car destructor"<<std::endl;
}