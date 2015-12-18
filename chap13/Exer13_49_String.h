#ifndef STRING_SIMPLE_H
#define STRING_SIMPLE_H
#include <iostream>
#include <cstddef>
#include <cstring>
#include <utility>
#include <memory>
#include <algorithm>
class String {
public:
	String();
	String(const char*);
	String(const String&);
	String(String&&) noexcept; // move constructor
	String& operator=(const String&);
	String& operator=(String&&) noexcept; // move assignment
	~String();
	void push_back(const char&);
	std::size_t size() const { return first_free - elements;}
	std::size_t capacity() const { return cap - elements; }
	char* begin() const { return elements; }
	char* end() const { return first_free; }
	bool empty() const { return elements == first_free; }
	void clear();
private:
	void chk_n_alloc() { if(size() == capacity()) reallocate(); }
	std::pair<char*, char*> alloc_n_copy(const char*, const char*);
	void free();
	void reallocate();
private:
	static std::allocator<char> alloc;
	static std::size_t ini_size;
	char *elements;
	char *first_free;
	char *cap;
};
std::allocator<char> String::alloc;
// It seems both gcc and visual studio library allocates 15 space for a default 
// initialized string.
std::size_t String::ini_size = 15;
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
void String::clear()
{
	for(auto p = first_free; p != elements; /* empty */)
		alloc.destroy(--p);
	first_free = elements;
}
std::pair<char*, char*> String::alloc_n_copy(const char *b, const char *e)
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
	for(std::size_t i = 0; i != size(); ++i)
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
// Note1: don't know why, but uninitialized_copy and for_each don't work if std:: 
// isn't prefixed. This remains to be solved.

// Note2: here we can see the advantage of std::allocator compared to new/delete. If
// we use new/delete, we might have to use char array instead of raw and uninitialized
// memory.