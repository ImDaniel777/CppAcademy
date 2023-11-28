#include <iostream>
#include <typeinfo>

class TestClass {

};
class Child : public TestClass {

};
int main(){
	int i{};
	Child c;
	TestClass *p = &c;
	const std::type_info &ti = typeid(*p);
	std::cout<<ti.name()<<std::endl;
}