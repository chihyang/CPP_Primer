// Warning: This is for verification. It CANNOT be compiled successfully by every compiler.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
    // (a), there should be a { after do and a } before while
    do
        int v1, v2;
        cout << "Please enter two numbers to sum:";
        if(cin >> v1 >> v2)
            cout << "Sum is: " << v1 + v2 << endl;
    while(cin);
    // (b), define ival outside the condition.
    do {
        int ival = 0;
    }while(int ival = 0);
    // (c), define ival outside the body of do while loop.
    do{
        int ival = 2;
    }while(ival);
    return 0;
}
