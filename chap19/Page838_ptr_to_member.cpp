// Warning: this is for verification. Don't put class definitions together with function definitions.
// Warning: some functions are not defined. The program cannot link.
#include <iostream>
#include <string>
class Screen{
	friend void ptrTest();
public:
	typedef std::string::size_type pos;
	// return a pointer to data member, required by exercise 19.12
	static const std::string Screen::*data()
	    { return &Screen::contents; }
	Screen() = default;
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
	char get_cursor() const { return contents[cursor]; }
	char get() const { return contents[cursor]; }
	inline char get(pos ht, pos wd) const;
	Screen &move(pos r, pos c);
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
};
char Screen::get(pos r, pos c) const 
{
	pos row = r * width;
	return contents[row + c];
}
Screen& Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}
// Action is a type that can point to a member function of Screen
// that returns a char and takes two pos arguments
using Action = char (Screen::*)(Screen::pos, Screen::pos) const;
// action takes a reference to a Screen and a pointer to the get member of Screen
Screen& action(Screen&, Action = &Screen::get);
int main()
{
	// pmf is a pointer that can point to a Screen member function that is const
	// that returns a char and takes no arguments
	auto pmf = &Screen::get_cursor;
	// declare a pointer to member function that is const
	// that returns a char and takes two arguments of Screen::pos type
	char (Screen::*pmf2)(Screen::pos, Screen::pos) const;
	pmf2 = &Screen::get;
	pmf = &Screen::get; // must explicitly use the address-of operator
	Screen myScreen, *pScreen = &myScreen;
	// call the function to which pmf points on the object to which pScreen points
	char c1 = (pScreen->*pmf)();
	// passes the arguments 0,0 to the two-parameter version of get on the object myScreen
	// without parentheses, this means to call the function named pmf2 and use 
	// its return values as the operand of the pointer-to-member operator(.*)
	char c2 = (myScreen.*pmf2)(0, 0);
	Action get = &Screen::get; // get points to the get member of Screen
	action(myScreen);          // uses the default argument
	action(myScreen, get);     // uses the variable get that's previously defined
	action(myScreen, &Screen::get); // passes the address explicitly
	return 0;
}