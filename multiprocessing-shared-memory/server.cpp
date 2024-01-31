#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include "config.h"

void* create_shared_memory(size_t size) {
  // Our memory buffer will be readable and writable:
  int protection = PROT_READ | PROT_WRITE;

  // The buffer will be shared (meaning other processes can access it), but
  // anonymous (meaning third-party processes cannot obtain an address for it),
  // so only this process and its children will be able to use it:
  int visibility = MAP_SHARED | MAP_ANONYMOUS;

  // The remaining parameters to `mmap()` are not important for this use case,
  // but the manpage for `mmap` explains their purpose.
  return mmap(NULL, size, protection, visibility, -1, 0);
}

int main()
{
#if SHMGET_METHOD == 1
    // ftok to generate unique key
    key_t key = ftok(KEY_STRING, 65);

    // shmget returns an identifier in shmid
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
 
    // shmat to attach to shared memory
    char* str = (char*)shmat(shmid, (void*)0, 0);
 
    std::cout << "Write Data : ";
    std::cin.getline(str, 1024);
  
    // detach from shared memory
    shmdt(str);
#else
    char *shmem = (char*)create_shared_memory(MESSAGE_SIZE);

    if(shmem == MAP_FAILED)
    {
        perror("Error mapping the file into memory");
        exit(EXIT_FAILURE);
    }

    while(1)
    {
        printf("Server waiting for a message from the client...\n");
        while(shmem[0] == '\0')
        {

        }
        // Process the message
        if(shmem[0] == '0')
        {
            break;
        }
        printf("Server received message: %s\n", shmem);
    }
    munmap(shmem, 128);

#endif
    return 0;
}