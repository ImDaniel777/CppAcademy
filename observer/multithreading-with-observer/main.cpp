#include <iostream>
#include "CarEcu.hpp"
#include "InjectionSystem.hpp"
#include "BrakingSystem.hpp"
#include <thread>
#include <chrono>
#include <mutex>

std::mutex mtx;

void simulateCarEcu(CarEcu &carEcu)
{
    std::cout<<"Car engine on\n";
    for(int i = 0; i < 100; ++i)
    {
        {
            std::lock_guard<std::mutex>lock(mtx);
            carEcu.setSpeed(i*1.5);
            carEcu.setThrottle(i*1.5);
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

}

void printBrakingInfo(BrakingSystem *brakingSystem, CarEcu &carEcu)
{
    std::cout<<"Getting brakes informations\n";
    for(int i = 0; i < 100; ++i)
    {
        {
            std::lock_guard<std::mutex> lock(mtx);
            std::cout<<"Braking help: "<<brakingSystem->getBrakingHelp()<<" for car speed: "<<carEcu.getSpeed()<<'\n';
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void printInjectionInfo(InjectionSystem *injectionSystem, CarEcu &carEcu)
{
    std::cout<<"Getting injection informations\n";
    for(int i = 0; i < 100; ++i)
    {
        {
            std::lock_guard<std::mutex> lock(mtx);
            std::cout<<"Engine load: "<<injectionSystem->getEngineLoad()<<" for throttle: "<<carEcu.getThrottle()<<'\n';
        }
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
    std::thread brakesThread(printBrakingInfo, (brakingSystem), std::ref(carEcu));
    std::thread injectionThread(printInjectionInfo, (injectionSystem), std::ref(carEcu));

    mainThread.join();
    brakesThread.join();
    injectionThread.join();
    return 0;
}