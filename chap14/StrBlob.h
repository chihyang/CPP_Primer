#ifndef STRBLOB_H
#define STRBLOB_H
#include <cstddef>
#include <string>
#include <vector>
#include <initializer_list>
#include <memory>
#include <stdexcept>
using std::size_t;
using std::string;
using std::vector;
using std::initializer_list;
using std::shared_ptr;
using std::make_shared;
using std::weak_ptr;
using std::runtime_error;
using std::out_of_range;
class StrBlobPtr;
class ConstStrBlobPtr;
class StrBlob {
	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;
	// overloaded equality operators required by exercise 14.16
	friend bool operator==(const StrBlob&, const StrBlob&);
	friend bool operator!=(const StrBlob&, const StrBlob&);
	// overloaded relational operator required by exercise 14.18
	friend bool operator<(const StrBlob&, const StrBlob&);
	friend bool operator<=(const StrBlob&, const StrBlob&);
	friend bool operator<(const StrBlob&, const StrBlob&);
	friend bool operator>=(const StrBlob&, const StrBlob&);
public:
	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(initializer_list<string> il);
	size_type size() const { return data->size(); }
	// add and remove elements
	void push_back(const string &t) { data->push_back(t); }
	void pop_back();
	// elements access
	string& front();
	string& back();
	// const versions of front and back required by exercise 12.2
	const string& front() const;
	const string& back() const;
	// return reference count
	const size_type use_count() const { return data.use_count(); }
	StrBlobPtr begin();
	StrBlobPtr end();
	ConstStrBlobPtr begin() const;
	ConstStrBlobPtr end() const;
	// access elements
	string& at(size_type) const;
	// subscript operator required by exercise 14.26
	// the difference between at and subscript is that subscript doesn't throw
	// exception if the index is out of range.
	string& operator[](size_t n)
	{ return (*data)[n]; }
	string& operator[](size_t n) const
	{ return (*data)[n]; }
private:
	shared_ptr<vector<string>> data;
	// throws msg if data[i] isn't valid
	void check(size_type i, const string &msg) const;
};
// constructor
StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il) : 
    data(make_shared<vector<string>>(il)) {};
void StrBlob::check(size_type i, const string &msg) const
{
	if(i >= data->size())
		throw out_of_range(msg);
}
// add and remove elements
void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}
// elements access
string& StrBlob::front()
{
	check(0, "front on empty StrBlob");
	data->front();
}
string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	data->back();
}
const string& StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	data->front();
}
const string& StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	data->back();
}
string& StrBlob::at(size_type n) const
{
	check(n, "index out of range");
	return data->at(n);
}
// friend definition
bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
	return *lhs.data == *rhs.data;
}
bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
	return !(lhs == rhs);
}
bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
	return *lhs.data < *rhs.data;
}
bool operator<=(const StrBlob &lhs, const StrBlob &rhs)
{
	return (lhs < rhs || lhs == rhs);
}
bool operator>(const StrBlob &lhs, const StrBlob &rhs)
{
	return !(lhs < rhs || lhs == rhs);
}
bool operator>=(const StrBlob &lhs, const StrBlob &rhs)
{
	return !(lhs < rhs);
}
// ******************************
// nonconst version of StrBlobPtr
// ******************************
class StrBlobPtr{
	// overloaded equality operators required by exercise 14.16
	friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
	// overloaded relational operators required by exercise 14.18
	friend bool operator<(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator>(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator>=(const StrBlobPtr&, const StrBlobPtr&);
public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
	string& deref() const;
	StrBlobPtr& incr();
	// subscript operator required by exercise 14.26
	string& operator[](size_t n);
	string& operator[](size_t n) const;
private:
	shared_ptr<vector<string>> check(size_t, const string&) const;
	weak_ptr<vector<string>> wptr;
	size_t curr;
};
shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string& msg) const
{
	auto ret = wptr.lock();
	if(!ret)
		throw runtime_error("unbound StrBlobPtr");
	if(i >= ret->size())
		throw out_of_range(msg);
	return ret;
}
string& StrBlobPtr::deref() const
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
// It should be curr + n, because this points to the position of index curr,
// if we dereference an element by index, we should get the element at the
// position of curr + n.
string& StrBlobPtr::operator[](size_t n)
{
	auto p = check(curr + n, "deference past end");
	return (*p)[curr + n];
}
string& StrBlobPtr::operator[](size_t n) const
{
	auto p = check(curr + n, "deference past end");
	return (*p)[curr + n];
}
// definitions of friend operators
// shared_ptr has its overloaded version of equality and relational operators, but weak_ptr doesn't
// so we have to use lock() to compare
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr == rhs.curr;
}
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !(lhs == rhs);
}
bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.curr < rhs.curr;
}
bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.curr <= rhs.curr;
}
bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.curr > rhs.curr;
}
bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.curr >= rhs.curr;
}
// ***************************
// const version of StrBlobPtr
// ***************************
class ConstStrBlobPtr{
	// overloaded equality operators required by exercise 14.16
	friend bool operator==(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
	friend bool operator!=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
	// overloaded relational operators required by exercise 14.18
	friend bool operator<(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
	friend bool operator<=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
	friend bool operator>(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
	friend bool operator>=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
public:
	ConstStrBlobPtr() : curr(0) {}
	ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data),curr(sz) {}
	string& deref() const;
	ConstStrBlobPtr& incr();
	// subscript operator required by exercise 14.26
	// ConstStrBlobPtr should only have const version of subscript operator
	string& operator[](size_t n) const;
private:
	shared_ptr<vector<string>> check(size_t, const string&) const;
	weak_ptr<vector<string>> wptr;
	size_t curr;
};
shared_ptr<vector<string>> ConstStrBlobPtr::check(size_t i, const string& msg) const
{
	auto ret = wptr.lock();
	if(!ret)
		throw runtime_error("unbound StrBlobPtr");
	if(i >= ret->size())
		throw out_of_range(msg);
	return ret;
}
string& ConstStrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}
ConstStrBlobPtr& ConstStrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}
string& ConstStrBlobPtr::operator[](size_t n) const
{
	auto p = check(curr + n, "deference past end");
	return (*p)[curr + n];
}
// definitions of friend operators
bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr == rhs.curr;
}
bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return !(lhs == rhs);
}
bool operator<(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return lhs.curr < rhs.curr;
}
bool operator<=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return lhs.curr <= rhs.curr;
}
bool operator>(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return lhs.curr > rhs.curr;
}
bool operator>=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return lhs.curr >= rhs.curr;
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
ConstStrBlobPtr StrBlob::begin() const
{
	return ConstStrBlobPtr(*this);
}
ConstStrBlobPtr StrBlob::end() const
{
	auto ret = ConstStrBlobPtr(*this, data->size());
	return ret;
}
#endif
// Note: If two pointers point to two unrelated objects, the result of comparison
// is undefined (See page 120). Here we assume that lhs and rhs point to the same
// object. Thus StrBlobPtr has consistent behaviour with built-in pointer. On the
// other hand, we can compare two pointers with == regardless whether they point
// to the same object. Thus it seems that equality and relational operators are
// not consistent with each other.