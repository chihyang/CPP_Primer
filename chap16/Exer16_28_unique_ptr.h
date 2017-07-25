#ifndef EXER16_28_UP_H
#define EXER16_28_UP_H
#include <cstddef>
#include <utility>
#include <functional>
#include <stdexcept>
class DefaultDeleter {
public:
    // as with any function template, the type of T is deduced by the compiler
    template <typename T>
    void operator()(T *p) const
    { delete p; }
};
// delete dynamic array
class DefaultDeleterArray {
public:
    // as with any function template, the type of T is deduced by the compiler
    template <typename T>
    void operator()(T *p) const
    { delete []p; }
};
template <typename T, typename D = DefaultDeleter> class unique_ptr;
template <typename T>
void swap(unique_ptr<T>&, unique_ptr<T>&);
template <typename T, typename D>
class unique_ptr {
    friend void swap<T>(unique_ptr<T>&, unique_ptr<T>&);
public:
    // constructor
    unique_ptr() : p(nullptr), del(D()) {}
    // forbid implicit conversion
    template <typename U>
    explicit unique_ptr(U *t) : p(t), del(D()) {}
    unique_ptr(const D &d) : p(nullptr), del(d) {}
    // copy-control operations(copy version is deleted)
    unique_ptr(const unique_ptr&) = delete;
    unique_ptr(unique_ptr &&up) noexcept : p(std::move(up.p)), del(std::move(up.del)) {}
    unique_ptr& operator=(const unique_ptr&) = delete;
    unique_ptr& operator=(unique_ptr&&) noexcept;
    // generic copy control members, see effective C++, 3rd edition, item 45
    template <typename U, typename DU>
    unique_ptr(unique_ptr<U, DU> &&up) noexcept : p(std::move(up.p)), del(std::move(up.del)) {}
    template <typename U, typename DU>
    unique_ptr& operator=(unique_ptr<U, DU> &&up) noexcept;
    // std::nullptr_t is not covered in textbook, see http://en.cppreference.com/w/cpp/types/nullptr_t
    unique_ptr& operator=(std::nullptr_t);
    ~unique_ptr();
    // overloaded operators
    T& operator*() const;
    T* operator->() const;
    explicit operator bool() const { return p; }
    // other operations
    T* get() const { return p; }
    void swap(unique_ptr&);
    T* release();
    void reset();
    void reset(T*);
    void reset(std::nullptr_t);
private:
    void free() const;
    T *p;
    D del;
};
template <typename T, typename D>
inline void unique_ptr<T, D>::free() const
{
    if(p) {
        del(p);
    }
}
// move assignment
template <typename T, typename D>
unique_ptr<T, D>& unique_ptr<T, D>::operator=(unique_ptr &&rhs) noexcept
{
    p = rhs.p;
    del = rhs.del;
    rhs.p = nullptr;
    return *this;
}
template <typename T, typename D>
template <typename U, typename DU>
unique_ptr<T, D>& unique_ptr<T, D>::operator=(unique_ptr<U, DU> &&rhs) noexcept
{
    p = rhs.p;
    del = rhs.del;
    rhs.p = nullptr;
    return *this;
}
template <typename T, typename D>
unique_ptr<T, D>& unique_ptr<T, D>::operator=(std::nullptr_t)
{
    free();
    p = nullptr;
    return *this;
}
template <typename T, typename D>
unique_ptr<T, D>::~unique_ptr()
{
    free();
    p = nullptr;
}
// overloaded operators
template <typename T, typename D>
inline T& unique_ptr<T, D>::operator*() const
{
    if(!p)
        throw std::runtime_error("dereference null pointer");
    return *p;
}
template <typename T, typename D>
inline T* unique_ptr<T, D>::operator->() const
{
    return &this->operator*();
}
// other operations
template <typename T>
void swap(unique_ptr<T> &lhs, unique_ptr<T> &rhs)
{
    lhs.swap(rhs);
}
// non-member version calls member version, if we use member version call
// non-member version, we have to use ::swap for a hidden name
template <typename T, typename D>
inline void unique_ptr<T, D>::swap(unique_ptr &rhs)
{
    using std::swap;
    swap(this->p, rhs.p);
    swap(this->del, rhs.del);
}
template <typename T, typename D>
T* unique_ptr<T, D>::release()
{
    auto ret = p;
    p = nullptr;
    return ret;
}
template <typename T, typename D>
void unique_ptr<T, D>::reset()
{
    free();
    p = nullptr;
}
template <typename T, typename D>
void unique_ptr<T, D>::reset(T *t)
{
    free();
    p = t;
}
template <typename T, typename D>
void unique_ptr<T, D>::reset(std::nullptr_t)
{
    free();
    p = nullptr;
}
// dynamic array version
template <typename T, typename D> class unique_ptr<T[], D>;
template <typename T>
void swap(unique_ptr<T[]>&, unique_ptr<T[]>&);
template <typename T, typename D = DefaultDeleterArray>
class unique_ptr<T[], D> {
    friend void swap<T>(unique_ptr<T>&, unique_ptr<T>&);
public:
    // constructor
    unique_ptr() : p(nullptr), del(D()) {}
    // forbid implicit conversion
    explicit unique_ptr(T *t) : p(t), del(D()) {}
    unique_ptr(const D &d) : p(nullptr), del(d) {}
    // copy-control operations(copy version is deleted)
    unique_ptr(const unique_ptr&) = delete;
    unique_ptr(unique_ptr &&up) noexcept : p(std::move(up.p)), del(std::move(del)) {}
    unique_ptr& operator=(const unique_ptr&) = delete;
    unique_ptr& operator=(unique_ptr&&) noexcept;
    // std::nullptr_t is not covered in textbook, see http://en.cppreference.com/w/cpp/types/nullptr_t
    unique_ptr& operator=(std::nullptr_t);
    ~unique_ptr();
    // overloaded operators
    T& operator[](std::size_t n) const { return p[n]; }
    explicit operator bool() const { return p; }
    // other operations
    T* get() const { return p; }
    void swap(unique_ptr&);
    void release();
    void reset();
    void reset(T*);
    void reset(std::nullptr_t);
private:
    void free() const;
    T *p;
    D del;
};
template <typename T, typename D>
inline void unique_ptr<T[], D>::free() const
{
    if(p) {
        del(p);
    }
}
// constructor
template <typename T, typename D>
unique_ptr<T[], D>& unique_ptr<T[], D>::operator=(unique_ptr &&rhs) noexcept
{
    p = rhs.p;
    del = rhs.del;
    rhs.p = nullptr;
}
template <typename T, typename D>
unique_ptr<T[], D>& unique_ptr<T[], D>::operator=(std::nullptr_t)
{
    free();
    p = nullptr;
    return *this;
}
template <typename T, typename D>
unique_ptr<T[], D>::~unique_ptr()
{
    free();
}
// other operations
template <typename T>
void swap(unique_ptr<T[]> &lhs, unique_ptr<T> &rhs)
{
    lhs.swap(rhs);
}
// non-member version calls member version, if we use member version call
// non-member version, we have to use ::swap for a hidden name
template <typename T, typename D>
inline void unique_ptr<T[], D>::swap(unique_ptr &rhs)
{
    using std::swap;
    swap(this->p, rhs.p);
    swap(this->del, rhs.del);
}
template <typename T, typename D>
void unique_ptr<T[], D>::release()
{
    free();
    p = nullptr;
}
template <typename T, typename D>
void unique_ptr<T[], D>::reset()
{
    free();
    p = nullptr;
}
template <typename T, typename D>
void unique_ptr<T[], D>::reset(T *t)
{
    free();
    p = t;
}
template <typename T, typename D>
void unique_ptr<T[], D>::reset(std::nullptr_t)
{
    free();
    p = nullptr;
}
#endif
// Note: because release and reset might change the value of one object, they can't
// be applied to const unique_ptr. Because all of this functions call a private
// function free() to free resource, we can not write p = nullptr in free.
