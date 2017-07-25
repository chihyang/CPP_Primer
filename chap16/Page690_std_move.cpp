// Warning: this is for illustration. Don't use move like this.
#include <iostream>
#include <string>
#include <type_traits>
using std::cout;
using std::endl;
using std::string;
// template <typename T>
// typename std::remove_reference<T>::type&& move(const T& t)
// {
    // // ok to use const T& as function parameter, but need to remove const at first
    // return static_cast<typename std::remove_reference<T>::type&&>(const_cast<T&>(t));
// }
template <typename T>
typename std::remove_reference<T>::type&& move(T&& t)
{
    return static_cast<typename std::remove_reference<T>::type&&>(t);
}
int main()
{
    int i = 0, &ir = i;
    const int &ci = i;
    cout << ::move(i) << endl;
    string s1("hi!"), s2, s3;
    cout << "s1 before move: " << s1 << endl;
    // here we use ::move to avoid possible name collision with std::move
    s2 = ::move(string("hi")); // #1 - T: string, t: string&&, return: string&&
    s3 = ::move(s1);           // #2 - T: string&, t: string&, return: string&&
    cout << "s1 after move: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;
    const string s4("world"), &sr = s4;
    string s5;
    s5 = ::move(sr);           // #3 - T: const string&, t: const string&, return: const string&&
    cout << "s4: " << s4 << endl;
    cout << "sr(reference to s4 after move): " << sr << endl;
    cout << "s5: " << s5 << endl;
    s5 = "beautiful";
    cout << "s4: " << s4 << endl;
    cout << "s5: " << s5 << endl;
    return 0;
}
// Note #1: explanation on #3
// #1 and #2 comes from page 690, now let's see #3:
// sr is a const reference to s4, thus sr is an lvalue. When we pass sr to ::move,
// T is deduced as const string& &, the reference to the lvalue type, which collapses
// to const string&, so the type of parameter of move is const string& &&, which
// collapses to const string&. Because T is const string&, remove_reference<T> is
// const string, and the member type of remove_reference<const string&> is
// const string, thus the return type is const string&&.

// Note #2: moving const arguments is ok.
// As what we can see, move can take arguments of essentially any type(page 690),
// whether the arguments are const or nonconst.
// When the argument is nonconst, the return type of move is:
// (1). rvalue reference to the argument type(i.e. argument is not a reference)
// (2). rvalue reference to referred-to type of the argument(i.e. argument is a reference)
// When the argument is const, the return type of move is:
// (1). const rvalue reference to the argument type(i.e. argument has top-level const)
// (2). const rvalue reference to referred-to type of the argument(i.e. argument has low-level const)
// the key is that move might do NOTHING but change the type of its parameter. So
// move also applies for const.

// Note #3: why the parameter of move must be T&&?
// There are some kinds of parameters that move could choose:
// (1). T; (2). const T; (3). T&; (4). const T&; (5). T&&; (6). const T&&.
// let's check them one by one.
// (1). for move(T t), the value of arguments are copied(page 679), if the type
//      of arguments doesn't allow copy, we can not pass such arguments to move,
//      so move(T t) is not viable.
// (2). for move(const T t), top const doesn't matter, still we cannot pass arguments
//      whose type doesn't allow copy, so move(const T t) is not viable;
// (3). for move(T& t), we cannot pass rvalue(page 687);
// (4). for move(const T& t), we can pass any kind of argument(page 687); but t
//      is const, when we use static_cast and remove_reference<T>, the const of
//      t is discarded,this conversion(discarding low-level const) is not allowed.
//      if we want to convert t to an rvalue, we have to use const_cast<T&> to
//      cast it to a nonconst value first:
// return static_cast<typename std::remove_reference<T>::type&&>(const_cast<T&>(t));
//      this is ok but changes the const property of the argument, which is surplus.
//      After all, we just want to get an rvalue rather than change the const
//      argument of the parameter;
// (5). for move(T&& t), this is explained in detail on primer; it's ok to use
//      rvalue reference this way;
// (6). for move(const T&& t), the problem is the same as (4); we have to cast
//      t to a nonconst at first, which is not intended.
//
// Below is the summary of contents above taking string as an example,
// for passing pointer, see Page697_passing_pointer.cpp
// column is function parameter, row is argument passing to ::move
// (TABLE1-1 and TABLE1-2 Assume all of the arguments passed to ::move are lvalues,
// or T& is not available.)
//
// TABLE1-1: template argument from deduction
// --------------------------------------------------------------------------------------
// |          |string  |const string  |string& |const string& |string&& |const string&& |
// |----------|--------|--------------|--------|--------------|---------|---------------|
// |T         |string  |string        |string  |string        |string   |string         |
// |----------|--------|--------------|--------|--------------|---------|---------------|
// |const T   |string  |string        |string  |string        |string   |string         |
// |----------|--------|--------------|--------|--------------|---------|---------------|
// |T&        |string  |const string  |string  |const string  |string   |const string   |
// |----------|--------|--------------|--------|--------------|---------|---------------|
// |const T&  |string  |string        |string  |string        |string   |string         |
// |----------|--------|--------------|--------|--------------|---------|---------------|
// |T&&       |string& |const string& |string& |const string& |string&  |const string&  |
// |----------|--------|--------------|--------|--------------|---------|---------------|
// |const T&& |string& |string&       |string& |string&       |string&  |string&        |
// --------------------------------------------------------------------------------------
// (Keep in mind that rvalue reference is lvalue itself(page 533).)
// TABLE1-2: instantiated function parameter type
// ------------------------------------------------------------------------------------------------------
// |          |string        |const string  |string&       |const string& |string&&      |const string&&|
// |----------|--------------|--------------|--------------|--------------|--------------|--------------|
// |T         |string        |string        |string        |string        |string        |string        |
// |----------|--------------|--------------|--------------|--------------|--------------|--------------|
// |const T   |const string  |const string  |const string  |const string  |const string  |const string  |
// |----------|--------------|--------------|--------------|--------------|--------------|--------------|
// |T&        |string&       |const string& |string        |const string& |string&       |const string& |
// |----------|--------------|--------------|--------------|--------------|--------------|--------------|
// |const T&  |const string& |const string& |const string& |const string& |const string& |const string& |
// |----------|--------------|--------------|--------------|--------------|--------------|--------------|
// |T&&       |string&       |const string& |string&       |const string& |string&       |const string& |
// |----------|--------------|--------------|--------------|--------------|--------------|--------------|
// |const T&& |const string& |const string& |const string& |const string& |const string& |const string& |
// ------------------------------------------------------------------------------------------------------
//
// (TABLE2-1 and TABLE2-2 Assume all of the arguments passed to ::move are rvalues)
// TABLE2-1: template argument from deduction
// ---------------------------
// |          |string rvalue |
// |----------|--------------|
// |T         |string        |
// |----------|--------------|
// |const T   |string        |
// |----------|--------------|
// |T&        |-             |
// |----------|--------------|
// |const T&  |string        |
// |----------|--------------|
// |T&&       |string        |
// |----------|--------------|
// |const T&& |string        |
// ---------------------------
// TABLE2-2: instantiated function parameter type
// ---------------------------
// |          |string rvalue |
// |----------|--------------|
// |T         |string        |
// |----------|--------------|
// |const T   |string        |
// |----------|--------------|
// |T&        |-             |
// |----------|--------------|
// |const T&  |const string& |
// |----------|--------------|
// |T&&       |string&&      |
// |----------|--------------|
// |const T&& |const string&&|
// ---------------------------

// Note #4: move constructor or assignment rather than move makes an object invalid
// as we can see, move itself doesn't change the function arguments, but move
// constructor and assignment do. In the example above, moved objects might not
// be destroyed immediately after they are moved, but it's quite possible that
// these objects hold invalid values(such as the StrVec: move constructor makes
// the moved object point to nullptr). As a result, we shouldn't use moved
// objects. Rvalue is designed for ephemeral use, we should use it this way.
