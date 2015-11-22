int main()
{
	bool b = false;
	// error, bool is promoted to int because all of its possible values fit in
	// ant int(page 160) on a x64 machine; int is 32 bit wide, so 42 is larger 
	// than the number of bits in the result
	b << 42; 
	return 0;
}