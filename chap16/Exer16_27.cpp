// Note: this problem is not solved completely yet. 
// (a) and (f) need to be considered more.
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;
template <typename T> class Stack {};
void f1(Stack<char>) {}               // (a)
class Exercise {
	Stack<double> &rsd;               // (b)
	Stack<int> si;                    // (c)
};
int main()
{
	Stack<char> *sc;                  // (d)
	f1(*sc);                          // (e)
	int iObj = sizeof(Stack<void>);   // (f)
	cout << sizeof(string) << endl;
	cout << sizeof(vector<string>) << endl;
	cout << iObj << endl;
	return 0;
}
// Note: the book says(page 656):
// When the compiler sees the definition of a template, it does not generate code.
// It generates code only when we instantiate a specific instance of the template.
//
// Now the problem is what the "usage" of a template is? Is a pointer to a instance
// of a template a "usage"? What about reference? What about parameter declaration?
//
// According to this link:
// https://stackoverflow.com/questions/21598635/how-is-a-template-instantiated
// Only when stuff is allocated then the template has to be completely resolved.
// Thus (a), (b), (d) won't instantiate template Stack(and the member of it won't
// either), because they don't need newly allocated resource of the class.
// (c) defines an object of Stack<int>, so the class template is instantiated.
// But no member function is used, so no member function is instantiated.
// (e) uses the object sc points to to initialize parameter of f1, thus both the 
// class template and copy constructor of the class template is instantiated.
// (f) requires instantiation of the class template because it needs to evaluate
// the size of a class. But sizeof does not need to initialize an object, so no
// member function(including constructor) will be instantiated.(I'm a little 
// doubtful about this. Because no matter what template argument is offered, the
// result is the same. So is it with the library container vector. Maybe argument
// is just used as a placeholder? Not for sure.)
//
// One more thing to note is that instantiation of class template and its member
// function is separated. When a class template is instantiated, its member 
// function may not. However, when a non-static member function is instantiated,
// it implies that the class template has already been instantiated too, or we 
// can't call this member function.
