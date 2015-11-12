#ifndef EXER13_26_H
#define EXER13_26_H
#include <string>
#include <vector>
#include <initializer_list>
#include <memory>
#include <stdexcept>
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
public:
	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(initializer_list<string> il);
	// because until now the whole class is not defined, we cannot use initializer list here 
	StrBlob(const StrBlob &rhs) : data(make_shared<vector<string>>(*rhs.data)) {}
	StrBlob& operator=(const StrBlob&);
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
// copy-assignment operator
StrBlob& StrBlob::operator=(const StrBlob &rhs)
{
	auto newp = make_shared<vector<string>>(*rhs.data); // allocate new memory
	data = newp; // reset date to point to new allocated object, original 
	// object will be destroyed automatically if necessary
	return *this;
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
// ******************************
// nonconst version of StrBlobPtr
// ******************************
class StrBlobPtr{
public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0) : curr(sz) {}
	string& deref() const;
	StrBlobPtr& incr();
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

// ***************************
// const version of StrBlobPtr
// ***************************
class ConstStrBlobPtr{
public:
	ConstStrBlobPtr() : curr(0) {}
	ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data),curr(sz) {}
	string& deref() const;
	ConstStrBlobPtr& incr();
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