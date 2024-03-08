#include "FLASH.hpp"
#include "EEPROM.hpp"
#include "MemoryContext.hpp"

int main()
{
    Eeprom eeprom;
    Flash flash;

    MemoryContext memory(&eeprom);
    memory.allocateMemory();
    memory.read();
    memory.write();
    
    memory.setContext(&flash);
    memory.allocateMemory();
    memory.read();
    memory.write();
    
    return 0;
}