#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
void printVec(const vector<int> &vec, int beg, int size)
{
    if(vec.empty())
        return;
    if(size - beg > 0)
    {
        cout << vec[beg] << " ";
        printVec(vec, ++beg, size);
    }
}
int main()
{
    vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printVec(vi, 0, vi.size());
    cout << endl;
    return 0;
}
