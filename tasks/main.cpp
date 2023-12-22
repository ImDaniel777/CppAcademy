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

    PetrolCar a;
    a.addModification("stage_1");
    a.addModification("stage_2");
    a.printModifications();
    auto a5{a};
    // a5.printModifications();
    return 0;
}
/**
 * @brief 
 * 
 * Constructors/destructors calling order:
 * Base constructor => derived constructor => derived destructor => base destructor
 */