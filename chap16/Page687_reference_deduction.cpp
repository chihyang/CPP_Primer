// Warning: this is for illustration. Template declarations and definitions should be put into header files.
// Warning: this program cannot compile. The problem lies in line 13.
template <typename T> void f1(T&) {} // argument must be an lvalue
template <typename T> void f2(const T&) {} // can take an rvalue
template <typename T> void f3(T&&) {}
int main()
{
	int i = 0;
	const int ci = 42;
	int &&ri = 1;
	// calls to f1 use the referred-to type of the argument as the template parameter type
	f1(i);  // i is an int; template parameter T is int
	f1(ci); // ci is a const int; template T is const int
	f1(5);  // error: argument to a & parameter must be an lvalue
	
	// parameter in f2 is const &; const in the argument is irrelevant
	// in each of these three calls, f2's function parameter is inferred as const int&
	f2(i);  // i is an int; template parameter T is int
	f2(ci); // ci is a const int, but template parameter T is int
	f2(5);  // a const & parameter can be bound to an rvalue; T is int
	
	// we can pass argument of any type to f3 because of special rule for type 
	// deduction for rvalue reference parameter and reference collapse
	f3(i);  // argument is an lvalue of type int; template parameter T is int&; function parameter is int&
	f3(ci); // argument is an lvalue of type int; template parameter T is const int&; function parameter is const int&
	f3(42); // argument is an rvalue of type int; template parameter T is int
	f3(42); // argument is an rvalue of type int; template parameter T is int
	return 0;
}