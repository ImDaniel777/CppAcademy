#include <iostream>
#include "HybridCar.h"

HybridCar::HybridCar(){}

HybridCar::HybridCar(const HybridCar &other)
{

}

HybridCar::HybridCar(HybridCar &&other)
{

}

HybridCar &HybridCar::operator=(const HybridCar &other)
{
}

HybridCar &HybridCar::operator=(HybridCar &&other)
{

}

HybridCar::HybridCar(std::string VIN) : Car(VIN)
{

}

void HybridCar::chargeBattery(float value)
{
    battery += value;
}

void HybridCar::addFuel(float value)
{

}

void HybridCar::accelerate()
{

}

HybridCar::~HybridCar()
{

}