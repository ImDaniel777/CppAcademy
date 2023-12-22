#include "Utils.h"
#include "Car.h"
#include <typeinfo>

void Utils::customPrinting(std::string message)
{
    std::cout<<"I'm not printing your message xd"<<std::endl;
}

// template<typename T1, typename T2>
// void Utils::swap(T1 &x, T2 &y)
// {
//     x^=y^=x^=y;
// }
// template void Utils::swap<int, int>(int&, int&); // explicit instantiation of template OR move the code to header file
