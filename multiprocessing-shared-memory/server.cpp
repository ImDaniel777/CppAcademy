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
    std::ofstream ServerFile("serverOut.txt");

#if SHMGET_METHOD == 1
    // ftok to generate unique key
    key_t key = ftok(KEY_STRING, 65);

    // shmget returns an identifier in shmid
    size_t size = sizeof(int) * 10;
    int shmid = shmget(key, size, 0666 | IPC_CREAT);
    if(shmid == -1)
    {
        std::cerr << "Error getting shared memory id: " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }
    printf("Created shared memory with id=%d\n", shmid);
    // shmat to attach to shared memory
    int *data = (int*)shmat(shmid, (void*)0, 0);
    data[0] = 1;
    int index, value;
    while(1)
    {
        std::cout<<"Choose an index(9 is maximum) and a value to be inserted at that index\n";
        std::cin>>index>>value;
        if(index > 9)
        {
            continue;
        }
        else
        {
            data[index] = value;
        }
    }
    // detach from shared memory
    shmdt(data);

    shmctl(shmid, IPC_RMID, NULL);
#else
    char *shmem = (char*)create_shared_memory(MESSAGE_SIZE);

    if(shmem == MAP_FAILED)
    {
        perror("Error mapping into memory");
        exit(EXIT_FAILURE);
    }

    printf("Server waiting for a message from the client...\n");
    while(shmem[0] == '\0')
    {

    }
    printf("Server received message:\n%s", shmem);
    munmap(shmem, MESSAGE_SIZE);

#endif
    return 0;
}