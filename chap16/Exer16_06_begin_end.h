#ifndef EXER16_06_H
#define EXER16_06_H
template <typename T, unsigned N>
inline T* begin(T (&arr)[N]) // the parameter cannot be const, or we cannot make T* bound to arr
{
    return arr;
}
template <typename T, unsigned N>
inline T* end(T (&arr)[N]) // the parameter cannot be const, or we cannot make T* bound to arr
{
    return arr + N;
}
#endif
