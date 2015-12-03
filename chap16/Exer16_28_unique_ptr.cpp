#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <utility>
#include "Exer16_28_unique_ptr.h"
using std::size_t;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
using std::function;
using std::runtime_error;
struct DebugDelete { // test deleter
public:
	DebugDelete(std::ostream &s = std::cerr) : os(s) {}
	template <typename T>
	void operator()(T *p) const
	{ os << "deleting unique_ptr" << std::endl; delete p; }
private:
	std::ostream &os;
};
int main()
{
	unique_ptr<int> q;
	unique_ptr<int, DefaultDeleter> q2;
	q2.reset(new int(2));
	if(!q2)
		cout << "q2 is null!" << endl;
	int *p = new int(2);
	q2 = nullptr;
	q = unique_ptr<int>(p);
	q = std::move(unique_ptr<int>(new int(9)));
	q2.reset();
	try {
		cout << *q2 << endl;
	}
	catch(runtime_error err) {
		cout << err.what() << endl;
	}
	{
		unique_ptr<vector<string>, DebugDelete> q3(new vector<string>({ "str1", "str2" }));
		cout << "q3->size(): " << q3->size() << endl;
	}
	unique_ptr<string, DebugDelete> q4;
	unique_ptr<string> q5;
	unique_ptr<string> q6;
	q4.reset(new string("q4"));
	// swap(q4, q5); // error: cannot swap two unique_ptr of different types
	q5.swap(q6); // ok
	auto sp = q4.release();
	if(!q4)
		cout << "q4 is null!" << endl;
	delete sp;
	// dynamic array
	unique_ptr<int[]> up(new int[10]());
	for(size_t i = 0; i != 10; ++i)
		cout << up[i] << " ";
	cout << endl;
	up.release();
	const unique_ptr<int> up2(new int(1)); // cannot use release and reset
	return 0;
}