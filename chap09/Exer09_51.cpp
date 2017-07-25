#include <iostream>
#include <string>
#include <stdexcept>
#include "Exer09_51.h"
using std::cin;
using std::cerr;
using std::endl;
using std::string;
using std::invalid_argument;
int main()
{
    string d;
    while(getline(cin, d))
    {
        try
        {
            Date date(d);
            date.print_date();
        }
        catch(invalid_argument inv_arg)
        {
            cerr << inv_arg.what()
                 << "\nTry again? Enter y or n" << endl;
            char c;
            cin >> c;
            if(!cin || c == 'n')
                break;
        }
    }
    return 0;
}
