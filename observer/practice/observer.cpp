#include <iostream>
#include <list>

#define MAX_THROTTLE_POSITION 100

struct EcuData
{
    float throttle = 0;
    float carSpeed = 0;
};

class IObserver
{
public:
    virtual ~IObserver(){}
    virtual void update(EcuData &ecuData) = 0;
};


class IObservable
{
public:
    virtual ~IObservable(){}
    virtual void subscribe(IObserver *observer) = 0;
    virtual void unsubscribe(IObserver *observer) = 0;
    virtual void notify() = 0;
};

class CarECU : public IObservable
{
public:
  void subscribe(IObserver *observer)
  {
    observers.push_back(observer);
  } 
  void unsubscribe(IObserver *observer)
  {
    observers.remove(observer);
  }
  void notify()override
  {
    for(auto *observer: observers)
    {
        observer->update(data);
    }
  }
  void setCarSpeed(float value)
  {
    data.carSpeed = value;
    notify();
  }

  void setThrottle(float value)
  {
    data.throttle = value;
    notify();
  }
private:
    std::list<IObserver*>observers;
    EcuData data;
};

class Sensor : public IObserver
{
public:
    void update(EcuData &data)override
    {
        std::cout<<"Sensor updated\n";
        updateEngineLoad(data.throttle);
    }
    void updateEngineLoad(float throttle)
    {
        engineLoad = throttle / static_cast<float>(MAX_THROTTLE_POSITION);
    }
    float getEngineLoad()const
    {
        return engineLoad;
    }
private:
    float engineLoad = 0;
};

int main()
{
    CarECU ECU;
    Sensor sensor;
    ECU.subscribe(&sensor);
    ECU.setThrottle(20);
    std::cout<<sensor.getEngineLoad()<<'\n';
    return 0;

}