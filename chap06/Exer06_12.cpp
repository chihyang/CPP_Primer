#include <iostream>
using std::cout;
using std::cin;
using std::endl;
// here, reference is better than pointer. It's easy to see.
void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << "Before swap: " << a << " " << b << endl;
    swap(a, b);
    cout << "After swap: " << a << " " << b << endl;
    return 0;
}
