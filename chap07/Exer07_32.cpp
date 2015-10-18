// Note: this exercise requires careful structuring. See notes in header file 
// for details.
#include <iostream>
#include "Exer07_32.h"
int main()
{
	Screen s(24, 80, 'x');
	Window_mgr win(s); // initialize win with s;
	std::cout << "The original win:" << std::endl;
	win.get(0).display(std::cout);
	std::cout << std::endl;
	win.clear(0);
	std::cout << "The cleared win:" << std::endl;
	win.get(0).display(std::cout);
	return 0;
}