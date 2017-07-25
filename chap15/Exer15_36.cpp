#include <iostream>
#include "Exer15_35_Query.h"
using std::cout;
using std::endl;
int main()
{
    Query q = Query("fiery") & Query("bird") | Query("wind");
    cout << "\n" << q << endl;
    return 0;
}
