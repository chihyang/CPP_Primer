#include <iostream>
#include "Exer13_28_BinStrTree_value.h"
using std::cout;
using std::endl;
int main()
{
    TreeNode t1("t1");
    TreeNode t2 = t1;
    t1.read(cout) << endl;
    t2.write("t2");
    t2.read(cout) << endl;
    {
        TreeNode t3(t2);
        t3.read(cout) << endl;
        t3.write("t3");
        t3.read(cout) << endl;;
    }
    TreeNode t4("t4");
    TreeNode t5("t5");
    t4.read(cout) << endl;;
    t5.read(cout) << endl;
    t4 = t4;
    BinStrTree r1;
    BinStrTree r2(r1);
    BinStrTree r3;
    r3 = r1;
    r3 = r3;
    return 0;
}
