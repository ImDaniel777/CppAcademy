#include <iostream>
#include "PetrolCar.h"
#include "ElectricCar.h"
#include "HybridCar.h"
#include "Utils.h"
/***
 * This class is used to demonstrate the cases when the compiler creates 
 * the copy constructor, move constructor, copy assignment, move assignment and destructor
*/
class PetrolCarFamily
{
    PetrolCar car;
public:
    PetrolCarFamily(std::string  &VIN) : car(VIN){}
};

PetrolCarFamily createAudi(std::string  &VIN)
{
    PetrolCarFamily a(VIN);
    return a;
}
int main()
{

    // std::unique_ptr<Car> car(new PetrolCar());

    // ElectricCar &electricCar = ElectricCar::getInstance();
    // ElectricCar &anotherElectricCar = ElectricCar::getInstance();

    // std::cout<<&electricCar<<std::endl;
    // std::cout<<&anotherElectricCar<<std::endl;

    std::string vin = "1GEWAG7WEAG6AW";
    PetrolCar petrolCar1{vin};

    auto petrolCar2{petrolCar1}; /* Copy constructor */
    petrolCar2 = petrolCar1; /* Copy assignment operator */

    PetrolCar petrolCar3{vin};

    auto petrolCar4{std::move(petrolCar3)}; /* Move constructor */
    petrolCar4 = std::move(petrolCar3);

    // int x = 10, y = 20;
    // Utils::swap(x, y);
    return 0;
}
/**
 * @brief 
 * 
 * Constructors/destructors calling order:
 * Base constructor => derived constructor => derived destructor => base destructor
 */