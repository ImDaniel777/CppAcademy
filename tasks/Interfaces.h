#pragma once

class ElectricCarInterface
{
public:
    virtual void chargeBattery(float amount) = 0;
    virtual ~ElectricCarInterface(){};
};

class HybridCarInterface
{

public:
    virtual void addFuel(float amount) = 0;
    virtual ~HybridCarInterface(){};
};

class MildHybridCarInterface : ElectricCarInterface, HybridCarInterface
{

public:
    virtual ~MildHybridCarInterface(){};
};