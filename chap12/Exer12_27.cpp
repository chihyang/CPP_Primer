// Warning: this program has run time error. See notes below.
// The problem is inherent in class.
#include <iostream>
#include <string>
#include "Exer12_27.h"
using std::cout;
using std::cin;
using std::endl;
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
// ONCE. See following sections for right way to implement these classes.