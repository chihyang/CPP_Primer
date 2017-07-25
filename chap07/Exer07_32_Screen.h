#ifndef EXER07_32_H
#define EXER07_32_H
#include <iostream>
#include <string>
#include <vector>
class Screen; // forward declaration here, or the program won't compile.
class Window_mgr {
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
    Window_mgr() = default;
    Window_mgr(const Screen& s);
    const Screen& get(ScreenIndex i) const { return screens[i]; }
private:
    std::vector<Screen> screens;//{Screen(24, 80, ' ')};
};
class Screen {
    // friend function
    friend void Window_mgr::clear(ScreenIndex);
    // friend class Window_mgr;
public:
    using pos = std::string::size_type;
    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
    char get() const { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;
    Screen& move(pos r, pos c);
    Screen& set(pos row, pos col, char c);
    Screen& set(char c);
    Screen& display(std::ostream& os);
    const Screen& display(std::ostream& os) const;
private:
    void do_display(std::ostream& os) const;
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};
char Screen::get(pos ht, pos wd) const
{
    pos row = wd * width;
    return contents[row + ht];
}
Screen& Screen::move(pos r, pos c)
{
    cursor = r * width + c;
    return *this;
}
Screen& Screen::set(pos row, pos col, char c)
{
    contents[row * width + col] = c;
    return *this;
}
Screen& Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}
Screen& Screen::display(std::ostream& os)
{
    do_display(os);
    return *this;
}
const Screen& Screen::display(std::ostream& os) const
{
    do_display(os);
    return *this;
}
inline void Screen::do_display(std::ostream& os) const
{
    os << contents;
}
Window_mgr::Window_mgr(const Screen& s)
{
    screens = {s};
}
// friend function clear()
void Window_mgr::clear(ScreenIndex i)
{
    if(i < screens.size())
    {   Screen &s = screens[i];
        s.contents = std::string(s.height * s.width, ' ');
    }
}
#endif
// Note: let's see line 15:
// 15    std::vector<Screen> screens; //{Screen(24, 80, ' ')};
// "{Screen(24, 80, ' ')}" is commented, or else this header won't compile. Why?
// Because if we initialize screens with constructor of class Screen, definition
// of this constructor must appear before the point where we use it. Thus the
// class Screen must be defined in front of class Window_mgr. But if we define
// Screen before we define Window_mgr, friend member function clear is unseen at
// the point where we declare it as a friend of class Screen. That is to say:
// Screen(24, 80, ' ') must appear after the definition of class Screen, while
// the declaration of member function clear must appear before the definition of
// class Screen! They conflict with each other. As a result, we have to comment
// this part to make the program compile.
// If we want to initialize screens with one element, we can use a constructor
// to resolve conflict. But in-class initializer is not viable here.
