/*
    std::array - CANNOT GROW AT RUNTIME
    std::vector - dynamic array - grows automatically, not good for insertion/deletion anywhere except back (end)
    std::deque - Double ended queue 0 grows automatically, same as vector, but also ok for begin, not only end insertion
    std::list - double linked list - efficient for insertion/delition anywhere - does not provide random access
    std::forward_list - one way linked list, smaller memory (has only forward pointer)
    std::set / std::multi_set - binary tree - keeps items sorted - doesn't allow duplicates
    std::multi_set allows duplicates
    Sets are good when we want to frequently search (look up) VALUES
    std::map / std::multi_map - binary tree - stores pairs key/value - sorted order based on KEY - fast search - no random access
    
    UNORDERED CONTAINTERS
    std::unordered_set
    std::hash

    ////////////        SUMMARY         /////////////////
    Use vector for random access, but not insertion and deletion.
    Deque is preferable when elements need to be inserted and removed from both the ends.
    Use list if frequent insertions and deletions are required
        Use forward_list for memory consttrained systmes
    Use associative containers if lookup/search is important
    Favour unordered containers if elements need not to be oredered, else use set/map.
*/

#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

void Array(){
    std::array<int, 5>arr;
    for(int i = 0; i < arr.size(); i++){
        arr[i] = i;
    }

    auto itr = arr.begin();

    for(auto x : arr){
        std::cout<<x<<" ";
    }
    arr.data();
}

void Vector(){
    std::vector<int> v{1,2,3};
    for(int i = 0; i < 10; i++){
        v.push_back(i*10);
        std::cout<<v.size()<<std::endl;
    }

    auto itr = v.begin();

    v.insert(itr, 1000); /* This leads to assignments and copies as the elements must be shifted*/
    std::cout<<v[v.size() - 1];
}

void Deque(){
    std::deque<int>deq;
    for(int i = 0; i < 10; i++){
        deq.push_front(i*2);
        deq.push_back(i);
    }

    auto itr = deq.begin();

    for(auto x : deq){
        std::cout<<x<<" ";
    }
    deq.insert(deq.begin(), -10);
    deq.pop_back();
    deq.pop_front();
}

void List(){
    std::list<int> l;

    for(int i = 0; i < 10; i++){
        l.push_back(i);
    }

    auto itr = l.begin();

    while(itr != l.end()){
        std::cout << *itr++ << " ";
    }
}

void Set(){
    std::set<int> s{8,2,0,5};
    s.insert(1);
    s.insert(20);

    auto itr = s.begin(); // constant itr
    while( itr != s.end()){
        std::cout<<*itr++<<std::endl;
    }
    s.erase(1);
    s.erase(s.begin());
    itr = s.find(8);
    s.insert(2);
}

void Map(){
    std::map<int, std::string> m{
        {1, "Daniel"},
        {2, "Mihai"}
    };
    m.insert(std::make_pair(6, "superman"));
    m[4] = "batman";

    auto itr = m.begin();
    while(itr != m.end()){
        std::cout<<itr->first << ":" <<itr->second <<std::endl;
        ++itr;
    }
    for(const auto &x : m){
        
    }
}

void UnSet(){
    std::unordered_set<std::string> us;
    us.insert("Hulk");
    us.insert("Hulk1");
    us.insert("Hulk2");
    us.insert("Hulk3");
    us.insert("Hulk4");

    for(const auto x : us){
        std::cout<<"Bucket " << us.bucket(x)<<" "<<x<<std::endl;
    }

    std::cout<<"Bucket count" << us.bucket_count()<<std::endl;
    std::cout<<"NUmber of elements" << us.size()<<std::endl;
    std::cout<<"Load factor" << us.load_factor()<<std::endl;
}
void UnMap(){
    std::unordered_map<std::string, std::string> um;
    um.insert(std::make_pair("first", "Daniel"));
    std::cout<<um["first"];
}

class Employee{
    std::string _name;
    int _id;
public:
    Employee(const std::string &n, int id) : _name(n), _id(id){

    }
    const std::string &GetName()const{
        return _name;
    }
    int getId()const{
        return _id;
    }
};

/*
    What are these :>
*/
struct EmployeeHash{
    size_t operator()(const Employee &emp)const{
        auto s1 = std::hash<std::string>{}(emp.GetName());
        auto s2 = std::hash<int>{}(emp.getId());
        return s1 ^ s2;
    }
};
struct EmpEquality{
    bool operator()(const Employee &e1, const Employee &e2)const{
        return e1.getId() == e2.getId() && e1.GetName() == e2.GetName(); /* Perform equality on all atributes that where involved in hashing*/
    }
};
void Hash(){
    std::hash<std::string> h;
    std::cout<<h("hello")<<std::endl;
    std::unordered_set<Employee, EmployeeHash, EmpEquality> coll;
    coll.insert(Employee{"Umbr", 5});
    coll.insert(Employee{"Dan", 51});
    coll.insert(Employee{"fwafwa", 15});

    for(const auto &x : coll){
        std::cout<<x.getId()<<':'<<x.GetName()<<std::endl;
    }
}
int main(){
    // Array();
    // Vector();
    // Deque();
    // List();
    // Set();
    // Map();
    // UnSet();
    // UnMap();
    Hash();

}