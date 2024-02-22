#include <vector>
#include <iostream>

struct Record
{
    int _id;
    std::string _name;
    
    Record(int id, const std::string &name);
};

class Database
{
public:
    static Database &createInstance();
    void addRecord(int id, const std::string &name);
    void removeRecord(int id);
    Record *searchRecordById(int id);
    void printAllRecords();
    int getNumberOfRecords();

    Database &operator=(const Database &obj) = delete;
    Database(const Database &obj) = delete;
private:
    Database(){}
    ~Database(){}

    std::vector<Record> records;
};