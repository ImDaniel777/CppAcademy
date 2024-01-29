#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/managed_shared_memory.hpp>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>

int main(int argc, char *argv[])
{

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