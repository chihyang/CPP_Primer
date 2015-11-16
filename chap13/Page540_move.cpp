#include <utility>
class Foo {
public:
	Foo() = default;
	Foo(const Foo&) {} // copy constructor
	// other members, but Foo does not define a move constructor
};
int main()
{
	Foo x;
	Foo y(x); // copy constructor; x is an lvalue
	Foo z(std::move(x)); // copy constructor, because there is no move constructor
	return 0;
}