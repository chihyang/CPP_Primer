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
    
    const vector<string> scores = {"F" ,"E", "D", "C" , "B" , "A", "A++"};
    int grade;
    
    string lettergrade;

    while(cin >> grade)
    {


        lettergrade = (grade <= 100 && grade >= 0)?  
                        ((grade > 50)? scores[(grade - 40)/ 10] + 
                        ((grade% 10 < 3 && grade != 100) ? lettergrade += '-' : 
                        ((grade%10 > 7)? lettergrade += '+' : lettergrade += " ") )
                        : scores[0]) :
                        "Enter valid input";


        cout << lettergrade << endl;
        lettergrade = "";
    }
    return 0;
}
