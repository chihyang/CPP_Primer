#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
int main()
{
    vector<int> ivec(10);
    vector<int>::size_type cnt = ivec.size();
    // Here, whether you use
    // (++ix, --cnt), (++ix, cnt--), (ix++, --cnt) or (ix++, cnt--)
    // You are doomed to the same way.
    for(vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
        ivec[ix] = cnt;
    for(auto i : ivec)
        cout << i << " ";
    cout << endl;
    return 0;
}
