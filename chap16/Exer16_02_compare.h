#ifndef EXER16_02_COMPARE_H
#define EXER16_02_COMPARE_H
template <typename T>
int compare(const T &v1, const T &v2)
{
    if(v1 < v2) return -1;
    if(v2 < v1) return 1;
    return 0;
}
#endif
