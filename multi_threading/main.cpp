#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>
#include <cmath>
#include <future>

using namespace std;
#define ITERATIONS 1E6

// void work(int &count, mutex &mtx)
// {
//     for(int i = 0; i < ITERATIONS; i++)
//     {   
//         lock_guard<mutex> guard(mtx);
//         ++count;
//     }
// }

class App
{
private:
    int count = 0;
    mutex mtx;
public:
    void operator()()
    {
        for(int i = 0; i < ITERATIONS; i++)
        {   
            lock_guard<mutex> guard(mtx);
            ++count;
        }
    }

    int getCount()const{
        return count;
    }
};

double calculatePi(int terms)
{
    double sum = 0;

    if(terms < 1)
    {
        throw runtime_error(" Number of terms cannot be less than 1");
    }
    for(int i = 0; i < terms; i ++)
    {
        int sign = pow(-1, i);
        double term = 1.0 / (i * 2 + 1);
        sum += sign*term;
    }
    return sum * 4;
}
int main()
{
    // App app;
    
    // thread t1(ref(app));
    // thread t2(ref(app));

    // t1.join();
    // t2.join();

    // cout<<app.getCount()<<endl;

    promise<double> promise;

    auto doCalculation = [&](int terms){
        try
        {
            auto result = calculatePi(terms);
            promise.set_value(result);
        }
        catch(...)
        {
            promise.set_exception(current_exception());
        }
    };
    
    thread t1(doCalculation, 0);

    future<double> future = promise.get_future();
    try
    {
        cout<<future.get()<<endl;
    }
    catch(const exception &e)
    {
        cout<<e.what()<<endl;
    }
    t1.join();


    return 0;
}