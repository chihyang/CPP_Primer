// Warning: this program has runtime error. See notes below.
// The problem is inherent in class.
#include <iostream>
#include <fstream>
#include <string>
#include "Exer12_27_TextQuery.h"
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;
void runQueries(ifstream &infile)
{
    TextQuery tq(infile);
    while(true)
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if(!(cin >> s) || s == "q")
            break;
        else
        {
            QueryResult qr(tq.query(s));
            print(cout, qr) << endl; // wrong use
        }
    }
}
int main(int argc, char* argv[])
{
    if (argc != 2)
        return -1;
    ifstream in(argv[1]);
    runQueries(in);
    return 0;
}
// Note: consider what will happen after line 22 executes. Because qr is a local
// object to if statement, it'll be destroyed after if statement is executed. It
// uses dynamically allocated object, which is initialized by the return value
// of query. However, the member of QueryResult points to tq, an object that is
// not dynamically allocated. Because shared_ptr uses delete as default deleter,
// the program cannot destroy qr as normal. As a result, THE LOOP CAN ONLY RUN
// ONCE. See subsequent sections for the correct way to implement these classes.
//
// Moreover, a more trivial problem is that we have to declare print as a friend
// function of both TextQuery and QueryResult in order to access elements stored
// in TextQuery.
//
// Thirdly, because we return this as an argument in query, we cannot declare
// query as const, or the member of QueryResult must be a const.
