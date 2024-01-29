#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <thread>

void read_shared_memory()
{
    std::cout<<"Thread joined"<<'\n';
    // ftok to generate unique key
    key_t key = ftok("shmfile", 65);
 
    // shmget returns an identifier in shmid
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
 
    // shmat to attach to shared memory
    char* str = (char*)shmat(shmid, (void*)0, 0);

    std::cout<<str<<'\n';

    shmdt(str);

    shmctl(shmid, IPC_RMID, NULL);
    
}
int main()
{
    // ftok to generate unique key
    key_t key = ftok("shmfile", 65);
 
    // shmget returns an identifier in shmid
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
 
    // shmat to attach to shared memory
    char* str = (char*)shmat(shmid, (void*)0, 0);
 
    std::cout << "Write Data : ";
    std::cin.getline(str, 1024);
 
    std::cout << "Data written in memory: " << str << std::endl;
 
    // detach from shared memory
    shmdt(str);
 

    std::thread read_thread{read_shared_memory};
    if(read_thread.joinable())
    {
        read_thread.join();
    }
    return 0;
}