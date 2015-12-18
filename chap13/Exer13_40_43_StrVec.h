#ifndef STRVEC_H
#define STRVEC_H
#include <cstddef>
#include <string>
#include <utility>
#include <memory>
#include <initializer_list>
#include <algorithm>
class StrVec {
public:
	StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);
	// constructor that takes a std::initializer_list as parameter, required by exercise 13.40
	StrVec(const std::initializer_list<std::string>&);
	~StrVec();
	void push_back(const std::string&);
	std::size_t size() const { return first_free - elements; }
	std::size_t capacity() const { return cap - elements; }
	std::string *begin() const { return elements; }
	std::string *end() const { return first_free; } // both begin() and end() are const
	// reserve and resize required by exercise 13.39
	void reserve(std::size_t);
	void resize(std::size_t);
	void resize(std::size_t, const std::string&);
private:
	static std::allocator<std::string> alloc;
	void chk_n_alloc() { if(size() == capacity()) reallocate(); }
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
	void free();
	void reallocate();
	void add_rem(std::size_t n, const std::string &s = "");
	std::string *elements;
	std::string *first_free;
	std::string *cap;
};
// Warning: define static member outside the class, without this the program
// using the class won't compile
std::allocator<std::string> StrVec::alloc;
void StrVec::push_back(const std::string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}
std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
	auto data = alloc.allocate(e - b);
	return {data, uninitialized_copy(b, e, data)};
}
void StrVec::free()
{
	if (elements) {
		// if we use lambda and algorithm, we must use reference rather than pointer directly
		for_each(begin(), end(), [](const std::string &s) {alloc.destroy(&s);} );
		alloc.deallocate(elements, cap - elements);
	}
}
StrVec::StrVec(const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap =  newdata.second;
}
StrVec::StrVec(const std::initializer_list<std::string> &il)
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
void StrVec::reallocate()
{
	// we'll allocate space for twice as many as the current size
	auto newcapacity = size() ? 2 * size() : 1; // if empty, allocate 1 space, otherwise double
	// allocate new memory
	auto newdata = alloc.allocate(newcapacity);
	// move the data from the old memory to the new
	auto dest = newdata; // points to the next free position in the new memory
	auto elem = elements; // points to the next element in the old memory
	for(std::size_t i = 0; i != size(); ++i)
		alloc.construct(dest++,  std::move(*elem++));
	free(); // free the old space once we've moved the elements
	// update our data structure to point to the new elements
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}
void StrVec::reserve(std::size_t n)
{
	if(n > capacity())
	{
		auto newdata = alloc.allocate(n);
		auto dest = newdata;
		auto elem = elements;
		for(std::size_t i = 0; i != size(); ++i)
			alloc.construct(dest++, std::move(*elem++));
		free();
		elements = newdata;
		first_free = newdata;
		cap = elements + n;
	}
}
void StrVec::resize(std::size_t n)
{
	add_rem(n);
}
void StrVec::resize(std::size_t n, const std::string &s)
{
	add_rem(n, s);
}
void StrVec::add_rem(std::size_t n, const std::string &s)
{
	if(n <= size()) {
		auto p = first_free;
		while(p != elements + n)
			alloc.destroy(--p);
		first_free = p;
	}
	else{
		auto new_elem_count = n - size();
		for(std::size_t i = 0; i != new_elem_count; ++i)
			push_back(s);
	}
}
#endif
// Note: in this program we use a static member, never forget to define this 
// member outside the class(Page 302). We do not need to repeat the static 
// keyword. We can use default initialization of std::allocator, so we do not need to
// provide an initializer.