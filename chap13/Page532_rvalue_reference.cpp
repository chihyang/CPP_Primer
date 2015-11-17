// Warning: this is for verification. It cannot compile.
// The problem lies in line 7 and 8.
int main()
{
	int i = 42; 
	int &r = i; // ok: r refers to i
	int &&rr = i;// error: cannot bind an rvalue reference to an lvalue
	int &r2 = i * 42; // error: i * 42 is an rvalue
	const int &r3 = i * 42; // ok: we can bind a reference to const to an rvalue
	int &&rr2 = i * 42; // ok: bind rr2 to the result of the multiplication
	return 0;
}