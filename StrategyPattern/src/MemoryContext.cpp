#include "MemoryContext.hpp"

void MemoryContext::setContext(MemoryInterface *context)
{
    memory = context;
}

MemoryContext::MemoryContext(MemoryInterface *context) : memory(context){}

void MemoryContext::allocateMemory()
{
    memory->allocateMemory();
}

void MemoryContext::read()
{
    memory->read();
}

void MemoryContext::write()
{
    memory->write();
}