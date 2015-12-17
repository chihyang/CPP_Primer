#include <iostream>
#include <string>
#include <typeinfo>
#include "Sales_data.h"
using std::cout;
using std::endl;
using std::ostream;
using std::type_info;
class Base {
public:
	virtual ~Base() = default;
};
class Derived : public Base {};
ostream& translate(ostream &os, const type_info &t)
{
	if(t == typeid(int))
		os << "int";
	else if(t == typeid(int[10]))
		os << "int[10]";
	else if(t == typeid(std::string))
		os << "std::string";
	else if(t == typeid(Base))
		os << "class Base";
	else if(t == typeid(Base*))
		os << "class Base *";
	else if(t == typeid(Derived))
		os << "class Derived";
	else if(t == typeid(Sales_data))
		os << "class Sales_data";
	return os;
}
int main()
{
	int arr[10];
	Derived d;
	Base *p = &d;
	cout << typeid(42).name() << "\n"
	     << typeid(arr).name() << "\n"
	     << typeid(Sales_data).name() << "\n"
	     << typeid(std::string).name() << "\n"
	     << typeid(p).name() << "\n"
	     << typeid(*p).name() << "\n" << endl;
	translate(cout, typeid(42)) << "\n";
	translate(cout, typeid(arr)) << "\n";
	translate(cout, typeid(Sales_data)) << "\n";
	translate(cout, typeid(std::string)) << "\n";
	translate(cout, typeid(p)) << "\n";
	translate(cout, typeid(*p)) <<endl;
	return 0;
}
// ******result of g++ and clang++******
// i
// A10_i
// 10Sales_data
// NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
// P4Base
// 7Derived

// ******result of cl******
// int
// int [10]
// class Sales_data
// class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
// class Base *
// class Derived