#include <iostream>
#include "Audi.h"

Audi::Audi()
{
    std::cout<<"Audi constructor"<<std::endl;
}

void Audi::accelerate()
{
    std::cout<<"Audi acceleration"<<std::endl;
}
Audi::~Audi()
{
    std::cout<<"Audi destructor"<<std::endl;
}