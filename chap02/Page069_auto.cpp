#include <iostream>
#include <typeinfo>
using std::cout;
using std::endl;
int main()
{
	int i = 2, &ri = i, *pi = &i;
	const int ci = 42, &cri = ci, *cpi = &ci;
	int* const pci = &i;
	const int* const cpci = &ci;
	auto a1 = i;      // int
	auto a2 = ci;     // int
	auto a3 = ri;     // int
	auto a4 = cri;    // int
	auto a5 = pi;     // int*
	auto a6 = cpi;    // const int*
	auto a7 = *pi;    // int
	auto a8 = *cpi;   // int
	auto a9 = pci;    // int*
	auto a10 = cpci;  // const int*
	auto a11 = *pci;  // int
	auto a12 = *cpci; // int
	if (typeid(a1) == typeid(int))
		cout << "a1 is an int" << endl;
	if (typeid(a2) == typeid(int))
		cout << "a2 is an int" << endl;
	if (typeid(a3) == typeid(int))
		cout << "a3 is an int" << endl;
	if (typeid(a4) == typeid(int))
		cout << "a4 is an int" << endl;
	if (typeid(a5) == typeid(int*))
		cout << "a5 is an int*" << endl;
	if (typeid(a6) == typeid(const int*))
		cout << "a6 is a const int*" << endl;
	if (typeid(a7) == typeid(int))
		cout << "a7 is an int" << endl;
	if (typeid(a8) == typeid(int))
		cout << "a8 is an int" << endl;
	if (typeid(a9) == typeid(int*))
		cout << "a9 is an int*" << endl;
	if (typeid(a10) == typeid(const int*))
		cout << "a10 is a const int*" << endl;
	if (typeid(a11) == typeid(int))
		cout << "a11 is an int" << endl;
	if (typeid(a12) == typeid(int))
		cout << "a12 is an int" << endl;
	return 0;
}
