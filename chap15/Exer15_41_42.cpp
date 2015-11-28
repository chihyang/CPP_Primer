#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Exer15_41_42_TextQuery.h"
#include "Exer15_41_42_Query.h"
using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ifstream;
using std::istringstream;
using std::string;
int main(int argc, char* argv[])
{
	if(argc != 2 && argc != 4)
		return -1;
	ifstream is(argv[1]);
	TextQuery tq(is);
	cout << "Input 3 words or input q to quit:" << endl;
	string opt;
	while(getline(cin, opt) && opt != "q")
	{
		string sought1, sought2, sought3;
		istringstream istr(opt);
		istr >> sought1 >> sought2 >> sought3;
		Query q = Query(sought1) & Query(sought2) | Query(sought3);
		QueryResult qr = q.eval(tq);
		TextQuery::line_no min, max;
		cout << "Int two numbers of range between 1 and " << qr.get_file()->size() << "\n";
		while(cin >> min >> max)
		{
			cout << "Executing Query for: " << q << "\n";
			print(cout, qr, min, max);
		}
		cin.clear();
		cout << "Input 3 words or input q to quit:\n";
	}
	return 0;
}