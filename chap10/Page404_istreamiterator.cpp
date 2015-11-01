#include <iostream>
#include <vector>
#include <iterator>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::istream_iterator;
int main()
{
	istream_iterator<int> in_iter(cin);
	istream_iterator<int> eof;
	vector<int> vec1;
	while(in_iter != eof)
		vec1.push_back(*in_iter++);
	cin.clear(); // clear flags for latter input
	istream_iterator<int> in_iter2(cin); // now in_iter == eof, so we have to define another
	vector<int> vec2(in_iter2, eof);
	for(auto i : vec1)
		cout << i << " ";
	cout << endl;
	for(auto i : vec2)
		cout << i << " ";
	cout << endl;
	return 0;
}