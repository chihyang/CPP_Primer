// Warning: this is for verification. Don't use noexcept in the way below.
#include <stdexcept>
class Foo {
public:
    Foo() = default;
    Foo(const Foo&f) : i(f.i) {}
    Foo(Foo&&) noexcept;
private:
    void throw_exp();
    int i = 0;
};
Foo::Foo(Foo &&f) noexcept : i(f.i)
{
    throw_exp();
}
void Foo::throw_exp()
{
    throw std::runtime_error("this is an exception function");
}
int main()
{
    Foo f1;
    Foo f2(std::move(f1));
    return 0;
}
// Note: class Foo has a move constructor that calls throw_exp, which throws
// exception deliberately. But this constructor still is marked as noexcept.
// It seems that noexcept doesn't influence whether a function really throws
// exception. Even if a functions does throw one, we can mark it as noexcept.
// As the note on page 535 says:
// move constructors and move assignment operators that cannot throw exceptions
// should be marked as noexcept.
// This implies if move constructor or assignment operator really throw
// exceptions, we shouldn't mark it as noexcept.
