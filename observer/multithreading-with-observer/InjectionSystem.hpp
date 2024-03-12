#pragma once
#include "Interfaces.hpp"
#define MAX_THROTTLE 100.0

class InjectionSystem : public IObserver
{
public:
    ~InjectionSystem();
    void update(CarData data)override;
    void updateEngineLoad(float value);
    float getEngineLoad();
private:
    float engineLoad = 0;

};