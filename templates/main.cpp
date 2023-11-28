// Templates allow us to write functions that can operate on any data type
// similay to generics in Typescript
#include <iostream>
#include <cstring>
#include "Integer.h"

template<typename T>
T Max(T x, T y){
    return x > y ? x : y;
} 

// explicit instantiation
template char Max(char x, char y);

// explicit specialization
template<> const char *Max<const char *>(const char *x, const char *y){
    std::cout <<"Max<const char*>()"<<std::endl;
    return x;
}
template<int size>
void Print(){
    char buffer[size];
    std::cout<<size<<std::endl;
}

/*
    Non-type template arguments
    1. Expressions that are computete at compile time
    2. Must be a constant expression: addresses, references, integrals, nullptr, enums.
*/
// USING THIS WE CAN PASS ARRAYS TO FUNCTIONS WITHOUT SPECIFYING SIZE
template<typename T, int size>
T Sum(T (&parr)[size]){
    T sum{};
    for(int i = 0; i < size; i++){
        sum += parr[i];
    }
    return sum;
}

class Employee {
    std::string _Name;
    Integer _Id;

    public:
    // Employee(const std::string &name, const Integer &id) : 
    //     _Name{name}, //Copy constructor invoked
    //     _Id(id){ //Copy constructor invoked
    //         std::cout<<"Employee(&, &)"<<std::endl;
    //     }
    template<typename T1, typename T2>
    Employee(T1 &&name, T2 &&id) :
        _Name{std::forward<T1>(name)},
        _Id{std::forward<T2>(id)}{ //Still the copy constructor is invoked without std::move
            std::cout<<"Employee(&&, &&)"<<std::endl;
        }
};

/*
    Variadic templates
    - used for writing functions that can accept any type/number of arguments
*/

// template <typename T>
// void Print(std::initializer_list<T> args){
//     for(const auto &x : args){
//         std::cout<<x<<" ";
//     }
// }

void Print(){
    
}
//Template parameter pack
template <typename T, typename...Params>
// Function parameter pack
void Print(T a, Params... args){
    //must use recursion
    Print(args...);
}
/*
Number of arguments is reduced by 1 for every call
In the last case we will have 0 args => compiler searcher for a function with 0 args
That will be the base function
1. Print(1, 2.5, "4")
2. Print(2.5, "4")
*/
int main(){
    // Employee emp1{"daniel", 100};
    // std::string name = "Daniel";
    // Integer val{100};
    // Employee emp3{std::string{"Dan"}, val};

    Print(1, 2.5, "3");
    return 0;
}