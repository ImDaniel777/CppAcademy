#include <iostream>
#include "Cpp_Component.hpp"
#include <algorithm>
#include <string>

Record::Record(int id, const std::string &name) : _id{id}, _name{name}{}

Database &Database::createInstance()
{
  static Database db;
  return db;
}

void Database::addRecord(int id, const std::string &name)
{
  records.emplace_back(id, name);
}

void Database::removeRecord(int id)
{
  records.erase(std::remove_if(records.begin(), records.end(),[id](const Record &record){return record._id == id;}), records.end());
}

Record *Database::searchRecordById(int id)
{
  auto it = std::find_if(records.begin(), records.end(),
      [id](const Record& record) { return record._id == id; });
  if (it != records.end()) {
      return &(*it);
  }
  return nullptr;
}

void Database::printAllRecords()
{
  for (const auto& record : records) {
      std::cout << "ID: " << record._id << ", Name: " << record._name << std::endl;
  }
}

int Database::getNumberOfRecords()
{
  return records.size();
}