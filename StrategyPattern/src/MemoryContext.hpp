#include "Memory.h"

class MemoryContext
{
public:
    void setContext(MemoryInterface *memory);
    void allocateMemory();
    void read();
    void write();
private:
    MemoryInterface *memory;
};