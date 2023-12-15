#include <iostream>
#include "Car.h"

Car::Car()
{
    std::cout<<"Car constructor"<<std::endl;
}
Car::Car(char *VIN) 
    : VIN(VIN){

}

Car::~Car()
{
    std::cout<<"Car destructor"<<std::endl;
}