#include <iostream>
#include <stdexcept>
#include "Exer16_12_Blob.h"
using std::cout;
using std::endl;
using std::string;
using std::out_of_range;
int main()
{
	Blob<int> blob1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	Blob<int> blob2 = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	BlobPtr<int> ps(blob1);
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
	cout << "*ps = " << *ps << endl;
	cout << "ps[5] = " << ps[5] << endl;
	cout << "*++ps = " << *ps << endl;
	cout << "*ps++ = " << *ps << endl;
	cout << "*--ps = " << *ps << endl;
	cout << "*ps-- = " << *ps << endl;
	ps += 4;
	cout << "ps += 4 = " << *ps << endl;
	// out_of_range exception
	try {
		ps -= 20;
		cout << "ps -= 20 = " << *ps << endl;
	}
	catch(out_of_range err){
		std::cerr << err.what() << endl;
	}
	ps = ps + 22;
	cout << "(ps = ps - 22) = " << *ps << endl;
	ps = ps - 1;
	cout << "(ps = ps + 1) = " << *ps << endl;
	return 0;
}