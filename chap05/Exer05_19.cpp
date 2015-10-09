#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
	do{
		string s1, s2;
		cin >> s1 >> s2;
		// To be honest, judge if s1 and s2 are empty is surplus here. Just I 
		// remind myself that checking boundary conditions is essential.
		if(!s1.empty() && !s2.empty()){
			if(s1 < s2)
				cout << "The first string is less than the second." << endl;
			else if(s1 > s2)
				cout << "The second string is less than the first." << endl;
			else
				cout << "Two strings are equal." << endl;
		}
	}while(cin);
	return 0;
}