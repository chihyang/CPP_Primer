#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{	
	vector<string> si{ "7", "198", "39", "429", "345", "440", "66", "432", "17", "500", "331" };
	vector<string> sd{ "-3.0016", "2.4498", "3.6968", "8.5594", "-0.9706", "-10.6917", "-4.1979" }; 
	int sumi = 0;
	double sumd = 0;
	for(auto i : si)
		sumi += stoi(i);
	for(auto d : sd)
		sumd += stod(d);
	cout << sumi << endl;
	cout << sumd << endl;
	return 0;
}