#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include "config.h"

int main()
{
#if SHMGET_METHOD == 1
    // ftok to generate unique key
    key_t key = ftok(KEY_STRING, 65);
 
    // shmget returns an identifier in shmid
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
 
    // shmat to attach to shared memory
    char* str = (char*)shmat(shmid, (void*)0, 0);

    std::cout<<str<<'\n';

    shmdt(str);

    shmctl(shmid, IPC_RMID, NULL);
#else
    char *shared_memory = (char*)mmap(NULL, MESSAGE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, -1, 0);
    snprintf(shared_memory, MESSAGE_SIZE, "Data from client");

#endif  
    return 0;
}
