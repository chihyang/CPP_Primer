#include <iostream>
#include <vector>
using std::cin;
using std::vector;
int main()
{
    vector<int> ivec;
    int i;
    while(cin >> i) {
        ivec.push_back(i);
    }
    return 0;
}
