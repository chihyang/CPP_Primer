#include<iostream>
int main()
{
    const int i =42;
    auto j = i; // int
    const auto &k = i; // const reference(or say, reference to const)
    auto *p = &i; // pointer to const, const of i is not ignored, so it's const int *
    const auto j2 = i, &k2 = i; // j2, const int; i, const reference
    std::cout << j << " " << k << " " << *p << " " << j2 << " " << k2 << " " << std::endl;
    return 0;
}
