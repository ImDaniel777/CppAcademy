#include "Interfaces.h"
#include "Car.h"
#include <memory>
class Tesla : public Car, public ElectricCarInterface 
{
private:
    Tesla();
    static int n;
public:
    static Tesla &getInstance();

    Tesla (const Tesla &obj) = delete;
    Tesla &operator=(const Tesla &obj) = delete;
    
    void chargeBattery(float amount) override;
    void accelerate() override;
    ~Tesla();
};