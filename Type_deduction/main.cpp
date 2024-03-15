#include <iostream>
#include <vector>
/* PRIOR KNOWLEDGE NEEDED: LVALUES, RVALUES AND REFERENCES */

/**
 * @brief TEMPLATE TYPE DEDUCTION (ONLY FOR FUNCTIONS, CLASS TEMPLATES DOES NOT HAVE TYPE DEDUCTION)
 * 
 * template <typename T>
 * func(ParamType param)
 * {}
 * func(exp) => How is T and ParamType deduced from exp ?
 * 
 * We have 3 cases:
 *  1. ParamType is a reference or a pointer, but not a universal reference (&&)
 *  2. ParamType is a Universal Reference
 *  3. ParamType is neither a reference nor a pointer (pass by value)
 */

/**
 * @brief Case 1 : ParamType is a reference or a pointer, but not a universal reference
 * 
 *  The way we declare the ParamType affects how T is deduced.
 *  If exp type is a reference, ignore it.
 *  If we have more params (T& param1, const T& param2) and the deduced types for T are not the same, the template will not compile and it is not instantiated! 
 */
template <typename T>
void func_1(T& param){} 

/* AUTO PLAYS THE ROLE OF T */
int x = 10;
const int const_x = x;
const int& const_ref_x = x;

auto& v1 = x; /* v1 type is int&, auto is int */
auto& v2 = const_x; /* v2 type is const int&, auto is const int */
auto& v3 = const_ref_x; /* v3 type is const int&, auto is const int */

const auto& v4 = x; /* v4 is const int&, auto is int */
const auto& v5 = const_x; /* v5 is const int&, auto is const int */
const auto& v6 = const_ref_x; /* v6 is const int&, auto is const int */

/**
 * @brief Case 2: ParamType is a universal reference
 * 
 * Treated like normal references, except:
 *  When exp type is lvalue with deduced type E, T is deduced as E&. ###### THIS IS THE ONLY PLACE IN C++ WHERE A DEDUCED TYPE IS A REFERENCE
 *  => reference collapsing yields param type is E&
 *  When we are dealing with universal references, T will SOMETIMES be deducted as a reference
 */
template <typename T>
void func_2(T&& param){}


/**
 * @brief Case 3: Pass by value
 * 
 * We dont care about type qualifiers because we are creating a new object (a copy).
 * If exp is a reference, ignore it.
 * If exp is const or volatile, ignore it.
 */
template <typename T>
void func_3(T param){}
/* Again, auto plays the role of T */
auto v7 = x; /* NEW OBJECT, auto is int, v7 type is int */
auto v8 = const_x; /* NEW OBJECT, auto is int, v8 type is int */
auto v9 = const_ref_x; /* NEW OBJECT,  auto is int, v9 is int */
/* Auto never deduced to be a reference
    It must be manually added
        If present, use by-reference rules
*/
auto v10 = const_ref_x; /* v10 type is int */
auto& v11 = const_ref_x; /* v11 type is const int& */
auto&& v12 = const_ref_x; /* v12 type is const int& (exp is lvalue) */

/**
 * @brief AUTO type deduction
 * 
 * Same as template type deduction, except for braced initialisation.
 *  Template type deduction fails.
 *  Auto deduces std::initializer_list
 *  A BRACED INITIALIZER DOES NOT HAVE A TYPE!!!
 */
template <typename T>
void func_4(T param){}

auto br1 = {1, 2, 3}; /* This works, type is std::initializer_list<int> */
auto br2 = {1}; /* Also std::initializer_list<int>*/
auto br3 {1}; /* int */
//auto br3 {1, 2, 3}; /* error in c++17 */

/**
 * @brief Decltype type deduction
 * 
 * Decltype works on expressions, auto works on types.
 * decltype(some expr of type T) = T&
 * 
 * Names are lvalues, but decltype(name) rule beats decltype(lvalue) rule.
 */
// decltype (x); /* = int, x is lvalue expression, but also name => name rule prevails */
// decltype ((x)); /* = int& (x) is lvalue expression, but not a name*/

/**
 * @brief Function return type deduction
 * 
 * For auto use template(not auto) rules!
 *   => No type deduced for braced initializers
 * For decltype(auto) use delcltype rules!
 * 
 * Auto return type gives a copy
 * decltype(auto) gives reference
 */
auto lookUpValue(char information)
{
    static std::vector<int> v{1,2,3};
    int idx = 0; //computed
    return v[idx];
    /*
        Returns a new copy, modifying it wont modify the value from the vector
        decltype(auto) would return int& which would allow to modify the value from vector
        lookUpValue(information) = 5; should not compile!
    */
}

decltype(auto) authorizeAndIndex(std::vector<int> &x, int idx)
{
    //authorize();
    return x[idx];
    /*
        This returns int& which allows to be modified (desired behaviour)
        auto would return int, a new copy and would modify that copy, not the vector.
        authorizeAndIndex(v, 10) = 5; should compile!
    */
}
/* DECLTYPE(AUTO) IS SENSITIVE TO FUNCTION IMPLEMENTATION 

    RULES:
        1. Use auto when a reference type would never be correct. (reference is not needed)
        2. Use decltype(auto) only if a reference type would be correct.
            => "Perfect returning"
*/

decltype(auto) lookUp(char context)
{
    static std::vector<int> v{1,2,3};
    int idx = 0;
    auto ret = v[idx]; /* This creates a new object of type int */

    return ret; /* This returns an int (new object) */
    // return (ret); /* This returns an int& (reference to the local variable ret) because (ret) is an expression */
}

int main()
{
    func_1(x); /* T is int, ParamType is int& */
    func_1(const_x); /* T is const int, ParamType is const int& */
    func_1(const_ref_x); /* T is const int, ParamType is const int& */

    func_2(x); /* exp is lvalue with deduced type int => T is int&, ParamType is int&*/
    func_2(const_x); /* exp is lvalue with deduced type const int => T is const int&, ParamType is const int& */
    func_2(const_ref_x); /* exp is lvalue with deduced type const int => T is const int&, ParamType is const int& */
    func_2(10); /* exp is rvalue => no special case, ParamType is int&& (rvalue reference), T is int */

    func_3(x); /* T is int, ParamType is int */
    func_3(const_x); /* T is int, ParamType is int */
    func_3(const_ref_x); /* T is int, ParamType is int */

    /* 
        This will not compile
    func_4({1,2,3});
    */
    std::cout<<typeid(br2).name()<<'\n';
    return 0;
}