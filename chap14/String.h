// Inheritance: exercise 13.55.
// Note: see Exer19_18.cpp for the explanation of the problem issued in note.
#ifndef STRING_SIMPLE_H
#define STRING_SIMPLE_H
#include <iostream>
#include <cstddef>
#include <cstring>
#include <utility>
#include <memory>
#include <algorithm>
using std::ostream;
using std::size_t;
using std::pair;
using std::allocator;
class String {
	// overloaded output operator required by exercise 14.7
	friend ostream &operator<<(ostream&, const String&);
	// overloaded equality operator required by exercise 14.16
	friend bool operator==(const String&, const String&);
	friend bool operator!=(const String&, const String&);
	// overloaded relational operator required by exercise 14.18
	friend bool operator<(const String&, const String&);
	friend bool operator<=(const String&, const String&);
	friend bool operator>(const String&, const String&);
	friend bool operator>=(const String&, const String&);
public:
	String();
	String(const char*);
	String(const String&);
	String(String&&) noexcept; // move constructor
	String& operator=(const String&);
	String& operator=(String&&) noexcept; // move assignment
	// subscript operator(const and nonconst version) required by exercise 14.26
	char& operator[](size_t n)
	{ return elements[n]; }
	char& operator[](size_t n) const
	{ return elements[n]; }
	~String();
	void push_back(const char&);
	void push_back(char&&);
	size_t size() const { return first_free - elements;}
	size_t capacity() const { return cap - elements; }
	char* begin() const { return elements; }
	char* end() const { return first_free; }
	bool empty() const { return elements == first_free; }
	void clear();
private:
	void chk_n_alloc() { if(size() == capacity()) reallocate(); }
	pair<char*, char*> alloc_n_copy(const char*, const char*);
	void free();
	void reallocate();
private:
	static allocator<char> alloc;
	static size_t ini_size;
	char *elements;
	char *first_free;
	char *cap;
};
allocator<char> String::alloc;
// It seems both gcc and visual studio library allocates 15 space for a default 
// initialized string.
size_t String::ini_size = 15;
// friend definition
ostream& operator<<(ostream &os, const String &s)
{
	if(s.elements != s.first_free)
	{
		for(auto p = s.begin(); p != s.end(); ++p)
			os << *p;
	}
	return os;
}
bool operator==(const String &lhs, const String &rhs)
{
	if(lhs.size() != rhs.size())
		return false;
	else {
		for(auto p = lhs.begin(), q = rhs.begin(); p != lhs.end(); ++p, ++q)
			if(*p != *q)
				return false;
		return true;
	}
}
bool operator!=(const String &lhs, const String &rhs)
{
	return !(lhs == rhs);
}
bool operator<(const String &lhs, const String &rhs)
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
bool operator<=(const String &lhs, const String &rhs)
{
	return (lhs < rhs || lhs == rhs);
}
bool operator>(const String &lhs, const String &rhs)
{
	return !(lhs < rhs || lhs == rhs);
}
bool operator>=(const String &lhs, const String &rhs)
{
	return !(lhs < rhs);
}
String::String(): elements(nullptr), first_free(nullptr), cap(nullptr)
{
	elements = alloc.allocate(ini_size);
	first_free = elements;
	cap = elements + ini_size;
}
String::String(const char *s)
{
	auto newdata = alloc_n_copy(s, s + strlen(s));
	elements = newdata.first;
	first_free = newdata.second;
	cap = (strlen(s) > ini_size) ? first_free : (elements + ini_size);
}
String::String(const String &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = newdata.second;
	cap = (s.size() > ini_size) ? first_free : (elements + ini_size);
	// call identity required by exercise 13.47
	std::cout << "String(const String&) is called" << std::endl;
}
// copy constructor required by exercise 13.49
String::String(String &&s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	s.elements = s.first_free = s.cap = nullptr;
	std::cout << "String(String&&) is called" << std::endl;
}
String& String::operator=(const String& rhs)
{
	auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = newdata.first;
	first_free = newdata.second;
	cap = (rhs.size() > ini_size) ? first_free : (elements + ini_size);
	// call identity required by exercise 13.47
	std::cout << "String& operator=(const String&) is called" << std::endl;
	return *this;
}
// move assigment required by exercise 13.49
String& String::operator=(String &&rhs) noexcept
{
	if(this != &rhs)
	{
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	std::cout << "String& operator=(String&&) is called" << std::endl;
	return *this;
}
String::~String()
{
	free();
}
void String::push_back(const char &c)
{
	chk_n_alloc();
	alloc.construct(first_free++, c);
}
void String::push_back(char &&c)
{
	chk_n_alloc();
	alloc.construct(first_free++, std::move(c));
}
void String::clear()
{
	for(auto p = first_free; p != elements; /* empty */)
		alloc.destroy(--p);
	first_free = elements;
}
pair<char*, char*> String::alloc_n_copy(const char *b, const char *e)
{
	auto newcapacity = (e - b > ini_size) ? (e - b) : ini_size;
	auto newdata = alloc.allocate(newcapacity);
	return {newdata, std::uninitialized_copy(b, e, newdata)};
}
void String::reallocate()
{
	auto newcapacity = (size() * 2 > ini_size) ? size() * 2 : ini_size;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for(size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}
void String::free()
{
	// std::for_each(elements, first_free, [](const char &c) {alloc.destroy(&c);});
	for(auto p = first_free; p != elements; /* empty */)
		alloc.destroy(--p);
	alloc.deallocate(elements, cap - elements);
}
#endif
// Note #1: don't know why, but uninitialized_copy and for_each don't work if std:: 
// isn't prefixed. This remains to be solved.
// ADDITION: see Exer19_18.cpp for explanation, or see section 18.2.3, page 798 
// for the reason.

// Note #2: here we can see the advantage of allocator compared to new/delete. If
// we use new/delete, we might have to use char array instead of raw and uninitialized
// memory.