#include <iostream>
#include <mutex>
#include <future>
#include <thread>
#include <list>
#include "header.h"

#define MAX_LEN 100

std::list<int> data;
extern int x;
std::mutex mtx;

void process_data_1(int &value)
{
    std::unique_lock<std::mutex> lock(mtx);

    std::cout<<"Value before process_data_1() "<<value<<'\n';
    for(int i = 0; i < MAX_LEN; i++)
    {
        value++;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    std::cout<<"Value after process_data_1() "<<value<<'\n';
}

void process_data_2(int &value)
{
    std::unique_lock<std::mutex> lock(mtx);

    std::cout<<"Value before process_data_2() "<<value<<'\n';
    for(int i = 0; i < MAX_LEN; i++)
    {
        value++;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    std::cout<<"Value after process_data_2() "<<value<<'\n';
}

int main()
{
    std::thread th1{process_data_1, std::ref(x)};
    std::thread th2{process_data_2, std::ref(x)};

    /*
        Packaged task invokes a function async.
        It creates a future object
    */

    th1.join();
    th2.join();

    std::cout<<data.size()<<'\n';
    std::cout<<x<<'\n';
    return 0;
}