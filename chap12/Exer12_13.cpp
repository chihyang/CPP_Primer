#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;
void process(shared_ptr<int> ptr)
{
    cout << ptr.use_count() << endl;
}
int main()
{
    auto sp = make_shared<int>(42);
    cout << sp.use_count() << endl;
    auto p = sp.get();
    cout << sp.use_count() << endl;
    delete p; // error: this frees memory sp points to
    cout << sp.use_count() << endl;
    *sp = 32; // error: sp becomes a dangling pointer
    return 0;
}
