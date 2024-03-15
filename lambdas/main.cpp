#include <iostream>
#include <vector>
#include <functional>

/**
 * @brief Avoid default capture mode    
 * 
 * Default by-reference capture: can lead to dangling references
 * Default by-value capture:
 *      - Seemingly prevents dangling references, but doesn't.
 *      - Seemingly guarantees self-contained closures, but doesn't.
 * 
 * Can't capture static variables.  
 * 
 * A lambda's type is copyable, movable, or neither, depending if the captures are copyable, movable..
 */

using FilterContainer = std::vector<std::function<bool(int)>>;
FilterContainer filters;

void addDivisorFilter(int divisor)
{
    filters.emplace_back(
        [=](int value) { std::cout<<divisor<<'\n'; return value % divisor == 0; } /* divisor will dangle here after we leave the addDivisorFilter() */
    );
}

bool test_filters(int value)
{
    for (auto filter : filters)
    {
        if (filter(value) == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int x = 10;
    addDivisorFilter(5);

    std::cout<<test_filters(x)<<'\n';


    return 0;
}