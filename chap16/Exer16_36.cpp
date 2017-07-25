// Warning: this is for test. It cannot compile.
// The problem lies in line 10.
template <typename T> f1(T, T) {}
int main()
{
    int i = 0, j = 42, *p1 = &i;
    const int *cp1 = &i, *cp2 = &j;
    int *const pc1 = &i;
    f1(cp1, pc1); // illegal: top-level const of pc1 is ignored, but cp1 is deduced as const int*, pc1 is deduced as int*, their types are different
    f1(pc1, p1); // legal: pc1 is deduced as int*, so is p1
    return 0;
}
