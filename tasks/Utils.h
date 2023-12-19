#include <iostream>

class Utils
{
private:
    Utils() = delete;
    ~Utils() = delete;
public:

    static void customPrinting(std::string message);
};