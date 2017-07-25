#ifndef EXER07_29_H
#define EXER07_29_H
#include <iostream>
#include <string>
class Screen{
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
    char get() const { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;
    Screen& move(pos r, pos c);
    Screen set(pos row, pos col, char c);
    Screen set(char c);
    const Screen& display(std::ostream &os) const;
private:
    void do_display(std::ostream &os) const; // declare as const to apply to all cases
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
inline Screen Screen::set(pos row, pos col, char c)
{
    contents[row * width + col] = c;
    return *this;
}
inline Screen Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}
const Screen& Screen::display(std::ostream &os) const
{
    do_display(os);
    return *this;
}
inline void Screen::do_display(std::ostream &os) const
{
    os << contents;
}
#endif
