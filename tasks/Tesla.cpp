#include <iostream>
#include "Tesla.h"

std::unique_ptr<Tesla> Tesla::instance{nullptr};
Tesla::Tesla(_cons)
{
    std::cout<<"Tesla constructor"<<std::endl;
}

std::unique_ptr<Tesla> &Tesla::getInstance()
{
    static std::unique_ptr<Tesla> instance { Tesla::instanceFactory() };
    return instance;
}

std::unique_ptr<Tesla> Tesla::instanceFactory()
{
    return std::make_unique<Tesla>(_cons());
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
    instance.release();
}