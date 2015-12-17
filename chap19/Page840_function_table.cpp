#include <iostream>
#include "Page840_Screen.h"
using std::cout;
using std::endl;
int main()
{
	Screen myScreen(10, 10, 'c');
	cout << myScreen;
	cout << "move cursor to (5, 5):\n";
	myScreen.move(5, 5);
	cout << myScreen;
	// move cursor
	cout << "advance cursor by one step:\n";
	myScreen.move(Screen::FORWARD);
	cout << myScreen;
	cout << "move cursor one step back:\n";
	myScreen.move(Screen::BACK);
	cout << myScreen;
	cout << "move cursor one line back:\n";
	myScreen.move(Screen::UP);
	cout << myScreen;
	cout << "move cursor one line forward:\n";
	myScreen.move(Screen::DOWN);
	cout << myScreen;
	cout << "move cursor to the beginning:\n";
	myScreen.move(Screen::HOME);
	cout << myScreen;
	return 0;
}