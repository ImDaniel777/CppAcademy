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
    void operator=(const Tesla &obj) = delete;
    void chargeBattery(int amount) override;
    void accelerate() override;
    ~Tesla();
};