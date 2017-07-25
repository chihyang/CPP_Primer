// Screen header from exercise 7.29. Fulfilment move operation.
#ifndef PAGE840_SCREEN_H
#define PAGE840_SCREEN_H
#include <iostream>
#include <sstream>
#include <string>
class Screen{
    friend std::ostream& operator<<(std::ostream&, const Screen&);
public:
    typedef std::string::size_type pos;
    // Action is a pointer that can be assigned any of the cursor movement members
    using Action = Screen& (Screen::*)();
    // specify which direction to move
    enum Directions { HOME, FORWARD, BACK, UP, DOWN };
    Screen& move(Directions);
    // other interface and implementation as in exercise 7.29
    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
    char get() const { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;
    Screen& move(pos r, pos c);
    Screen set(pos row, pos col, char c);
    Screen set(char c);
    Screen& display(std::ostream &os);
    const Screen& display(std::ostream &os) const;
private:
    // cursor movement functions
    Screen& home();
    Screen& forward();
    Screen& back();
    Screen& up();
    Screen& down();
    void do_display(std::ostream &os) const; // declare as const to apply to all cases
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    static Action Menu[]; // function table
};
inline char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}
inline Screen& Screen::move(pos r, pos c)
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
inline Screen& Screen::display(std::ostream &os)
{
    do_display(os);
    return *this;
}
inline const Screen& Screen::display(std::ostream &os) const
{
    do_display(os);
    return *this;
}
// enhance do_display to show a rectangle
inline void Screen::do_display(std::ostream &os) const
{
    std::ostringstream scr_buff;
    for (pos i = 0; i != height; ++i) {
        // display the location of cursor
        if (i * width <= cursor && cursor < (i + 1) * width) {
            std::string line_str = contents.substr(i * width, width);
            line_str[cursor - i * width] = '_';
            scr_buff << line_str << "\n";
        } else {
            scr_buff << contents.substr(i * width ,width) << "\n";
        }

    }
    os << scr_buff.str();
}
inline std::ostream& operator<<(std::ostream &os, const Screen &s)
{
    s.do_display(os);
    return os;
}
#endif
