#include <iostream>
#include <stdexcept>
#include "Exer13_26.h"
using std::cout;
using std::endl;
using std::out_of_range;
int main()
{
	StrBlob b1 = {"what", "when", "how"};
	cout << b1.use_count() << endl;
	StrBlob b2 = b1; // copy initialization
	cout << b2.use_count() << endl;
	b2.push_back("whether"); // won't influence the value of b1
	cout << b1.back() << endl;
	cout << b2.back() << endl;
	{
		StrBlob b2 = {"a", "an", "the"};
		b1 = b2; // assign local b2 to b1
		b2.push_back("about");
		cout << b2.use_count() << endl;
	}
	b1 = b1; // assign to itself
	cout << b1.use_count() << endl; // reference count is still 1
	const StrBlob b3({"and", "or", "not"});
	cout << b3.front() << " "<< b3.back() << endl;
	StrBlob b4 = b3;
	cout << b4.use_count() << endl;
	try
	{
		StrBlob b5;
		cout << b5.front();
	}
	catch(out_of_range err)
	{
		cout << err.what() << endl;
	}
	return 0;
}