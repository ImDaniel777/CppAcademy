#include <iostream>
#include "PetrolCar.h"

PetrolCar::PetrolCar()
{
    std::cout<<"PetrolCar constructor"<<std::endl;
}

PetrolCar::PetrolCar(std::string  &VIN) : Car(VIN)
{
    std::cout<<"PetrolCar param constructor"<<std::endl;

}

PetrolCar::PetrolCar(const PetrolCar &obj)
{
    std::cout<<"PetrolCar(const PetrolCar&)"<<std::endl;
    _VIN = new std::string(*obj._VIN);
    mods = obj.mods;
}

PetrolCar::PetrolCar(PetrolCar &&obj)
{   
    std::cout<<"PetrolCar(PetrolCar &&)"<<std::endl;
    _VIN = obj._VIN;
    obj._VIN = nullptr;
}

PetrolCar &PetrolCar::operator=(const PetrolCar &obj)
{
    std::cout<<"operator=(const PetrolCar &obj)"<<std::endl;
    if(this != &obj)
    {
        delete _VIN;
        _VIN = new std::string(*obj._VIN);
    }
    return *this;
}

PetrolCar &PetrolCar::operator=(PetrolCar &&obj)
{
    std::cout<<"operator=(PetrolCar &&obj)"<<std::endl;
    if(this != &obj)
    {
        delete _VIN;
        _VIN = obj._VIN;
        obj._VIN = nullptr;
    }
    return *this;
}

void PetrolCar::accelerate()
{
    std::cout<<"PetrolCar acceleration"<<std::endl;
}

void PetrolCar::addModification(std::string mod)
{
    mods->emplace_back(mod);
}

void PetrolCar::printModifications()const
{
    for(auto mod: *mods)
    {
        std::cout<<mod<<std::endl;
    }
}

PetrolCar::~PetrolCar()
{
    std::cout<<"PetrolCar destructor"<<std::endl;
    delete _VIN;
}