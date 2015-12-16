#include <iostream>
#include <typeinfo>
#include "Exer19_06_07_08_TextQuery.h"
#include "Exer19_06_07_08_Query.h"
using std::cout;
using std::endl;
using std::bad_cast;
void cast_test()
{
	// exercise 19.6
	Query_base *pb1 = new AndQuery(Query("value1"), Query("value2"));
	Query_base *pb2 = new OrQuery(Query("value1"), Query("value2"));
	if(AndQuery *pa1 = dynamic_cast<AndQuery*>(pb1)) {
		cout << "cast succeeds!" << endl;
	} else {
		cout << "cast fails!" << endl;
	}
	if(AndQuery *pa2 = dynamic_cast<AndQuery*>(pb2)) {
		cout << "cast succeeds!" << endl;
	} else {
		cout << "cast fails!" << endl;
	}
	// exercise 19.7
	try {
		AndQuery &ra1 = dynamic_cast<AndQuery&>(*pb1);
		cout << "cast succeeds!" << endl;
	} catch(bad_cast e) {
		cout << e.what() << endl;
	}
	try {
		AndQuery &ra2 = dynamic_cast<AndQuery&>(*pb2);
		cout << "cast succeeds!" << endl;
	} catch(bad_cast e) {
		cout << e.what() << endl;
	}
	// exercise 19.8
	if(typeid(*pb1) == typeid(*pb2))
		cout << "pb1 and pb2 points to the same type" << endl;
	else
		cout << "dynamic types of pb1 and pb2 are different" << endl;
	if(typeid(*pb1) == typeid(AndQuery))
		cout << "dynamic type of pb1 is AndQuery" << endl;
	else
		cout << "dynamic type of pb1 is not AndQuery" << endl;
	if(typeid(*pb2) == typeid(AndQuery))
		cout << "dynamic type of pb2 is AndQuery" << endl;
	else
		cout << "dynamic type of pb2 is not AndQuery" << endl;
}
int main()
{
	cast_test();
	return 0;
}