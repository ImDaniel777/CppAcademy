#include <iostream>
#include <memory>
class Singleton
{
    Singleton() {}
    ~Singleton() {}

    std::string data;
public:
    /*
    Static function objects are initialized when control flow hits the function for the first time.
    The lifetime of function static variables begins the first time the program flow encounters the declaration and ends at program termination.
    If control enters the declaration concurrently while the variable is being initialized, the concurrent execution shall wait for completion of the initialization.
    */
    static Singleton &createInstance()
    {
        static Singleton instance;
        return instance;
    }

    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;
};

class BreaksInterface
{
public:
    virtual void printBreaksType() = 0;
    virtual void applyBrakes() = 0;

};

class DrumBrakes : public BreaksInterface
{
public:
    std::string _name;

    void printBreaksType() override {
        std::cout<<"Drum breaks"<<'\n';
    }
    
    void applyBrakes()
    {
        std::cout << "Applying drum brakes" << '\n';

    }
};
class DiscBrake : public BreaksInterface
{
public:
    std::string _name;

    void printBreaksType() override {
        std::cout<<"Disc breaks"<<'\n';
    }

    void applyBrakes()
    {
        std::cout << "Applying disc brakes" << '\n';

    }
};

class CockpitInterface
{
public:
    virtual void printCockpitType() = 0;
};

class Car
{
public:
    std::string VIN;
};

class VirtualCockpit : CockpitInterface
{
public:
    void printCockpitType() override
    {
        std::cout<<"Virtual cockpit"<<'\n';
    }
};

class AnalogCockpit : CockpitInterface
{
public:
    void printCockpitType() override
    {
        std::cout<<"Analog cockpit"<<'\n';
    }
};

class AbstractCarFactory
{
public:
    virtual Car createCar() = 0;
};

class SimpleCarFactory : public AbstractCarFactory
{
public:
    Car createCar() override {
        // Implementation goes here
        return Car();
    }
};

class LuxuryCarFactory : public AbstractCarFactory
{
public:
    Car createCar() override {
        // Implementation goes here
        return Car();
    }
};


int main()
{
    // auto &s1 = Singleton::createInstance();
    // Singleton &s2 = s1;
    // std::cout<<&s1<<' '<<&s2<<'\n';
    std::unique_ptr<AbstractCarFactory> absCarFactory{new LuxuryCarFactory()};

    auto audi = absCarFactory->createCar();
    return 0;
}