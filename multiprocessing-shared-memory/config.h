#ifndef CONFIG_H
#define CONFIG_H

#define KEY_STRING "mysharedmemory"
#define MESSAGE_SIZE 128
#define VECTOR_SIZE 40
#define SHMGET_METHOD 1
#define MMAP_METHOD !SHMGET_METHOD

#endif