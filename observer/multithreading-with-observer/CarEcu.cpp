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

void CarEcu::setSpeed(float value)
{
    data.speed = value;
}

void CarEcu::setThrottle(float value)
{
    data.throttle = value;
}
