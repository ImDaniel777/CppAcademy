#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include "config.h"
#include <errno.h>
#include <fstream>
#include <cstring>

void* create_shared_memory(size_t size) {
  // Our memory buffer will be readable and writable:
  int protection = PROT_READ | PROT_WRITE;

  // The buffer will be shared (meaning other processes can access it), but
  // anonymous (meaning third-party processes cannot obtain an address for it),
  // so only this process and its children will be able to use it. Also anonymous means
  // the memory is mapped to RAM, not an extern data source.
  int visibility = MAP_SHARED | MAP_ANONYMOUS;

  // The remaining parameters to `mmap()` are not important for this use case,
  // but the manpage for `mmap` explains their purpose.
  return mmap(NULL, size, protection, visibility, -1, 0);
}

int main()
{
    std::ofstream ServerFile("../multiprocessing-shared-memory/serverOut.txt");

    // ftok to generate unique key
    key_t key = ftok(KEY_STRING, 65);

    // shmget returns an identifier in shmid
    int shmid = shmget(key, sizeof(SharedMemoryBlock), 0666 | IPC_CREAT);
    if(shmid == -1)
    {
        std::cerr << "Error getting shared memory id: " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }
    printf("Created shared memory with id=%d\n", shmid);
    // shmat to attach to shared memory
    SharedMemoryBlock *sharedMemory = (SharedMemoryBlock*)shmat(shmid, (void*)0, 0);
    std::strcpy(sharedMemory->ip_list[0], "0.0.0.0");

    int index;
    char ip[16];
    while(1)
    {
        std::cout<<"Choose an index(9 is maximum) and an ip to be inserted at that index\n";
        std::cin>>index>>ip;
        if(strcmp(ip, "0") == 0)
        {
            break;
        }
        if(index > 9)
        {
            break;
        }
        else
        {
            std::strcpy(sharedMemory->ip_list[0], ip);

        }
    }
    // detach from shared memory
    shmdt(sharedMemory);

    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}