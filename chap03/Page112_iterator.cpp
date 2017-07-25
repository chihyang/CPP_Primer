// This is a display of basic algorithm: binary search.
#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
bool binarySearch(vector<int> text, int sought)
{
    auto beg = text.begin(), end = text.end();
    auto mid = text.begin() + (end - beg) / 2;
    while(mid != end && *mid != sought)
    {
        if(sought < *mid)
            end = mid;
        else
            beg = mid + 1;
        mid = beg + (end - beg) / 2;
    }
    return !(mid == end);
}
int main()
{
    vector<int> v = {2, 4, 9, 10, 23, 2, 8, 9};
    int sought;
    cin >> sought;
    if(binarySearch(v, sought))
        cout << sought << " is in vector." << endl;
    else
        cout << sought << " is not in vector." << endl;
    return 0;
}
