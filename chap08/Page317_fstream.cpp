#include <iostream>
#include <fstream>
#include "Sales_data.h"
using std::cerr;
using std::endl;
using std::ifstream;
using std::ofstream;
int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        cerr << "Wrong input!" << endl;
        return -1;
    }
    ifstream input(argv[1]); // open the file of sales transactions
    ofstream output(argv[2]); // open the output file
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
                print(output, total) << endl; // print the results
                total = trans; // process the next book
            }
        }
        print(output, total) << endl; // print the last transaction
    }
    else
    {
        cerr << "No data?!" << endl; // no input
    }
    return 0;
}
// Note: if no input or output file is provided, the program will crash.
