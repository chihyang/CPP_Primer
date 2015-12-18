#include <iostream>
#include "Exer15_26_Quote.h"
#include "Exer15_26_Disc_quote.h"
#include "Exer15_26_Bulk_quote.h"
using std::cout;
using std::endl;
int main()
{
	// calls Quote(const string&, double)
	Quote q("978-7-121-20038-0", 128.0);
	cout << endl;
	// calls Bulk_quote(const string&, double, size_t, double)
	// calls Disc_quote(const string&, double, size_t, double) 
	// calls Quote(const string&, double)
	Bulk_quote bq("978-7-121-20038-0", 128.0, 6, 0.05);
	cout << endl;
	// calls Quote(const Quote&)
	Quote q1(q);
	cout << endl;
	// calls Quote(const Quote&)
	Quote q2(bq);
	cout << endl;
	// calls Bulk_quote(const Bulk_quote&)
	// calls Disc_quote(const Disc_quote&)
	// calls Quote(const Quote&)
	Bulk_quote bq1(bq);
	cout << endl;
	// calls Quote(Quote&&)
	Quote q3 = std::move(bq);
	cout << endl;
	// calls Bulk_quote(Bulk_quote&&)
	// calls Disc_quote(Disc_quote&&)
	// calls Quote(Quote&&)
	Bulk_quote bq2 = std::move(bq1);
	cout << endl;
	// calls Bulk_quote()
	// calls Disc_quote()
	// calls Quote()
	Bulk_quote bq3;
	cout << endl;
	// calls Bulk_quote::operator=(const Bulk_quote&)
	// calls Disc_quote::operator=(const Disc_quote&)
	// calls Quote::operator=(const Quote&)
	bq3 = bq2;
	cout << endl;
	// calls Bulk_quote()
	// calls Disc_quote()
	// calls Quote()
	Bulk_quote bq4;
	cout << endl;
	// calls Bulk_quote::operator=(Bulk_quote&&)
	// calls Disc_quote::operator=(Disc_quote&&)
	// calls Quote::operator=(Quote&&)
	bq4 = std::move(bq3);
	cout << endl;
	return 0;
}
// Note: one thing to say: every time we use move operation we must use std::move,
// because variable is lvalue; we cannot directly bind an rvalue reference to a 
// variable even if this variable is an rvalue reference. If we forgot to use
// std::move, the variable would be regarded as a lvalue and the corresponding 
// copy operation would substitute move operation.(review page 533 for more details)