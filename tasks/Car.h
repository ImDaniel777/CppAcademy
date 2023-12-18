#pragma once

#include <iostream>


class Car
{
private:
    int realMileage = 0;
    int horsePower;
    float kwPower;
protected:
    int mileage = 0;

    float fuelCapacity;

    char chassisType;
    std::string  *_VIN = nullptr;

public:
    Car();
    Car(std::string  &VIN);

    virtual void accelerate() = 0;
    void getRealMileage() const;
    void setRealMileage(int value);
    std::string  getVIN()const;
    void setVIN(std::string value);
    virtual ~Car();
};