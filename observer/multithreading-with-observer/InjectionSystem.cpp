#include "InjectionSystem.hpp"

void InjectionSystem::update(CarData data)
{
    InjectionSystem::updateEngineLoad(data.throttle);
}

void InjectionSystem::updateEngineLoad(float throttle)
{
    engineLoad = throttle / MAX_THROTTLE;
}
    
float InjectionSystem::getEngineLoad()
{
    return engineLoad;
}

InjectionSystem::~InjectionSystem()
{
    
}