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
    if(ClientFile.is_open() == 0)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    ClientFile << "Hello" <<'\n';
 
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
            ClientFile << sharedMemory->ip_list[i]<<' ';
        }
        std::cout<<'\n';
        ClientFile << '\n';
    }

    ClientFile.close();

     // detach from shared memory
    shmdt(sharedMemory);
    return 0;
}
