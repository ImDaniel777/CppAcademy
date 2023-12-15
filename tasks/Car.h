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
    char *VIN;

public:
    Car();
    Car(char *VIN);

    virtual void accelerate() = 0;
    void getRealMileage() const;
    void setRealMileage(int value);
    virtual ~Car();
};