// StrVec from chapter 14.
#ifndef EXER19_02_STRVEC_H
#define EXER19_02_STRVEC_H
#include <cstddef>
#include <cstdlib>
#include <string>
#include <utility>
#include <memory>
#include <initializer_list>
#include "Exer19_01_new_delete.h"
using std::size_t;
using std::string;
using std::pair;
using std::allocator;
using std::initializer_list;
class StrVec {
	// equality operator required by exercise 14.16
	friend bool operator==(const StrVec&, const StrVec&);
	friend bool operator!=(const StrVec&, const StrVec&);
	// relation operator required by exercise 14.18
	friend bool operator<(const StrVec&, const StrVec&);
	friend bool operator<=(const StrVec&, const StrVec&);
	friend bool operator>(const StrVec&, const StrVec&);
	friend bool operator>=(const StrVec&, const StrVec&);
public:
	StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec&);
	// move constructor from page 536
	StrVec(StrVec&&) noexcept;
	StrVec& operator=(const StrVec&);
	// move assignment from page 537
	StrVec& operator=(StrVec&&) noexcept;
	// assignment with an initializer_list parameter from page 563
	StrVec& operator=(initializer_list<string>);
	// constructor that takes a initializer_list as parameter, required by exercise 13.40
	StrVec(const initializer_list<string>&);
	// subscript operator from page 565
	// class is not responsible for checking if the subscript is out of range
	string& operator[](size_t n) // nonconst version of subscript operator
	{ return elements[n]; }
	string& operator[](size_t n) const // const version of subscript operator
	{ return elements[n]; }
	~StrVec();
	void push_back(const string&);
	void push_back(string&&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	string *begin() const { return elements; }
	string *end() const { return first_free; } // both begin() and end() are const
	// reserve and resize required by exercise 13.39
	void reserve(size_t);
	void resize(size_t);
	void resize(size_t, const string&);
private:
	static allocator<string> alloc;
	void chk_n_alloc() { if(size() == capacity()) reallocate(); }
	pair<string*, string*> alloc_n_copy(const string*, const string*);
	void free();
	void reallocate();
	void add_rem(size_t n, const string &s = "");
	string *elements;
	string *first_free;
	string *cap;
};
// Warning: define static member outside the class. Without this the program
// using the class wouldn't compile
allocator<string> StrVec::alloc;
// friend definition
bool operator==(const StrVec &lhs, const StrVec &rhs)
{
	if(lhs.size() != rhs.size())
		return false;
	else {
		for(auto p = lhs.elements, q = rhs.elements; p != lhs.first_free; ++p, ++q)
		{	
			if(*p != *q)
				return false;
		}
		return true;
	}
}
bool operator!=(const StrVec &lhs, const StrVec &rhs)
{
	return !(lhs == rhs);
}
bool operator<(const StrVec &lhs, const StrVec &rhs)
{
	auto shorter = lhs.size() < rhs.size() ? lhs.size() : rhs.size();
	auto p = lhs.begin(), q = rhs.begin();
	for(size_t i = 0; p + i != lhs.end(); ++i)
	{
		if(*(p + i) == *(q + i))
			continue;
		else if(*(p + i) < *(q + i))
			return true;
		else
			return false;
	}
	return lhs.size() < rhs.size();
}
bool operator<=(const StrVec &lhs, const StrVec &rhs)
{
	return lhs < rhs || lhs == rhs;
}
bool operator>(const StrVec &lhs, const StrVec &rhs)
{
	return !(lhs < rhs || lhs == rhs);
}
bool operator>=(const StrVec &lhs, const StrVec &rhs)
{
	return !(lhs < rhs);
}
void StrVec::push_back(const string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}
void StrVec::push_back(string &&s)
{
	chk_n_alloc();
	alloc.construct(first_free++, std::move(s));
}
pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
	auto data = alloc.allocate(e - b);
	return {data, uninitialized_copy(b, e, data)};
}
void StrVec::free()
{
	if (elements) {
		for(auto p = first_free; p != elements; /*empty*/ )
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}
StrVec::StrVec(const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap =  newdata.second;
}
StrVec::StrVec(StrVec &&s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	s.elements = s.first_free = s.cap = nullptr;
}
StrVec::StrVec(const initializer_list<string> &il)
{
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
StrVec::~StrVec()
{
	free();
}
StrVec& StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}
StrVec& StrVec::operator=(StrVec &&rhs) noexcept
{
	if(this != &rhs)
	{
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}
StrVec& StrVec::operator=(initializer_list<string> il)
{
	auto data = alloc_n_copy(il.begin(), il.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}
void StrVec::reallocate()
{
	// we'll allocate space for twice as many as the current size
	auto newcapacity = size() ? 2 * size() : 1; // if empty, allocate 1 space, otherwise double
	// allocate new memory
	auto newdata = alloc.allocate(newcapacity);
	// move the data from the old memory to the new
	auto dest = newdata; // points to the next free position in the new memory
	auto elem = elements; // points to the next element in the old memory
	for(size_t i = 0; i != size(); ++i)
		alloc.construct(dest++,  std::move(*elem++));
	free(); // free the old space once we've moved the elements
	// update our data structure to point to the new elements
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}
void StrVec::reserve(size_t n)
{
	if(n > capacity())
	{
		auto newdata = alloc.allocate(n);
		auto dest = newdata;
		auto elem = elements;
		for(size_t i = 0; i != size(); ++i)
			alloc.construct(dest++, std::move(*elem++));
		free();
		elements = newdata;
		first_free = newdata;
		cap = elements + n;
	}
}
void StrVec::resize(size_t n)
{
	add_rem(n);
}
void StrVec::resize(size_t n, const string &s)
{
	add_rem(n, s);
}
void StrVec::add_rem(size_t n, const string &s)
{
	if(n <= size()) {
		auto p = first_free;
		while(p != elements + n)
			alloc.destroy(--p);
		first_free = p;
	}
	else{
		auto new_elem_count = n - size();
		for(size_t i = 0; i != new_elem_count; ++i)
			push_back(s);
	}
}
#endif