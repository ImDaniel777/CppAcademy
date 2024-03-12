#include <iostream>
#include "BrakingSystem.hpp"

void BrakingSystem::update(CarData data)
{
    BrakingSystem::updateBrakingHelp(data.speed);
}

void BrakingSystem::updateBrakingHelp(float speed)
{
    brakingHelp = speed*SPEED_FACTOR + WEIGHT*WEIGHT_FACTOR;
}

float BrakingSystem::getBrakingHelp()
{
    return brakingHelp;
}