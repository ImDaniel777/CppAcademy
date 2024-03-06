#include "../Interfaces/Interfaces.h"
#include "../Car/Car.h"
#include <vector>

class HybridCar : public Car, public PlugInHybridInterface
{
private:
    float battery;

    std::vector<std::string> *models;
public:
    // using Car::Car;
    HybridCar();
    HybridCar(std::string VIN);

    HybridCar(const HybridCar &other);
    HybridCar(HybridCar &&other);
    HybridCar &operator=(const HybridCar &other);
    HybridCar &operator=(HybridCar &&other);

    void chargeBattery(float amount);
    void addFuel(float amout);
    void accelerate();

    ~HybridCar();
};