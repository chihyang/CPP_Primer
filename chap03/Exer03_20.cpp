// Tips: some situations must be considered carefully.
// For example: What if vector is null? What if vector has only one element?
#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
int main()
{
    vector<int> v;
    int i, j = 0;
    while(cin >> i)
    {
        v.push_back(i);
    }
    if(v.size() > 0)
    {
        if(v.size() > 1)
        {
            while(j < v.size() - 1)
            {
                cout << v[j] + v[j + 1] << " ";
                ++j;
            }
            cout << endl;
            j = 0;
            while(j <= v.size() - 1 - j)
            {
                if(j < v.size() -1 - j)
                    cout << v[j] + v[v.size() - 1 - j] << " ";
                else
                    cout << v[j];
                ++j;
            }
            cout << endl;
        }
        else
        {
            cout << v[j] << endl;
            cout << v[j] << endl;
        }
    }
    else
        cout << "No elements!" << endl;
    return 0;
}
