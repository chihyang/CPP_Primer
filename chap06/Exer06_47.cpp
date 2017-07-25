#include <iostream>
#include <vector>
#include <cassert>
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
void printVec(const vector<int> &vec, int beg, int size)
{
    if(vec.empty())
        return;
    if(size - beg > 0)
    {
        #ifndef NDEBUG
        cerr << "\n" << __FUNCTION__ << ":\n"
             << "The size of the vector:" << size - beg << endl;
        #endif
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
// Note: for visual studio compiler, substitute __FUNCTION__ for __func__,
// for g++, both __FUNCTION__ and __func__ are okay.
