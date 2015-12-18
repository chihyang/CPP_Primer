#ifndef EXER13_55_H
#define EXER13_55_H
#include <string>
#include <vector>
#include <initializer_list>
#include <memory>
#include <utility>
#include <stdexcept>
class StrBlobPtr;
class ConstStrBlobPtr;
class StrBlob {
friend class StrBlobPtr;
friend class ConstStrBlobPtr;
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	// because until now the whole class is not defined, we cannot use initializer list here 
	StrBlob(const StrBlob &rhs) : data(std::make_shared<std::vector<std::string>>(*rhs.data)) {}
	StrBlob& operator=(const StrBlob&);
	size_type size() const { return data->size(); }
	// add and remove elements
	void push_back(const std::string &t) { data->push_back(t); }
	// move version required by exercise 13.55
	void push_back(std::string &&t) { data->push_back(std::move(t)); }
	void pop_back();
	// elements access
	std::string& front();
	std::string& back();
	// const versions of front and back required by exercise 12.2
	const std::string& front() const;
	const std::string& back() const;
	// return reference count
	const size_type use_count() const { return data->use_count(); }
	StrBlobPtr begin();
	StrBlobPtr end();
	ConstStrBlobPtr begin() const;
	ConstStrBlobPtr end() const;
	// access elements
	std::string& at(size_type) const;
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
// copy-assignment operator
StrBlob& StrBlob::operator=(const StrBlob &rhs)
{
	// we can use make_shared directly to make data point to new object
	data = std::make_shared<std::vector<std::string>>(*rhs.data);
	return *this;
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
std::string& StrBlob::at(size_type n) const
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

// ***************************
// const version of StrBlobPtr
// ***************************
class ConstStrBlobPtr{
public:
	ConstStrBlobPtr() : curr(0) {}
	ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data),curr(sz) {}
	std::string& deref() const;
	ConstStrBlobPtr& incr();
private:
	std::shared_ptr<std::vector<std::string>> check(size_t, const std::string&) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	size_t curr;
};
std::shared_ptr<std::vector<std::string>> ConstStrBlobPtr::check(size_t i, const std::string& msg) const
{
	auto ret = wptr.lock();
	if(!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if(i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}
std::string& ConstStrBlobPtr::deref() const
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