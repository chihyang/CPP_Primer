#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <iostream>
#include <string>
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
	friend Sales_data add(const Sales_data& item1, const Sales_data& item2);
public:
	// constructor
	Sales_data() = default;
	Sales_data(const string &s) : bookNo(s) {}
	Sales_data(const string &s, unsigned n, double p) : 
	    bookNo(s), units_sold(n), revenue(p*n) {}
	explicit Sales_data(istream &is) { is >> *this; }
	Sales_data& combine(const Sales_data& rhs);
	string isbn() const { return bookNo; }
	// member
private:
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	double avg_price() const;
};
// declare friend functions outside class
ostream& operator<<(ostream&, const Sales_data&);
istream& operator>>(istream&, Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);
Sales_data add(const Sales_data& item1, const Sales_data& item2);
// member functions definition
Sales_data& Sales_data::combine(const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
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
Sales_data add(const Sales_data& item1, const Sales_data& item2)
{
	Sales_data sum = item1;
	sum.combine(item2);
	return sum;
}
#endif