#include "Memory.h"

class Eeprom : public MemoryInterface
{
public:
    void allocateMemory() override;
    void read() override;
    void write() override;
private:
    int *memory;
};