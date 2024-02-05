#ifndef CONFIG_H
#define CONFIG_H

#define KEY_STRING "mysharedmemory"
#define MESSAGE_SIZE 128
#define VECTOR_SIZE 40
struct SharedMemoryBlock
{
    char ip_list[10][16];
} sharedMemoryBlock;

#endif