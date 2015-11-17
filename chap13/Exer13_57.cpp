// Warning: this is for verification. It has run time error.
// The problem lies in line 28.
#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
class Foo {
public:
	Foo() = default;
	Foo(const vector<int> &v) : data(v) {}
	Foo(const Foo &f) : data(f.data) {}
	Foo(Foo &f) : data(std::move(f.data)) {}
	Foo& operator=(const Foo&);
	Foo& operator=(Foo&&);
	~Foo() = default;
	Foo sorted() &&;
	Foo sorted() const &;
private:
	vector<int> data;
};
Foo& Foo::operator=(const Foo &rhs)
{
	if(this != &rhs)
		data = rhs.data; 
	return *this; 
}
Foo& Foo::operator=(Foo &&rhs) 
{
	if(this != &rhs)
		data = std::move(rhs.data); 
	return *this;
}
Foo Foo::sorted() &&
{
	cout << "Foo sorted() && is called." << endl;
	sort(data.begin(),data.end());
	return *this;
}
Foo Foo::sorted() const &
{
	cout << "Foo sorted() const & is called." << endl;
	return Foo(*this).sorted(); // Foo(*this) yields an rvalue,
}
int main()
{
	Foo f = Foo({1,2,3,4}); // f is an lvalue
	f.sorted(); 
	return 0;
}