#include "Memory.h"

class MemoryContext
{
public:
    MemoryContext(){}
    MemoryContext(MemoryInterface *context);
    void setContext(MemoryInterface *context);
    void allocateMemory();
    void read();
    void write();
private:
    MemoryInterface *memory;
};