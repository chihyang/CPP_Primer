// For subsequent convenience, exercise 7.4 is defined as a header.
#ifndef EXER07_04_H
#define EXER07_04_H
#include <iostream>
#include <string>
using std::string;
using std::istream;
using std::ostream;
struct Person {
    // friend declaration required by exercise 7.22
    friend istream& read(istream& is, Person& psn);
    friend ostream& print(ostream& os, const Person &psn);
private:
    string name;
    string addr;
public:
    // functions required by exercise 7.5
    string getName() const { return name; }
    string getAddr() const { return addr; }
    // constructors required by exercise 7.15
    Person() = default;
    Person(const string& nm, const string& ad) : name(nm), addr(ad) {}
    Person(istream &is) { read(is, *this); }
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
