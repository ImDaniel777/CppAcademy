#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

#define DATA_SIZE 128

char *shared_memory = nullptr;

int main(int argc, char **argv)
{
    
    pid_t pid = fork();

    if(pid == 0)
    {
    std::cout<<shared_memory<<'\n';

    }
    else
    {
    shared_memory = (char *)mmap(NULL,
                        DATA_SIZE,
                        PROT_READ | PROT_WRITE,
                        MAP_ANONYMOUS | MAP_SHARED,
                        0,
                        0);
    strcpy(shared_memory, "Hello world");
    }

    return 0;
}