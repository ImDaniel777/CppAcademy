// Templates allow us to write functions that can operate on any data type
// similay to generics in Typescript
#include <iostream>
#include <cstring>
#include "Integer.h"
#include <list>
#include <vector>

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

// Base function for variadic template
void Print(){

}
//Template parameter pack
// template <typename T, typename...Params>
// Function parameter pack
// void Print(T &&a, Params&&... args){
//     //must use recursion
//     std::cout<<sizeof...(args)<<std::endl;
//     std::cout<<a<<" ";
//     Print(std::forward<Params>(...)); //This is needed because if we pass an R value, it will be converted to L value here, so by using this we perfect forward 
// }
/*
Number of arguments is reduced by 1 for every call
In the last case we will have 0 args => compiler searcher for a function with 0 args
That will be the base function
1. Print(1, 2.5, "4")
2. Print(2.5, "4")
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    Class Templates
*/

template<typename T, int size>
class Stack {
    T _buffer[size];
    int _top{-1};
public:
    Stack() = default;
    Stack(const Stack &obj){
        _top = obj._top;
        for(int i = 0; i <= _top; ++i){
            _buffer[i]=obj._buffer[i];
        }
    }
    void Push(const T &element){
        _buffer[++_top] = element;
    }
    void Pop();
    const T &Top() const{
        return _buffer[_top];
    }
    bool isEmpty() const{
        return _top == -1;
    }

    static Stack Create();
};

template<typename T, int size>
void Stack<T, size>::Pop(){
    --_top;
}
template<typename T, int size>
Stack<T, size> Stack<T, size>::Create(){ //cant use shorthand notation (Stack) because it is outside class
    return Stack<T, size>();
}

// Class template explicit specialization

// template<typename T>
// class PrettyPrinter{
//     T *_pData;

// public:
//     PrettyPrinter(T *data) : _pData(data){

//     }
//     void Print(){
//         std::cout<<"{" << *_pData <<std::endl;
//     }
//     T *GetData(){
//         return _pData;
//     }
// };

// Specific specialization of the PrettyPRinter class for char* type
// template<>
// class PrettyPrinter<char*>{
//     char *_pData;

// public:
//     PrettyPrinter(char *data) : _pData(data){

//     }
//     void Print(){
//         std::cout<<"{" << *_pData <<std::endl;
//     }
//     char *GetData(){
//         return _pData;
//     }
// };

/////////////////////////////////////// Partial specialisation //////////////////////////////////////
 template<typename T, int columns>
 class PrettyPrinter {
    T *_pData;

public:
    PrettyPrinter(T *data) :_pData(data){

    }
    void Print(){
        std::cout<<"columns:"<<columns<<std::endl;
        std::cout<<"{"<<*_pData<<"}"<<std::endl;
    }

    T * GetData(){
        return _pData;
    }
 };

 template<typename T>
 class PrettyPrinter<T, 80> {
    T *_pData;

public:
    PrettyPrinter(T *data) :_pData(data){

    }
    void Print(){
        std::cout<<"Using 80 columns"<<std::endl;
        std::cout<<"{"<<*_pData<<"}"<<std::endl;
    }

    T * GetData(){
        return _pData;
    }
 };
///////////////////////////////////////////////////////////////////////////////
 template<typename T>
 class SmartPointer{
    T *_ptr;
public:
    SmartPointer(T *ptr) : _ptr(ptr){

    }

    T * operator ->(){
        return _ptr;
    }
    T & operator *(){
        return *_ptr;
    }
    ~SmartPointer(){
        delete _ptr;
    }
 };

  template<typename T>
 class SmartPointer<T[]>{
    T *_ptr;
public:
    SmartPointer(T *ptr) : _ptr(ptr){

    }

    T & operator[](int index){
        return _ptr[index];
    }

    ~SmartPointer(){
        delete []_ptr;
    }
 };
 /**
  * TYPEDEF unsigned int UINT;
  * 
  * TYPEALIAS -> USING UINT = unsigned int;
  * 
 */

// typedef const char *(*PFN)(int);
using PFN = const char *(*)(int);
void ShowError(PFN pfn){}

// typedef std::vector < std::list<std::string>> Names;
using Names = std::vector<std::list<std::string>>;
int main(){
    // Employee emp1{"daniel", 100};
    // std::string name = "Daniel";
    // Integer val{100};
    // Employee emp3{std::string{"Dan"}, val};

    // Print(1, 2.5, "3");

    // Stack<float, 10> s = Stack<float, 10>::Create();
    // s.Push(1);
    // s.Push(2);
    // s.Push(3);

    // auto s2(s);
    // while(!s2.isEmpty()){
    //     std::cout<<s2.Top()<<" ";
    //     s2.Pop();
    // }

    // int data = 5;
    // float f = 8.2f;
    // PrettyPrinter<int> p1(&data);
    // p1.Print();

    int data = 800;
    PrettyPrinter<int, 40> p{&data};

    p.Print();

    SmartPointer<int[]> s1{new int[5]};
    s1[0] = 5;
    std::cout<<s1[0]<<std::endl;

    return 0;
}