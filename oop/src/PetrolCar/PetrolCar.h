#include "../Car/Car.h"
#include "../Interfaces/Interfaces.h"
#include <vector>
class PetrolCar : public Car
{
private:
    std::string model;
    std::vector<std::string> *mods = new std::vector<std::string>();
public:
    PetrolCar();
    PetrolCar(std::string  &VIN);
    // using Car::Car;
    PetrolCar(const PetrolCar &obj);
    PetrolCar(PetrolCar &&obj);
    PetrolCar &operator=(const PetrolCar &obj);
    PetrolCar &operator=(PetrolCar &&obj);

    void accelerate() override; /* If it will not find a function with the same signature in the base class it will throw error */
    void addModification(std::string mod);
    void printModifications()const;
    ~PetrolCar();
};