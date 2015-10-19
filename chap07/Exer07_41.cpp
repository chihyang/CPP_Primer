#include <iostream>
#include <string>
#include "Exer07_41.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
	cout << "item1: " << endl; 
	// first call Sales_data(const string&, unsigned, double), then Sales_data()
	Sales_data item1;
	cout << "item2: " << endl;
	// call Sales_data(const string&, unsigned, double)
	Sales_data item2("978-7-121-20038-0", 10, 128);
	cout << "item3: " << endl;
	// first call Sales_data(const string&, unsigned, double), then Sales_data(const string &)
	Sales_data item3("978-7-100-09211-1");
	cout << "item4: " << endl;
	// first call Sales_data(const string&, unsigned, double), then Sales_data(), at last Sales_data(istream &is)
	Sales_data item4(cin);
	return 0;
}