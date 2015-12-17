#include <iostream>
#include <string>
#include "Exer19_12_Screen.h"
using std::cout;
using std::endl;
using std::string;
void ptrTest()
{
	const string Screen::*pdata;
	pdata = &Screen::contents; // must be in class or in a friend
	Screen myScreen(20, 20, 'x'), *pScreen = &myScreen;
	cout << myScreen.*pdata << endl;
	cout << pScreen->*pdata << endl;
}
int main()
{
	ptrTest();
	const string Screen::*pdata = Screen::data();
	Screen myScreen(10, 20, 'a'), *pScreen = &myScreen;
	cout << myScreen.*pdata << endl;
	cout << pScreen->*pdata << endl;
	return 0;
}