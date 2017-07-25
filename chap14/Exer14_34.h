#ifndef FINAL_GRADE_H
#define FINAL_GRADE_H
#include <string>
using std::string;
class FinalGrade {
public:
    const string& operator()(bool grade, const string &s1, const string &s2) const {
        return grade ? s1 : s2;
    }
};
#endif
