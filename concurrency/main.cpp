#include <iostream>
#include <list>
#include <thread>
#include <mutex>

std::list<int> g_Data;
std::mutex g_Mutex;

const int SIZE = 5000000;
void download(std::string file){
    std::cout<<"[Downloader started]"<<file<<std::endl;
    for(int i = 0; i < SIZE; i++){
        g_Data.push_back(i);
    }
    std::cout<<"Downloader finished"<<std::endl;
}

int add(int x, int y){
    return x + y;
}

int square(int x){
    return x * x;
}

void download_1(){
    for(int i = 0; i < SIZE; ++i){
        std::lock_guard<std::mutex> mtx(g_Mutex);
        // g_Mutex.lock();
        g_Data.push_back(i);
        // if(i == 500){
        //     return; 
        // }        thread locked the mutex and returns without unlocking =>> use RAII
        // g_Mutex.unlock();
    }
}

void download_2(){
    for(int i = 0; i < SIZE; ++i){
        std::lock_guard<std::mutex> mtx(g_Mutex); // auto unlock, forced to update 
        g_Data.push_back(i);
    }
}

void process(){
    std::cout<<"Thread id"<<std::this_thread::get_id()<<std::endl;
}
int main(){
    // std::string file{"cppcast.mp4"};
    // std::cout<<"main user started an operation"<<std::endl;
    // std::thread thDownloader(download, std::ref(file)); // when passing arguments to threads, pass them as refference so no copy will be created

    // if(thDownloader.joinable()){
    //     thDownloader.join();
    // }

    std::thread thDownloader(download_1);
    std::thread thDownloader2(download_2);

    thDownloader.join();
    thDownloader2.join();
    std::cout<<g_Data.size()<<std::endl;

    int cores = std::thread::hardware_concurrency();
    std::cout<<"Cores:"<<cores<<std::endl;
    return 0;

}