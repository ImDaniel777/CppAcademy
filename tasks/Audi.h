#include "Car.h"
#include "Interfaces.h"
#include <vector>
class Audi : public Car
{
private:
    std::string model;
public:
    Audi();
    Audi(std::string  &VIN);
    using Car::Car;
    Audi(const Audi &obj);
    Audi(Audi &&obj);
    Audi &operator=(const Audi &obj);
    Audi &operator=(Audi &&obj);

    void accelerate() override; /* If it will not find a function with the same signature in the base class it will throw error */
    void addModification(std::string mod);
    ~Audi();
};