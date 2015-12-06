#ifndef EXER16_61_SALES_DATA_H
#define EXER16_61_SALES_DATA_H
#include <cstddef>
#include <iostream>
#include <string>
#include <functional>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;
using std::istream;
using std::ostream;
class Sales_data {
	// friend 
	// overloaded output operator required by exercise 14.6
	friend ostream &operator<<(ostream&, const Sales_data&);
	// overloaded input operator required by exercise 14.9
	friend istream &operator>>(istream&, Sales_data&);
	// overloaded addition operator required by exercise 14.13
	friend Sales_data operator+(const Sales_data&, const Sales_data&);
	// overloaded equality on page 561
	friend bool operator==(const Sales_data&, const Sales_data&);
	friend bool operator!=(const Sales_data&, const Sales_data&);
	// overloaded addition operator required by exercise 14.20
	friend Sales_data operator+(const Sales_data&, const Sales_data&);
	// hash for Sales_data required by exercise 16.62
	friend class std::hash<Sales_data>;
public:
	// constructor
	Sales_data() = default;
	Sales_data(const string &s) : bookNo(s) {}
	Sales_data(const string &s, unsigned n, double p) : 
	    bookNo(s), units_sold(n), revenue(p*n) {}
	explicit Sales_data(istream &is) { is >> *this; }
	// member
	string isbn() const { return bookNo; }
	// overloaded compound-assignment operator required by exercise 14.20
	Sales_data& operator+=(const Sales_data&);
	// takes an ISBN as parameter, required by exercise 14.22
	Sales_data& operator=(const string&);
private:
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	double avg_price() const;
};
// member functions definition
Sales_data& Sales_data::operator+=(const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
Sales_data& Sales_data::operator=(const string &isbn)
{
	bookNo = isbn;
	return *this;
}
// define avg_price as inline, required by exercise 7.26
inline double Sales_data::avg_price() const
{
	if(units_sold != 0)
		return revenue / units_sold;
	else
		return revenue;
}
// overloaded output operator
ostream& operator<<(ostream& os, const Sales_data& item)
{
	os << item.bookNo << " "
	   << item.units_sold << " "
	   << item.revenue << " "
	   << item.avg_price();
	return os;
}
// overloaded input operator
istream& operator>>(istream &is, Sales_data& item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	if(is) // check if input invalid
		item.revenue = item.units_sold * price;
	else
		item = Sales_data(); // input failed:given the object default state
	return is;
}
bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.bookNo == rhs.bookNo &&
	       lhs.units_sold == rhs.units_sold &&
		   lhs.revenue == rhs.revenue;
}
bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
	return !(lhs == rhs);
}
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}
// hash specialization for Sales_data required by exercise 16.62
// open the std namespace so we can specialize std::hash
namespace std {
template <> // we're defining a specialization with the template parameter of Sales_data
struct hash<Sales_data> {
	// the type used to hash an unordered container must define these types
	typedef size_t result_type;
	typedef Sales_data argument_type; // by default, this type needs ==
	size_t operator()(const Sales_data&) const;
	// our class uses synthesized copy control and default constructor
};
size_t // here we can use [typename] hash<Sales_data>::result_type to replace size_t
hash<Sales_data>::operator()(const Sales_data &s) const 
{
	return hash<string>()(s.bookNo) ^
	       hash<unsigned>()(s.units_sold) ^
	       hash<double>()(s.revenue);
}
} // close the std namespace; not: no semicolon after the close curly
#endif