#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
int main()
{
    int grade;
    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    string lettergrade;
    while(cin >> grade)
    {
        if(grade <= 100 && grade >= 0)
        {
            if(grade < 60)
            {
                lettergrade = scores[0];
            }
            else
            {
                lettergrade = scores[(grade - 50) / 10];
                if(grade != 100)
                {
                    if(grade % 10 > 7)
                        lettergrade += '+';
                    else if(grade % 10 < 3)
                        lettergrade += '-';
                    else
                        ;
                }
            }
            cout << lettergrade << endl;
        }
    }
    return 0;
}
