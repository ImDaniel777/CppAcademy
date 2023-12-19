#include "Interfaces.h"
#include "Car.h"
#include <memory>
class Tesla : public Car, public ElectricCarInterface 
{
private:
    static std::unique_ptr<Tesla> instance;
    struct _cons {explicit _cons() = default; };

public:

    Tesla(_cons);

    static std::unique_ptr<Tesla> &getInstance();
    static std::unique_ptr<Tesla> instanceFactory();

    Tesla (Tesla &obj) = delete;
    Tesla (Tesla &&obj) = delete;
    Tesla &operator=(const Tesla &obj) = delete;
    Tesla &operator=(Tesla &&obj) = delete;
    
    void chargeBattery(float amount) override;
    void accelerate() override;
    ~Tesla();
};