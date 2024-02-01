#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include "config.h"
#include <fstream>

int main()
{
#if SHMGET_METHOD == 1
    // ftok to generate unique key
    key_t key = ftok(KEY_STRING, 65);
    
    std::ofstream ClientFile("clientOut.txt");
    // shmget returns an identifier in shmid
    size_t size = sizeof(int) * 10;

    int shmid = shmget(key, size, 0666);

    printf("Created shared memory with id=%d\n", shmid);
 
    // shmat to attach to shared memory
    int* data = (int*)shmat(shmid, nullptr, 0);

    while(1)
    {
        if(data[0] == 0)
        {
            break;
        }
        getchar();
        for(int i = 0; i < 10; i++)
        {
            std::cout<<data[i]<<' ';
        }
    }

     // detach from shared memory
    shmdt(data);
#else
    char *shared_memory = (char*)mmap(NULL, MESSAGE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, -1, 0);
    snprintf(shared_memory, MESSAGE_SIZE, "Data from client");

#endif  
    return 0;
}
