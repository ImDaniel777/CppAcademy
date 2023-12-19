#include "Interfaces.h"
#include "Car.h"

class Toyota : public Car, public MildHybridCarInterface
{
private:
    float battery;
public:
    void chargeBattery(float amount);
    void addFuel(float amout);
};