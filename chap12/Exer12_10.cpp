#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;
void process(shared_ptr<int> ptr)
{
	cout << ptr.use_count() << endl;
}
int main()
{
	shared_ptr<int> p(new int(42));
	cout << p.use_count() << endl;
	process(shared_ptr<int>(p));
	cout << p.use_count() << endl;
	return 0;
}