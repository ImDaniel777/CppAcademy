#pragma once

class MemoryInterface
{
public:
    virtual void allocateMemory() = 0; 
    virtual void read() = 0;
    virtual void write() = 0;

    virtual ~MemoryInterface(){}
};