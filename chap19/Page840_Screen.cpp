#include "Page840_Screen.h"
// initialize static member
Screen::Action Screen::Menu[] = { &Screen::home,
                                  &Screen::forward,
                                  &Screen::back,
                                  &Screen::up,
                                  &Screen::down
                                };
Screen& Screen::move(Directions cm)
{
	// run the element indexed by cm on this object
	return (this->*Menu[cm])(); // Menu[cm] points to a member function
}
inline Screen& Screen::home()
{
	cursor = 0;
	return *this; 
}
inline Screen& Screen::forward()
{ 
	if(cursor < height * width - 1)
		++cursor;
	return *this;
}
inline Screen& Screen::back() {
	if(cursor > 0)
		--cursor;
	else
		cursor = 0;
	return *this;
}
inline Screen& Screen::up(){
	if(cursor - width > 0)
		cursor -= width;
	else
		cursor = 0;
	return *this;
}
inline Screen& Screen::down() {
	if(cursor + width < height * width)
		cursor += width;
	else
		cursor = height * width - 1;
	return *this;
}
// Note: in this file, only home, forward, back, up and down is inline. We can't
// declare a function as inline if it's in a source file and it will be called
// by functions in other source files. Or the compiler would complain that it 
// cannot find the definition of the function. See this link:
// https://stackoverflow.com/questions/7883022/inline-in-source-file