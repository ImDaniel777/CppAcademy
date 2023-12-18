#include <iostream>
#include "Audi.h"
#include "Tesla.h"
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
    std::string audiVIN = "aevewma49tgwa";
    Audi rs6 = Audi(audiVIN); 
    std::cout<<rs6.getVIN()<<std::endl;
    auto rs7{rs6};
    std::cout<<rs7.getVIN()<<std::endl;
    rs7.setVIN("3wafs");
    std::cout<<rs7.getVIN()<<std::endl;
    // std::cout<<a4.getVIN()<<std::endl;
    // auto a5{static_cast<Audi &&>(rs6)};
    // AudiFamily a1{"awfwa"};
    // auto a2{a1};
    // a2 = a1;

    
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