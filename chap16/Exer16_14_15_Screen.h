#ifndef EXER16_14_15_SCREEN_H
#define EXER16_14_15_SCREEN_H
#include <iostream>
#include <string>
#include <vector>
template <unsigned H, unsigned W> class Screen;
template <unsigned H, unsigned W> std::ostream& operator<<(std::ostream&, const Screen<H, W>&);
template <unsigned H, unsigned W> std::istream& operator>>(std::istream&, Screen<H, W>&);
template <unsigned H, unsigned W>
class Screen {
    friend std::ostream& operator<< <H, W>(std::ostream&, const Screen<H, W>&);
    friend std::istream& operator>> <H, W>(std::istream&, Screen<H, W>&);
public:
    using pos = std::string::size_type;
    Screen() : contents(H * W, '\0') {}
    Screen(char c) : contents(H * W, c), cursor(0) {}
    char get() const { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;
    Screen& move(pos r, pos c);
    Screen& set(pos row, pos col, char c);
    Screen& set(char c);
private:
    void do_display(std::ostream& os) const;
    pos cursor = 0;
    unsigned height = H, width = W;
    std::string contents;
};
template <unsigned H, unsigned W>
char Screen<H, W>::get(pos ht, pos wd) const
{
    pos row = wd * width;
    return contents[row + ht];
}
template <unsigned H, unsigned W>
Screen<H, W>& Screen<H, W>::move(pos r, pos c)
{
    cursor = r * width + c;
    return *this;
}
template <unsigned H, unsigned W>
Screen<H, W>& Screen<H, W>::set(pos row, pos col, char c)
{
    contents[row * width + col] = c;
    return *this;
}
template <unsigned H, unsigned W>
Screen<H, W>& Screen<H, W>::set(char c)
{
    contents[cursor] = c;
    return *this;
}
template <unsigned H, unsigned W>
inline void Screen<H, W>::do_display(std::ostream& os) const
{
    os << contents;
}
template <unsigned H, unsigned W>
std::ostream& operator<<(std::ostream &os, const Screen<H, W> &s)
{
    s.do_display(os);
    return os;
}
template <unsigned H, unsigned W>
std::istream& operator>>(std::istream &is, Screen<H, W> &s)
{
    char c;
    is >> c;
    s.set(c);
    return is;
}
#endif
