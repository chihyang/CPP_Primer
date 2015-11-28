#include <iostream>
#include <string>
#include "Exer15_39_TextQuery.h"
#include "Exer15_39_Query.h"
#include "Exer15_39_AndQuery.h"
#include "Exer15_39_OrQuery.h"
#include "Exer15_39_NotQuery.h"
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;
int main(int argc, char* argv[])
{
	if(argc != 2)
		return -1;
	ifstream is(argv[1]);
	TextQuery tq(is);
	string sought1, sought2, sought3;
	cout << "Input 3 words:" << endl;
	while(cin >> sought1 >> sought2 >> sought3)
	{
		Query q = Query(sought1) & Query(sought2) | Query(sought3);
		QueryResult qr = q.eval(tq);
		cout << q.rep() << endl;
		cout << "Executing Query for: " << q << endl;
		print(cout, qr);
	}
	return 0;
}