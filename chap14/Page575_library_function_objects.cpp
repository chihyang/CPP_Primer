#include <iostream>
#include <vector>
#include <functional>
using std::cout;
using std::endl;
using std::vector;
using std::plus;
using std::negate;
int main()
{
	plus<int> intAdd;       // function object that can add two int values
	negate<int> intNegate;  //function object that can negate an int value
	// uses intAdd::operator(int, int) to add 10 and 20
	int sum = intAdd(10, 20);           // equivalent to sum = 30
	cout << sum << endl;
	sum = intNegate(intAdd(10, 20));    // equivalent to sum = 30
	cout << sum << endl;
	// uses intNegate::operator(int) to generate -10 as the second parameter
	// to intAdd::operator(int, int)
	sum = intAdd(10, intNegate(10));      // sum = 10
	cout << sum << endl;
	return 0;
}