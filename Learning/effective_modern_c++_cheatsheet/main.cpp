/**
 *                                           Terms
 * 
 * 1. lvalue: typically an expression whose address can be taken e.g a variable name (auto x = 10;)
 * 2. rvalue: an expression whose address cannot be taken.
 * 3. lvalue-reference: reference to an lvalue type denoted by & (auto &x = xVal;)
 * 4. rvalue-reference: reference to an rvalue type typically denoted by && e.g auto&& rvalue_ref = 10;
 * 5. copy-operations: copy-construct from lvalues using copy-constructor and copy-assignment operator
 * 6. move-operations move-construct from rvalues using move-constructor and move-assignment operator
 * 7. arguments: expressions passed to a function call at call site (could be either lvalues or rvalues)
 * 8. parameters: lvalue names initialized by arguments passed to a function e.g x in void foo(int x);
 * 9. callable objects: objects supporting member operator() e.g functions, lambdas, std::function etc
 * 10. declarations: introduce names and types without details e.g class Widget;, void foo(int x);
 * 11. definitions: provide implementation details e.g class Widget { ... };, void foo(int x) { ... }
 */
#include <iostream>
#include <typeinfo>
#include <boost/type_index.hpp>

template <class T>
void foo(T param) {
    std::cout << "\n Readable name: " << boost::typeindex::type_id<T>().pretty_name() <<std::endl;
}

int main()
{
    /*
            Item 1: Understand template type deduction
            
        Deduced type of T doesn't always match that of the parameter (i.e ParamType) in template functions
        For lvalue-refs/rvalue-refs, compiler ignores the reference-ness of an arg when deducing type of T
        With universal-refs, type deduction always distinguishes between l-value and r-value argument types
        With pass-by-value, reference-ness, const and volatile are ignored if present in the ParamType
        Raw arrays [] and function types always decay to pointer types unless they initialize references
    */
   int x = 20;
   auto &ref = x;
   foo(ref);
   return 0;
}
