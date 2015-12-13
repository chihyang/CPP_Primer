#ifndef EXER18_09_SALES_DATA_H
#define EXER18_09_SALES_DATA_H
#include <iostream>
#include <string>
#include <stdexcept>
// exception classes
class out_of_stock: public std::runtime_error {
public:
	explicit out_of_stock(const std::string &s): runtime_error(s) {}
};
class isbn_mismatch: public std::logic_error {
public:
	explicit isbn_mismatch(const std::string &s): std::logic_error(s) {}
	isbn_mismatch(const std::string &s, const std::string &lhs, const std::string &rhs):
	    std::logic_error(s), left(lhs), right(rhs) {}
	const std::string left, right;
};
class Sales_data {
	// friend 
	// overloaded output operator required by exercise 14.6
	friend std::ostream &operator<<(std::ostream&, const Sales_data&);
	// overloaded input operator required by exercise 14.9
	friend std::istream &operator>>(std::istream&, Sales_data&);
	// overloaded addition operator required by exercise 14.13
	friend Sales_data operator+(const Sales_data&, const Sales_data&);
	// overloaded equality on page 561
	friend bool operator==(const Sales_data&, const Sales_data&);
	friend bool operator!=(const Sales_data&, const Sales_data&);
	// overloaded addition operator required by exercise 14.20
	friend Sales_data operator+(const Sales_data&, const Sales_data&);
public:
	// constructor
	Sales_data() = default;
	Sales_data(const std::string &s) : bookNo(s) {}
	Sales_data(const std::string &s, unsigned n, double p) : 
	    bookNo(s), units_sold(n), revenue(p*n) {}
	explicit Sales_data(std::istream &is) { is >> *this; }
	// member
	std::string isbn() const { return bookNo; }
	// overloaded compound-assignment operator required by exercise 14.20
	Sales_data& operator+=(const Sales_data&);
	// takes an ISBN as parameter, required by exercise 14.22
	Sales_data& operator=(const std::string&);
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	double avg_price() const;
};
// member functions definition
Sales_data& Sales_data::operator+=(const Sales_data& rhs)
{
	if (isbn() != rhs.isbn())
		throw isbn_mismatch("wrong isbns", isbn(), rhs.isbn());
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
Sales_data& Sales_data::operator=(const std::string &isbn)
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
std::ostream& operator<<(std::ostream& os, const Sales_data& item)
{
	os << item.bookNo << " "
	   << item.units_sold << " "
	   << item.revenue << " "
	   << item.avg_price();
	return os;
}
// overloaded input operator
std::istream& operator>>(std::istream &is, Sales_data& item)
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
#endif