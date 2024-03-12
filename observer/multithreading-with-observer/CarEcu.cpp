#include <iostream>
#include "CarEcu.hpp"

void CarEcu::subscribe(IObserver *observer)
{
    observers.push_back(observer);
}

void CarEcu::unsubscribe(IObserver *observer)
{
    observers.remove(observer);
}

void CarEcu::notify()
{
    for(auto *observer: observers)
    {
        observer->update(data);
    }
}
CarEcu::~CarEcu()
{
    for(auto *observer: observers)
    {
        CarEcu::unsubscribe(observer);
    }
}
void CarEcu::setSpeed(float value)
{
    if(value == data.speed)
    {
        return;
    }
    data.speed = value;
    CarEcu::notify();
}

void CarEcu::setThrottle(float value)
{
    if(value == data.throttle)
    {
        return;
    }
    data.throttle = value;
    CarEcu::notify();
}

float CarEcu::getSpeed()const
{
    return data.speed;
}

float CarEcu::getThrottle()const
{
    return data.throttle;
}