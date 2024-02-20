#include <iostream>

template <typename T1, char>
class MyClass
{
public:
    T1 sum(T1 &);
private:
    T1 val = 0;
};

template<typename T1>
T1 MyClass<T1, char>::sum(T1 &value)
{
    return val+value;
}
int main(int argc, char **argv)
{
    MyClass<int> cls;
    int value = 10.5;
    std::cout<<cls.sum(value);
    return 0;
}