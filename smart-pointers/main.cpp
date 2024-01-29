#include <iostream>
#include <memory>
#define UNIQUE_PTR_DEMO 0
#define SHARED_PTR_DEMO 0
#define WEAK_PTR_DEMO 1

void func1(std::unique_ptr<std::string> p) /* Can't be passed by value because it will involve a copy => std::move needed*/
{
    std::cout<<p.get()<<std::endl;
}
void func2(std::unique_ptr<std::string> &p)
{
    std::cout<<p.get()<<std::endl;
}

class Employee
{
    std::shared_ptr<std::string> _project{};
public:
    void setProject(const std::shared_ptr<std::string> &prj)
    {
        _project = prj;
    }
    const std::shared_ptr<std::string> &getProject()const
    {
        return _project;
    }
};

class Printer
{
    std::weak_ptr<int> value;
public:
    void setValue(std::weak_ptr<int> p)
    {
        value = p;
    }
    void print()
    {
        if(value.expired())
        {
            std::cout<<"pointer expired"<<'\n';
            return;
        }
        auto valueLock = value.lock(); /* Returns a shared_ptr and increments the ref count*/
        std::cout<<"value: "<<*valueLock<<'\n';
        std::cout<<"final ref count: "<<value.use_count()<<'\n';

    }
};
int main()
{
#if UNIQUE_PTR_DEMO == 1
    std::unique_ptr<std::string> uPtr(new std::string{"3af3aw"});
    func2(uPtr);
    /* 
        Here we can still use the uPtr
    */
    std::cout<<*uPtr<<std::endl;

    func1(std::move(uPtr));
    /*
        Move needed because uniquePtr can't be copied.
        Here we can no longer use uPtr
    */
    std::cout<<*uPtr<<std::endl;
#elif SHARED_PTR_DEMO == 1
    std::shared_ptr<std::string> prj {new std::string{"valeo_project"}};
    
    Employee e1;
    e1.setProject(prj);

    Employee e2;
    e2.setProject(prj);

    std::cout<<"ref count"<<prj.use_count()<<'\n';
#elif WEAK_PTR_DEMO == 1
    /* Used for solving cyclic referencing (2 classes have a pointer to each other)
       Allow communication between pointers without taking ownership 
    */
    Printer printer;
    int x;
    std::cin>>x;
    std::shared_ptr<int> pValue(new int{x});
    std::cout<<"ref count before setValue "<<pValue.use_count()<<'\n';
    printer.setValue(pValue);
    if(*pValue > 10)
    {
        pValue = nullptr; /* This decrements the ref count for shared_ptr by 1 so it will not free the memory here if it was > 1*/
    }
    printer.print();
#endif
    return 0;
}