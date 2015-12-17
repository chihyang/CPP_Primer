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
// substitute class for struct
class Sales_data {
	// friend 
	friend istream& read(istream&, Sales_data&);
	friend ostream& print(ostream& os, const Sales_data& item);
	friend Sales_data add(const Sales_data& item1, const Sales_data& item2);
public:
	// constructor
	Sales_data() : Sales_data("", 0, 0) { cout << "Sales_data()" << endl; }
	Sales_data(const string &s) : Sales_data(s, 0, 0)
	    { cout << "Sales_data(const string &s)" << endl; }
	Sales_data(const string &s, unsigned n, double p) : 
	    bookNo(s), units_sold(n), revenue(p*n) 
		{
			cout << "Sales_data(const string &s, unsigned n, double p)" << endl;
		}
	Sales_data(istream &is) : Sales_data() 
	    {
			cout << "Sales_data(istream &is)" << endl;
        	read(is, *this); 
		} 
	// member
	Sales_data& combine(const Sales_data& rhs);
	string isbn() const { return bookNo; }
private:
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	double avg_price() const;
};
// declare friend functions outside class
istream& read(istream&, Sales_data&);
ostream& print(ostream& os, const Sales_data& item);
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
// friend functions definition
istream& read(istream &is, Sales_data& item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = item.units_sold * price;
	return is;
}
// Why does the book use an ostream reference as return value rather than void?
// 'Cause only in this way can user have a better manipulation of the format.
ostream& print(ostream& os, const Sales_data& item)
{
	os << item.bookNo << " " 
	   << item.units_sold << " "
	   << item.revenue << " "
	   << item.avg_price();
	return os;
}
Sales_data add(const Sales_data& item1, const Sales_data& item2)
{
	Sales_data sum = item1;
	sum.combine(item2);
	return sum;
}
#endif