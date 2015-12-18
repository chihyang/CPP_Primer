#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Exer12_22_StrBlob.h"
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;
using std::out_of_range;
using std::runtime_error;
int main()
{
	// const version of StrBlob, cannot add or remove elements
	const StrBlob text({"This", "is", "a", "little", "child."});
	ConstStrBlobPtr text_ptr(text);
	try
	{
		int i = 0;
		while(i < text.size())
		{
			cout << text_ptr.deref() << " ";
			++i;
			text_ptr.incr();
		}
		cout << endl;
	}
	catch(out_of_range out)
	{
		cout << out.what() << endl;
	}
	catch(runtime_error run)
	{
		cout << run.what() << endl;
	}
	return 0;
}