#include <string>
#include <vector>
#include <algorithm>
#include "Page511_540_HasPtr.h"
using std::string;
using std::vector;
int main()
{
    vector<HasPtr> vec = { HasPtr("This"), HasPtr("is"), HasPtr("a"), HasPtr("tiger") };
    sort(vec.begin(), vec.end());
    for(const auto &h : vec)
        h.print(std::cout) << " ";
    std::cout << std::endl;
    return 0;
}
// Note: the code above doesn't use the swap of HasPtr version! It still uses the
// default version.
