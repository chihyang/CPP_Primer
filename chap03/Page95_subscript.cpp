#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
	const string hexdigits = "0123456789ABCDEF";
	cout << "Enter a series of numbers between 0 and 15"
	     << " separated by spaces. Hit ENTER when finished: "
		 << endl;
	string result;
	string::size_type n;
	while(cin >> n)
		if(n < hexdigits.size())
			result += hexdigits[n];
	cout << "Your hex number is: " << result << endl;
	return 0;
}

// In fact, just hit ENTER won't stop input. 
// You have to hit ENTER and press CTRL+Z to complete input.
