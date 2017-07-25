#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
int main()
{
    vector<unsigned> scores(11, 0);
    unsigned grade;
    while(cin >> grade)
    {
        if(grade <= 100)
            ++(*(scores.begin() + grade / 10));
    }
    for(auto i : scores)
        cout << i << " ";
    cout << endl;
    return 0;
}
