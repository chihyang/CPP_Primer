#ifndef EXER16_41_SUM_H
#define EXER16_41_SUM_H
// using trailing return type, the return type is guaranteed to hold the result of sum
template <typename T1, typename T2>
auto sum(T1 lhs, T2 rhs) -> decltype(lhs + rhs)
{
    return lhs + rhs;
}
#endif
