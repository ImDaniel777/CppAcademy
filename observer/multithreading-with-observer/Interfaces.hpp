#ifndef INTERFACES_HPP
#define INTERFACES_HPP

struct CarData
{
    float speed = 0;
    float throttle = 0;
};

class IObserver
{
public:
    virtual ~IObserver(){}
    virtual void update(CarData data) = 0;
};

class IObservable
{
public:
    virtual ~IObservable(){}
    virtual void subscribe(IObserver *observer) = 0;
    virtual void unsubscribe(IObserver *observer) = 0;
    virtual void notify() = 0;
};

#endif  