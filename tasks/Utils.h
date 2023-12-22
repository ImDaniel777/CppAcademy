#include <iostream>

class Utils
{
private:
    Utils() = delete;
    ~Utils() = delete;
public:

    static void customPrinting(std::string message);
    template<typename T>
    static void swap(T &x, T &y)
    {
        auto temp = x;
        x = y;
        y = temp;
    }
    
};