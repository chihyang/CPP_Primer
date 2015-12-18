// Note: this file contains explanation to a long-standing problem issued in 
// Exer13_55_String.h. See below.
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using std::size_t;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::function;
size_t cnt_empty(const vector<string> &vec)
{
	function<bool(const string&)> fcn = &string::empty;
	return count_if(vec.begin(), vec.end(), fcn);
}
int main()
{
	vector<string> vec = { "", "this", "", "is", "", "a", "", "string" };
	cout << cnt_empty(vec) << endl;
	return 0;
}
// Note: here let's see a long-standing problem: when we use generic algorithms,
// we hardly use the using declaration, but they still work fine. Why? Consider
// the situation where generic algorithms are used. These function templates take
// an input range as their arguments. The input range is almost always represented
// by a pair of iterators, and iterator is a class type defined in std namespace.
//
// One exception of name lookup of namespace is that when we pass an object of a
// class type to a function, the compiler searches the namespace in which the
// argument's class is defined in addition to the normal scope lookup. This exception
// also applies for calls that pass pointers or references to a class type.
// (section 18.2.3, page 798)
//
// According to the rule exception above, when we pass iterators to generic 
// algorithms, the compiler will automatically search the namespace std for the
// definition of the algorithm. As a result, we needn't use using declaration
// explicitly. On the other hand, if we define an array of int and two pointers
// as below:
//	int a[] = { 1, 2, 3, 4, 5 };
//	int *b = a, *e = a + 4;
// and we pass b and e to an algorithm, we must declare to use the algorithm:
//	using std::count;
//	count(b, e, 1);
// or the compiler would complain that it couldn't find the definition of count.
//
// Now we can solve the problem in Exer13_55_String.h: allocate returns a pointer
// to char in this example, b and e are pointers to const char. So none of the
// arguments of uninitialized_copy are class types that reside in namespace std.
// Thus the compiler won't search std for the definition of uninitialized_copy. As
// a result, we must use std::uninitialized_copy or using std::uninitialized_copy
// in this example.
//
// There is one exception, subtle but important: for functions that uses explicit
// template arguments. We almost always need to use using declarations. 
// See Exer19_18_ADL.cpp for detailed explanations.