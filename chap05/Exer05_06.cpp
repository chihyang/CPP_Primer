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
            lettergrade = (grade < 60) ? scores[0] : scores[(grade - 50) / 10];
            if(grade >= 60)
            {
                if(grade % 10 > 7)
                    lettergrade += '+';
                else if(grade % 10 < 3)
                    lettergrade += '-';
                else
                    ;
            }
            cout << lettergrade << endl;
        }
        else
        {
            cout << "Invalid number." << endl;
        }
    }
    return 0;
}
