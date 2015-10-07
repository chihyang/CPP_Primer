#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{
	string s = "This is the string. Ask for my size.";
	string s2;
	vector<int> v = {2, 3, 5, 7, 9};
	vector<int> v2;
	vector<double> v3;
	cout << "size of a string returned by sizeof: " << sizeof(s) << " " 
	     << sizeof(s2) << endl;
	cout << "size of a string returned by string.size: " << s.size() << endl;
	cout << "size of a vector: " << sizeof(v) << " " 
	     << sizeof(vector<string>) << endl;
	cout << "size of a vector returned by vector.size: " << v.size() << endl;
	return 0;
}

// Note: result returned by sizeof of a string or vector is a fixed value.
// It doesn't matter what type vector is and how many elements in a vector or 
// string.