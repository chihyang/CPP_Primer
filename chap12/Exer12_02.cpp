#include <iostream>
#include <stdexcept>
#include "StrBlob.h"
using std::cout;
using std::endl;
using std::out_of_range;
int main()
{
	StrBlob b1;
	cout << b1.use_count() << endl;
	{
		StrBlob b2 = {"a", "an", "the"};
		b1 = b2;
		b2.push_back("about");
		cout << b2.use_count() << endl;
	}
	cout << b1.use_count() << endl;
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