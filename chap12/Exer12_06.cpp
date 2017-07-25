#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
vector<int>* vec_create(const vector<int> &v = {})
{
    vector<int> *vp = new vector<int>(v);
    return vp;
}
vector<int>* vec_read(vector<int> *vp)
{
    int i;
    while(cin >> i)
    {
        vp->push_back(i);
    }
    return vp;
}
void vec_print(vector<int> *vp)
{
    for(const auto &i : *vp)
    {
        cout << i << " ";
    }
    cout << endl;
    delete vp;
}
int main()
{
    auto vp = vec_create();
    vec_read(vp);
    vec_print(vp);
    return 0;
}
