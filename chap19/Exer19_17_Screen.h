// Screen header from exercise 7.23.
#ifndef EXER19_17_SCREEN_H
#define EXER19_17_SCREEN_H
#include <string>
class Screen{
	// for test, required by exercise 19.12
	friend void ptrTest();
public:
	typedef std::string::size_type pos;
	// type alias for every kind of member function, required by exercise 19.17
	using Action1 = char (Screen::*)() const;
	using Action2 = char (Screen::*)(pos, pos) const;
	using Action3 = Screen& (Screen::*)(pos, pos);
	// return a pointer to data member, required by exercise 19.12
	static const std::string Screen::*data()
	    { return &Screen::contents; }
	Screen() = default;
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
	char get() const { return contents[cursor]; }
	char get_cursor() const { return contents[cursor]; }
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
#endif