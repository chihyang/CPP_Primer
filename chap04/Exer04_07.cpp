#include <iostream>
using std::cout;
using std::endl;
int main()
{
	short si1 = 32767;
	si1 += 1;
	unsigned short si2 = 0xFFFF;
	si2++;
	unsigned char ch = 256;
	// overflow, get a warning from g++, but nothing from cl
	cout << si1 << " "<< si2 << " " << ch << " " << endl;
	return 0;
}