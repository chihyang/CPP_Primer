// Warning: this is for verification. It cannot compile.
struct A {
	A(int = 0); // usually a bad idea to have two
	A(double);  //conversions from arithmetic types
	operator int() const;       // usually a bad idea to have two
	operator double() const;    // conversions to arithmetic types
	// other members
};
int main()
{
	// ambiguity #1
	void f2(long double);
	A a;
	f2(a); // error ambiguous: f(A::operator int())
	       //              or: f(A::operator double())  
	// ambiguity #2
   long lg = 0;
	A a2(lg); // error ambiguous: A::A(int) or A::A(double)
	// #3
	// promoting short to int is better than converting short to double
	short s = 42;
	A a3(s); // use A::A(int)
	return 0;
}
void f2(long double) {}
// Note: #1 is ambiguous because conversion from int to long double and double
// from long double has the same rank(there's no "float promotion");
// #2 is ambiguous because conversion from long to int and double to int has the 
// same rank(shrink from long to int is arithmetic conversion rather than 
// integral promotion).