#ifndef STRBLOB_H
#define STRBLOB_H
#include <string>
#include <vector>
#include <initializer_list>
#include <memory>
#include <stdexcept>
class StrBlobPtr;
class StrBlob {
    friend class StrBlobPtr;
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const { return data->size(); }
    // add and remove elements
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();
    // elements access
    std::string& front();
    std::string& back();
    // const versions of front and back required by exercise 12.2
    const std::string& front() const;
    const std::string& back() const;
    // return reference count
    size_type use_count() const { return data.use_count(); }
    StrBlobPtr begin();
    StrBlobPtr end();
private:
    std::shared_ptr<std::vector<std::string>> data;
    // throws msg if data[i] isn't valid
    void check(size_type i, const std::string &msg) const;
};
// constructor
StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
StrBlob::StrBlob(std::initializer_list<std::string> il) :
    data(std::make_shared<std::vector<std::string>>(il)) {};
void StrBlob::check(size_type i, const std::string &msg) const
{
    if(i >= data->size())
        throw std::out_of_range(msg);
}
// add and remove elements
void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}
// elements access
std::string& StrBlob::front()
{
    check(0, "front on empty StrBlob");
    data->front();
}
std::string& StrBlob::back()
{
    check(0, "back on empty StrBlob");
    data->back();
}
const std::string& StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    data->front();
}
const std::string& StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    data->back();
}
class StrBlobPtr{
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data),curr(sz) {}
    std::string& deref() const;
    StrBlobPtr& incr();
private:
    std::shared_ptr<std::vector<std::string>> check(size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    size_t curr;
};
std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(size_t i, const std::string& msg) const
{
    auto ret = wptr.lock();
    if(!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if(i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}
std::string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}
StrBlobPtr& StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}
// we have to define these member functions here, after the definition of StrBlobPtr
StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}
#endif
