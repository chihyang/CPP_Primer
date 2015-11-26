#ifndef QUOTE_H
#define QUOTE_H
#include <cstddef>
#include <iostream>
#include <string>
class Quote {
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}
	std::string isbn() const { return bookNo; }
	// return the total sales price for the specified number of items
	// derived class will override and apply different discount algorithms
	virtual double net_price(std::size_t n) const
	    { return n * price; }
	virtual void debug() const;
	virtual ~Quote() = default; // dynamic binding for the destructor
private:
	std::string bookNo; // ISBN number of this item
protected:
	double price = 0.0; // normal, undiscounted price
};
// calculate and print the price for the given number of copies, applying any discount
double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
	// depending on the type of the object bound to the item parameter
	// calls either Quote::net_price or Bulk_quote::net_price
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() // calls Quote::isbn
	   << " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}
inline void Quote::debug() const
{
	std::cout << "std::string bookNo\n"
	          << "double price\n"
	          << std::endl;  
}
#endif