#include <iostream>
#include <string>
class Employee {
public:
	Employee() : id(++count) {}
	Employee(const std::string& s) : name(s), id(++count){}
	Employee(const Employee& e) : name(e.name), id(++count) {}
	Employee& operator=(const Employee&);
	~Employee() { --count; }
private:
	std::string name;
	unsigned id;
	static unsigned count;
};
Employee& Employee::operator=(const Employee& e)
{
	name = e.name;
	id = ++count;
}