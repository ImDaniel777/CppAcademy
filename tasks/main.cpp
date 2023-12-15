#include <iostream>
// #include "Audi.h"
#include "Tesla.h"
int main()
{
    // const char *audiVIN = "TMBEAF312QWAA2A3A3";
    // Audi rs6 = Audi(); 

    std::unique_ptr<Tesla> &myTesla = Tesla::getInstance();
    std::unique_ptr<Tesla> &mySecondTesla = Tesla::getInstance();
    return 0;
}
/**
 * @brief 
 * 
 * Constructors/destructors calling order:
 * Base constructor => derived constructor => derived destructor => base destructor
 */