#include "../Interfaces/Interfaces.h"
#include "../Car/Car.h"
#include <memory>
class ElectricCar : public Car, public ElectricCarInterface 
{
private:
    ElectricCar();
    static int n;
public:
    static ElectricCar &getInstance();

    ElectricCar (const ElectricCar &obj) = delete;
    ElectricCar &operator=(const ElectricCar &obj) = delete;
    
    void chargeBattery(float amount) override;
    void accelerate() override;
    ~ElectricCar();
};