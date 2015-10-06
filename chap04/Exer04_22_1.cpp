// conditional version
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{
	vector<int> v = {99, 92, 60, 83, 76, 0, 11, 22, 73,  90, 56};
	string result;
	for(auto p = v.begin(); p != v.end(); ++p)
	{
		result = *p > 90 ? "high pass" 
	                  : (*p > 75) ? "pass" 
					  : (*p > 60) ? "low pass" : "fail";
		cout << result << " ";
	}
	cout << endl;
	return 0;
}