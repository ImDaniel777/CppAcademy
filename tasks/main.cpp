#include <iostream>
#include "Audi.h"
#include "Tesla.h"
#include "Toyota.h"
#include "Utils.h"
/***
 * This class is used to demonstrate the cases when the compiler creates 
 * the copy constructor, move constructor, copy assignment, move assignment and destructor
*/
class AudiFamily
{
    Audi audi;
public:
    AudiFamily(std::string  &VIN) : audi(VIN){}
};

AudiFamily createAudi(std::string  &VIN)
{
    AudiFamily a(VIN);
    return a;
}
int main()
{
    Toyota t = Toyota();
    
    // std::unique_ptr<Tesla> &myTesla = Tesla::getInstance();
    // std::unique_ptr<Tesla> &mySecondTesla = Tesla::getInstance();
    return 0;
}
/**
 * @brief 
 * 
 * Constructors/destructors calling order:
 * Base constructor => derived constructor => derived destructor => base destructor
 */