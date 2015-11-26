#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include <cstddef>
#include <iostream>
#include <string>
#include "Exer15_26_Disc_quote.h"
class Bulk_quote : public Disc_quote { // Bulk_quote inherits from Quote
public:
	Bulk_quote() { std::cout << "Bulk_quote()" << std::endl; }
	// inherited constructor
	using Disc_quote::Disc_quote;
	// overrides the base version in order to implement the bulk purchase discount policy
	double net_price(std::size_t) const override;
	void debug() const override;
	// copy-control members
	Bulk_quote(const Bulk_quote &bq) : Disc_quote(bq) 
	    { std::cout << "Bulk_quote(const Bulk_quote&)" << std::endl; }
	Bulk_quote(Bulk_quote &&bq) noexcept : Disc_quote(std::move(bq))
	    { std::cout << "Bulk_quote(Bulk_quote&&)" << std::endl; }
	Bulk_quote& operator=(const Bulk_quote&);
	Bulk_quote& operator=(Bulk_quote&&) noexcept;
	~Bulk_quote() { std::cout << "~Bulk_quote()" << std::endl; }
};
// if the specified number of items are purchased, use the discounted price
double Bulk_quote::net_price(std::size_t cnt) const
{
	if (cnt >= quantity)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}
inline void Bulk_quote::debug() const
{
	std::cout << "std::string bookNo\n"
	          << "double price\n"
	          << "std::size_t min_qty\n"
	          << "double discount\n"
	          << std::endl;  
}
inline Bulk_quote& Bulk_quote::operator=(const Bulk_quote &rhs)
{
	Disc_quote::operator=(rhs);
	std::cout << "Bulk_quote& operator=(const Bulk_quote&)" << std::endl;
	return *this;
}
inline Bulk_quote& Bulk_quote::operator=(Bulk_quote &&rhs) noexcept
{
	Disc_quote::operator=(std::move(rhs));
	std::cout << "Bulk_quote& operator=(Bulk_quote&&)" << std::endl;
	return *this;
}
#endif