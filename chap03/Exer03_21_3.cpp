// Page 105, exercise 20
// Tips: Some situations must be considered carefully.
// For example: What if the vector is null? What if the vector has only one element?
// Here using iterator is easier to prevent buffer overflow than subscript.
#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
int main()
{
	vector<int> v;
	int i;
	while(cin >> i)
	{
		v.push_back(i);
	}
	auto j = v.begin();
	if(v.begin() != v.end())
	{		
		if(v.size() == 1)
			cout << *v.begin() << endl;
		else
		{
			for(auto j = v.begin(); (j + 1) != v.end() && j!= v.end(); ++j)
			{
				cout << *j + *(j + 1) << " ";
			}
			cout << endl;
		}
		auto f = v.begin(), b = v.end();
		for(--b; f <= b; ++f, --b)
		{
			if(f < b)	
				cout << *f + *b << " ";
			else
				cout << *f << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "No elements!" << endl;
	}
	return 0;
}