#include <iostream>
#include <string>
#include <memory>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::allocator;
int main()
{
    string::size_type n = 10;
    string s;
    allocator<string> alloc;
    auto const p = alloc.allocate(n);
    auto q = p;
    while(cin >> s && q != p + n)
        alloc.construct(q++, s);
    for(auto ps = p; ps != q; ++ps)
        cout << *ps << " ";
    cout << endl;
    // destroy the objects
    while(q != p)
        alloc.destroy(--q);
    // free memory
    alloc.deallocate(p, n);
    return 0;
}
