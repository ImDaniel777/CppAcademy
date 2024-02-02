#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include "config.h"
#include <fstream>
#include <errno.h>
#include <cstring>


int main()
{
#if SHMGET_METHOD == 1
    // ftok to generate unique key
    key_t key = ftok(KEY_STRING, 65);
    
    // shmget returns an identifier in shmid
    int shmid = shmget(key, sizeof(SharedMemoryBlock), 0666);

     if(shmid == -1)
    {
        std::cerr << "Error getting shared memory id: " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }
    printf("Created shared memory with id=%d\n", shmid);

    std::ofstream ClientFile("../multiprocessing-shared-memory/clientOut.txt");
 
    // shmat to attach to shared memory
    SharedMemoryBlock* sharedMemory  = (SharedMemoryBlock*)shmat(shmid, nullptr, 0);

    while(1)
    {
        if(std::strcmp(sharedMemory->ip_list[0], "0") == 0)
        {
            break;
        }
        getchar();
        for(int i = 0; i < 10; i++)
        {
            std::cout << sharedMemory->ip_list[i]<< ' ';
        }
        std::cout<<'\n';
    }

    ClientFile.close();

     // detach from shared memory
    shmdt(sharedMemory);
#else
    char *shared_memory = (char*)mmap(NULL, MESSAGE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, -1, 0);
    snprintf(shared_memory, MESSAGE_SIZE, "Data from client");

#endif  
    return 0;
}
