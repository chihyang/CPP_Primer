#include <iostream>
#include <fstream>
#include <string>
#include "Exer17_03_TextQuery.h"
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;
void runQueries(ifstream &infile)
{
    // infile is an ifstream that is the file we want to query
    TextQuery tq(infile); // store the file and build the query map
    // iterate with the user: prompt for a word to find and print the result
    while(true)
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        // stop if we hit end-of-file on the input or if a 'q' is entered
        if(!(cin >> s) || s == "q")
            break;
        // run the query and print the results
        print(cout, tq.query(s)) << endl;
    }
}
int main(int argc, char* argv[])
{
    if(argc != 2)
        return -1;
    ifstream infile(argv[1]);
    runQueries(infile);
    return 0;
}
