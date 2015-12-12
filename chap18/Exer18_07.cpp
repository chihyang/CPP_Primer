#include <iostream>
#include <stdexcept>
#include "Exer18_07_Blob.h"
using std::cout;
using std::endl;
using std::string;
using std::out_of_range;
int main()
{
	// test for blob:
	Blob<int> blob1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	Blob<int> blob2 = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	for(typename Blob<int>::size_type i = 0; i != blob1.size(); ++i)
		cout << blob1[i] << " ";
	cout << endl;
	cout << "blob1.size(): " << blob1.size() << endl;
	blob1.push_back(12);
	cout << "blob1.size(): " << blob1.size() << endl;
	blob1.pop_back();
	blob1.pop_back();
	cout << "blob1.front(): " << blob1.front() << endl;
	cout << "blob1.back(): " << blob1.back() << endl;
	blob1.front() = 20;
	cout << "blob1.front(): " << blob1.front() << endl;
	blob1[2] = 23;
	cout << "blob1[2] = " << blob1[2] << endl;
	cout << "blob1.at(8) = " << blob1[8] << endl;
	cout << "blob1 == blob2 ? " << (blob1 == blob2) << endl;
	cout << "blob1 != blob2 ? " << (blob1 != blob2) << endl;
	cout << "blob1 < blob2 ? " << (blob1 < blob2) << endl;
	cout << "blob1 <= blob2 ? " << (blob1 <= blob2) << endl;
	cout << "blob1 > blob2 ? " << (blob1 > blob2) << endl;
	cout << "blob1 >= blob2 ? " << (blob1 >= blob2) << endl;
	return 0;
}