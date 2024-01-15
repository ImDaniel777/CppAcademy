#include <iostream>
#include <vector>
using namespace std;

struct Journal{
    string title;
    vector<string> entries;

    Journal(const tring &title) : title(title){};

    void add_entry(const string &entry){
        static int count = 1;
        entries.push_back(lexical_cast<string>(count++) + ": " + entry);
        
    }
}