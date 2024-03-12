#pragma once
#include "Interfaces.hpp"
#include "list"
class CarEcu : public IObservable
{
public:
    ~CarEcu(){}
    void subscribe(IObserver *observer)override;
    void unsubscribe(IObserver *observer)override;
    void notify()override;
    
    void setSpeed(float value);
    float getSpeed()const;
    
    void setThrottle(float value);
    float getThrottle()const;

private:
    CarData data;

    std::list<IObserver*> observers;
};