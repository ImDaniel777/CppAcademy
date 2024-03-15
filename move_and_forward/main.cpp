
#include <iostream>
#include <functional>
#include "../Integer.h"
/**
 * @brief Universal and rvalue references
 * 
 *  In type&&, && means either:
 *      Rvalue reference:
 *          - bind rvalues only
 *          - facilitates moves
 *      Universal reference:
 *          - rvalue OR lvalue reference
 *          - syntactically type &&, but semantically either & or &&
 *          - bind lvalue, rvalue, const..EVERYTHING
 *          - may facilitate copy, may facilitate move
 *          - same as Forwarding Reference
 * 
 *      !!! Universal reference: presence of && AND type ENTIRELY DEDUCED !!!
 * 
 *      NOT ALL T&& IN TEMPLATES ARE UREFS!
 * 
 *      template <class T, class Allocator<allocator<T>>
 *      class vector
 *      {
 *          public: 
 *              void push_back(T&& x); not universal reference, T is not deduced, it comes from vector<T>
 *              template<class... Args>
 *              void emplace_back(Args&&... args); this is universal reference, Args is deduced
 *      }
 *  
 *      std::vector<int> vec; => T is int
 *      vec.push_back(10.5); arg is double, but parameter is int
 *      vec.emplace_back(10.5); arg is double, parameter is double&&
 * 
 *      !!!!
 *      push_back vs emplace_back, last one directly creates object in the vector, uses URefs
 * 
 */
// void test(int&& x); // rvalue reference
// int&& x = 5;    // rvalue reference
// auto&& y = 5; // not rvalue reference
// template <typename T>
// void test(std::vector<T>&& vec); // rvalue reference
// template <typename T>
// void test(T&& arg); // not rvalue reference

// template <typename T>
// void test(const T&& arg); // Rref, not Uref, const is not deduced


/**
 * @brief std::move and std::forward
 * 
 * What they dont dont do?
 *  std::move does not move.
 *  std::forward does not forward.
 *  Neither generates code.
 * 
 * They are simply casts.
 *  std::move unconditionally casts to rvalue
 *  std::forward conditionally casts to rvalue
 */

/* std::move implementation */
// template <typename T>
// typename remove_reference<T>::type&& before c++14
// decltype(auto) move(T&& param)
// {
//     using ReturnType = remove_reference_t<T>&&; //c++14
//     return static_cast<ReturnType>(param); // just a cast
// }
/* std::forward => if we pass lvalue reference - do nothing, else, cast to rvalue*/
struct Person
{
    Integer _id;
    std::string _name;
    // Person(Integer &id, std::string& name) : _id(id), _name(name){}
    template <typename T1, typename T2>
    Person(T1&& id, T2&& name) : _id(std::forward<Integer>(id)), _name(name) {}
};

template <typename T>
void func(T&& arg)
{
    process(arg);
}
int main()
{
    int x, a, b;
    // std::function<int(int)> ret = [a,b](int x){ return x*x +a/2 + b;}; // closure could be on heap
    // or
    // auto rett = [a,b](int x){ return x*x +a/2 + b;}; // closure not on heap

    Integer n(10);
    Person pers(std::move(n), std::string("DAniel"));

}