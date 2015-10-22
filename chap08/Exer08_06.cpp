#include <iostream>
#include <fstream>
#include "Sales_Data.h"
using std::ifstream;
int main(int argc, char *argv[])
{

	if(argc > 2)
	{
		cerr << "Too many input arguments!" << endl;
		return -1;
	}
	else if(argc < 2)
	{
		cerr << "Not enough arguments!" << endl;
		return -1;
	}
	else
	{
		ifstream input(argv[1]); // open the file of sales transactions
		Sales_data total; // variable to hold the running sum
		if (read(input, total)) // read the first transaction
		{
			Sales_data trans; // variable to hold data for the next transaction
			while(read(input, trans)) // read the remaining transactions
			{
				if(total.isbn() == trans.isbn()) // check isbns
					total.combine(trans); // update the running total
				else
				{
					print(cout, total) << endl; // print the results
					total = trans; // process the next book
				}
			}
			print(cout, total) << endl; // print the last transaction
		}
		else
		{
			cerr << "No data?!" << endl; // no input
		}
	}
	return 0;
}