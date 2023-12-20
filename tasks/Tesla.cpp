#include <iostream>
#include "Tesla.h"

int Tesla::n = 0;

Tesla::Tesla()
{
    std::cout<<"Tesla constructor"<<std::endl;
}
Tesla &Tesla::getInstance()
{
    static Tesla instance;
    return instance;
}

void Tesla::chargeBattery(float amount)
{
    std::cout<<"Tesla charging"<<std::endl;
}

void Tesla::accelerate()
{
    std::cout<<"Tesla accelerating"<<std::endl;
}

Tesla::~Tesla()
{
    std::cout<<"Tesla destructor"<<std::endl;
    // instance.release();
}