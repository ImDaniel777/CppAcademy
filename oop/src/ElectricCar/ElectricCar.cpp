#include <iostream>
#include "ElectricCar.h"

int ElectricCar::n = 0;

ElectricCar::ElectricCar()
{
    std::cout<<"ElectricCar constructor"<<std::endl;
}
ElectricCar &ElectricCar::getInstance()
{
    static ElectricCar instance;
    return instance;
}

void ElectricCar::chargeBattery(float amount)
{
    std::cout<<"ElectricCar charging"<<std::endl;
}

void ElectricCar::accelerate()
{
    std::cout<<"ElectricCar accelerating"<<std::endl;
}

ElectricCar::~ElectricCar()
{
    std::cout<<"ElectricCar destructor"<<std::endl;
}