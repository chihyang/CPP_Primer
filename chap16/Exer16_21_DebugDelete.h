#ifndef EXER16_21_DEBUG_DELETE_H
#define EXER16_21_DEBUG_DELETE_H
#include <iostream>
// function-object class that calls delete on a given pointer
class DebugDelete {
public:
    DebugDelete(std::ostream &s = std::cerr) : os(s) {}
    // as with any function template, the type of T is deduced by the compiler
    template <typename T>
    void operator()(T *p) const
    { os << "deleting shared_ptr" << std::endl; delete p; }
private:
    std::ostream &os;
};
#endif
