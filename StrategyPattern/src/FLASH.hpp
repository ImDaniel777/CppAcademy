#ifndef FLASH_HPP
#define FLASH_HPP

#include "Memory.h"

class Flash : public MemoryInterface
{
public:
    void allocateMemory() override;
    void read() override;
    void write() override;
private:
    char *memory;
};

#endif