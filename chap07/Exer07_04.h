// For subsequent convenience, exercise 7.4 is defined as a header.
#ifndef EXER07_04_H
#define EXER07_04_H
#include <iostream>
#include <string>
using std::string;
using std::istream;
using std::ostream;
struct Person;
istream& read(istream&, Person&);
struct Person {
	string name;
	string addr;
	// functions required by exercise 7.5
	string getName() const { return name; }
	string getAddr() const { return addr; }
	// constructors required by exercise 7.15
	Person() = default;
	Person(const string& n, const string& a) : name(s), a(n) {}
	Person(istream &is) { read(is, *this) }
};
// functions required by exercise 7.6
istream& read(istream& is, Person &psn)
{
	is >> psn.name >> psn.addr;
	return is;
}
ostream& print(ostream& os, const Person &psn)
{
	os << psn.name << " " << psn.addr;
	return os;
}
#endif