#include <iostream>
#include "Exer15_39_TextQuery.h"
#include "Exer15_39_Query.h"
#include "Exer15_39_AndQuery.h"
#include "Exer15_39_OrQuery.h"
#include "Exer15_39_NotQuery.h"
using std::cout;
using std::endl;
using std::ifstream;
int main(int argc, char* argv[])
{
	if(argc != 2)
		return -1;
	ifstream is(argv[1]);
	TextQuery tq(is);
	Query q = Query("fiery") & Query("bird") | Query("wind");
	QueryResult qr = q.eval(tq);
	cout << q.rep() << endl;
	cout << "Executing Query for: " << q << endl;
	print(cout, qr);
	return 0;
}