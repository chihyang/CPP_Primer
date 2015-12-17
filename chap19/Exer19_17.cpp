#include <iostream>
#include "Exer19_17_Screen.h"
using std::cout;
using std::endl;
int main()
{
	Screen::Action1 get1 = &Screen::get;
	Screen::Action2 get2 = &Screen::get;
	Screen::Action3 mv = &Screen::move;
	Screen myScreen(20, 30, 'o'), *pScreen = &myScreen;
	cout << (myScreen.*get1)() << endl;     // call get()
	cout << (pScreen->*get2)(0, 0) << endl; // call get(pos, pos)
	(myScreen.*mv)(0, 0);                   // call move(pos, pos)
	return 0;
}