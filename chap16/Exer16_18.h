template <typename T, typename U, typename V> void f1(T, U, V);
// every template parameter must be preceded by keyword typename or class
template <typename T> T f2(int &T);
// can not reuse the name that are declared as a template parameter name
inline template <typename T> T foo(T, unsigned int*);
// inline should be put between parameter list and return type
template <typename T> f4(T, T);
// no return type
typedef char Ctype();
template <typename Ctype> Ctype f5(Ctype a);
// ok; but Ctype in template is not an alias of char; it'll be instantiated when f5 is used