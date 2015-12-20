// Warning: this is for verification. Template declarations and definitions should be put into header files.
#include <iostream>
#include <utility>
using std::cout;
using std::endl;
template <class T> struct remove_reference {
	typedef T type;
};
template <class V> struct remove_reference<V&> {
	typedef V type;
};
template <class V> struct remove_reference<V&&> {
	typedef V type;
};
int main()
{
	int i;
	decltype(42) i1;           // int, uninitialized
	decltype(i) i2;            // int, uninitialized
	decltype((i)) i3 = i;          // int& , should be initialized, see page 71
	decltype(std::move(i)) i4 = 8; // int&&, should be initialized
	remove_reference<decltype(42)>::type a = 1;  // int
	remove_reference<decltype(i)>::type* b = 0;  // int*, won't be misunderstood
	remove_reference<decltype((i))>::type c = 3; // int,
	typename remove_reference<decltype(std::move(i))>::type d = 4; // ok: add typename
	cout << a << " " << b << " " << c << " " <<  d << " " << endl;
	return 0;
}
// Note #1: on page 711, the comments of this statement:
// remove_reference<decltype(i)>::type b;
// says:
// decltype(i) is int&, uses first (T&) partial specialization
// seems this is wrong. The result of decltype for a variable should be the type
// of the it rather than its reference.

// Note #2: in this program, we can either add typename when accessing type member
// of remove_reference or not. This won't cause ambiguity because the template
// has already been instantiated. However, if we access inside remove_reference,
// such as accesing remove_reference<T>::type, we have to add typename before
// accesing it. In this case, compiler cannot know whether type is a data member
// or type alias member.