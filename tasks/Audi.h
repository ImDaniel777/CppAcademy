#include "Car.h"
#include "Interfaces.h"

class Audi : public Car
{
private:
    std::string model;
public:
    Audi();
    void accelerate() override; /* If it will not find a function with the same signature in the base class it will throw error */
    ~Audi();
};