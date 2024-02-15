#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/managed_shared_memory.hpp>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>

int main(int argc, char *argv[])
{
   using namespace boost::interprocess;

   if(argc == 1){  //Parent process
      //Remove shared memory on construction and destruction
      struct shm_remove 
      {
         shm_remove() { shared_memory_object::remove("MySharedMemory"); }
         ~shm_remove(){ shared_memory_object::remove("MySharedMemory"); }
      } remover;

    // Create shared memory segment
    boost::interprocess::managed_shared_memory segment(boost::interprocess::open_or_create, "MySharedMemory", 65536);

    // Allocate space in the shared memory
    char* shared_memory = segment.construct<char>("SharedMemory")[1024]();

    std::cout << "Server: Waiting for client data...\n";

    // Wait for the client to write data
    while (shared_memory[0] == 0) {
        boost::interprocess::ipcdetail::thread_yield();
    }

    std::cout << "Server: Received data from client: " << shared_memory << "\n";

    // Modify the received data (e.g., convert to uppercase)
    for (std::size_t i = 0; i < strlen(shared_memory); ++i) {
        shared_memory[i] = toupper(shared_memory[i]);
    }

    std::cout << "Server: Modified data.\n";

    return 0;
   }
   else{
      // Open the shared memory segment
    boost::interprocess::managed_shared_memory segment(boost::interprocess::open_or_create, "MySharedMemory", 65536);

    // Access the shared memory
    char* shared_memory = segment.find<char>("SharedMemory").first;

    // Write data to shared memory
    const char* data = "Hello, server!";
    strncpy(shared_memory, data, 1024);

    std::cout << "Client: Sent data to server: " << shared_memory << "\n";

    return 0;
   }
   return 0;
}