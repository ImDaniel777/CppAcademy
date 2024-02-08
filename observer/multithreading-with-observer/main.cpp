#include <iostream>
#include "CarEcu.hpp"
#include "InjectionSystem.hpp"
#include "BrakingSystem.hpp"
#include <thread>
#include <chrono>

void simulateCarEcu(CarEcu &carEcu)
{
    std::cout<<"Car engine on\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));

}

void printBrakingInfo(BrakingSystem *brakingSystem)
{
    std::cout<<"Getting brakes informations\n";
    for(int i = 0; i < 100; i++)
    {
        std::cout<<brakingSystem->getBrakingHelp()<<'\n';
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void printInjectionInfo(InjectionSystem *injectionSystem)
{
    std::cout<<"Getting injection informations\n";
    for(int i = 0; i < 100; i++)
    {
        // std::cout<<injectionSystem->getEngineLoad()<<'\n';
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main()
{
    CarEcu carEcu{};

    BrakingSystem *brakingSystem = new BrakingSystem();
    InjectionSystem *injectionSystem = new InjectionSystem();

    carEcu.subscribe(brakingSystem);
    carEcu.subscribe(injectionSystem);

    std::thread mainThread(simulateCarEcu, std::ref(carEcu));
    std::thread brakesThread(printBrakingInfo, (brakingSystem));
    std::thread injectionThread(printInjectionInfo, (injectionSystem));

    mainThread.join();
    brakesThread.join();
    injectionThread.join();
    return 0;
}