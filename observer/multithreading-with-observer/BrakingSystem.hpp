#pragma
#include "Interfaces.hpp"
#define WEIGHT 1500
#define WEIGHT_FACTOR 0.3
#define SPEED_FACTOR 0.5

class BrakingSystem : public IObserver
{
public:
    ~BrakingSystem(){}
    void update(CarData data)override;
    void updateBrakingHelp(float value);
    float getBrakingHelp();
private:
    float brakingHelp = 0;
};