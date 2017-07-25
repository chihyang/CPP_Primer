// Note: this file uses ./data/quiz and ./data/answer
#include <cstddef>
#include <cctype>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Exer17_11_quiz.h"
using std::size_t;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;
using std::bitset;
int main(int argc, char* argv[])
{
    if(argc != 3)
        return -1;
    ifstream is_quiz(argv[1]), is_ans(argv[2]);
    string str;
    vector<string> question; // questions
    // read questions into a vector
    while(getline(is_quiz, str))
        question.push_back(str);
    // read correct answers into a string
    is_ans >> str;
    Quiz<10> answer(str);
    Quiz<10> test;
    cout << "for every question, input y or n:\n";
    size_t i = 0;
    // run test
    for(auto p : question)
    {
        cout << p << endl;
        char c;
        cin >> c;
        bool ans = (tolower(c) == 'y');
        test.updataQuiz(i, ans);
    }
    cout << "grades: " << grades(answer, test) << endl;
    return 0;
}
