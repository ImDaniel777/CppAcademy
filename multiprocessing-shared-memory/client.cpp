#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <thread>
#include "config.h"

int main()
{
    // ftok to generate unique key
    key_t key = ftok(KEY_STRING, 65);
 
    // shmget returns an identifier in shmid
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
 
    // shmat to attach to shared memory
    char* str = (char*)shmat(shmid, (void*)0, 0);

    std::cout<<str<<'\n';

    shmdt(str);

    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
