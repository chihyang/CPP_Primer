#ifndef EXER16_16_VEC_H
#define EXER16_16_VEC_H
#include <cstddef>
#include <utility>
#include <memory>
#include <initializer_list>
template <typename T> class Vec;
// equality operator required by exercise 14.16
template <typename T> bool operator==(const Vec<T>&, const Vec<T>&);
template <typename T> bool operator!=(const Vec<T>&, const Vec<T>&);
// relation operator required by exercise 14.18
template <typename T> bool operator<(const Vec<T>&, const Vec<T>&);
template <typename T> bool operator<=(const Vec<T>&, const Vec<T>&);
template <typename T> bool operator>(const Vec<T>&, const Vec<T>&);
template <typename T> bool operator>=(const Vec<T>&, const Vec<T>&);
template <typename T>
class Vec {
	// equality operator required by exercise 14.16
	friend bool operator==<T>(const Vec<T>&, const Vec<T>&);
	friend bool operator!=<T>(const Vec<T>&, const Vec<T>&);
	// relation operator required by exercise 14.18
	friend bool operator< <T>(const Vec<T>&, const Vec<T>&);
	friend bool operator<=<T>(const Vec<T>&, const Vec<T>&);
	friend bool operator><T>(const Vec<T>&, const Vec<T>&);
	friend bool operator>=<T>(const Vec<T>&, const Vec<T>&);
public:
	Vec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
	Vec(const Vec&);
	// move constructor from page 536
	Vec(Vec&&) noexcept;
	Vec& operator=(const Vec&);
	// move assignment from page 537
	Vec& operator=(Vec&&) noexcept;
	// assignment with an std::initializer_list parameter from page 563
	Vec& operator=(std::initializer_list<T>);
	// constructor that takes a std::initializer_list as parameter, required by exercise 13.40
	Vec(const std::initializer_list<T>&);
	// subscript operator from page 565
	// class is not responsible for checking if the subscript is out of range
	T& operator[](std::size_t n) // nonconst version of subscript operator
	{ return elements[n]; }
	T& operator[](std::size_t n) const // const version of subscript operator
	{ return elements[n]; }
	~Vec();
	void push_back(const T&);
	void push_back(T&&);
	std::size_t size() const { return first_free - elements; }
	std::size_t capacity() const { return cap - elements; }
	T *begin() const { return elements; }
	T *end() const { return first_free; } // both begin() and end() are const
	// reserve and resize required by exercise 13.39
	void reserve(std::size_t);
	void resize(std::size_t);
	void resize(std::size_t, const T&);
private:
	static std::allocator<T> alloc;
	void chk_n_alloc() { if(size() == capacity()) reallocate(); }
	std::pair<T*, T*> alloc_n_copy(const T*, const T*);
	void free();
	void reallocate();
	void add_rem(std::size_t n, const T &s = "");
	T *elements;
	T *first_free;
	T *cap;
};
// Warning: define static member outside the class. Without this the program
// using the class wouldn't compile
template <typename T>
std::allocator<T> Vec<T>::alloc;
// friend definition
template <typename T>
bool operator==(const Vec<T> &lhs, const Vec<T> &rhs)
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
template <typename T>
bool operator!=(const Vec<T> &lhs, const Vec<T> &rhs)
{
	return !(lhs == rhs);
}
template <typename T>
bool operator<(const Vec<T> &lhs, const Vec<T> &rhs)
{
	auto shorter = lhs.size() < rhs.size() ? lhs.size() : rhs.size();
	auto p = lhs.begin(), q = rhs.begin();
	for(std::size_t i = 0; p + i != lhs.end(); ++i)
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
template <typename T>
bool operator<=(const Vec<T> &lhs, const Vec<T> &rhs)
{
	return lhs < rhs || lhs == rhs;
}
template <typename T>
bool operator>(const Vec<T> &lhs, const Vec<T> &rhs)
{
	return !(lhs < rhs || lhs == rhs);
}
template <typename T>
bool operator>=(const Vec<T> &lhs, const Vec<T> &rhs)
{
	return !(lhs < rhs);
}
template <typename T>
void Vec<T>::push_back(const T &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}
template <typename T>
void Vec<T>::push_back(T &&s)
{
	chk_n_alloc();
	alloc.construct(first_free++, std::move(s));
}
template <typename T>
std::pair<T*, T*> Vec<T>::alloc_n_copy(const T *b, const T *e)
{
	auto data = alloc.allocate(e - b);
	return {data, std::uninitialized_copy(b, e, data)};
}
template <typename T>
void Vec<T>::free()
{
	if (elements) {
		for(auto p = first_free; p != elements; /*empty*/ )
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}
template <typename T>
Vec<T>::Vec(const Vec &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap =  newdata.second;
}
template <typename T>
Vec<T>::Vec(Vec &&s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	s.elements = s.first_free = s.cap = nullptr;
}
template <typename T>
Vec<T>::Vec(const std::initializer_list<T> &il)
{
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
template <typename T>
Vec<T>::~Vec()
{
	free();
}
template <typename T>
Vec<T>& Vec<T>::operator=(const Vec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}
template <typename T>
Vec<T>& Vec<T>::operator=(Vec &&rhs) noexcept
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
template <typename T>
Vec<T>& Vec<T>::operator=(std::initializer_list<T> il)
{
	auto data = alloc_n_copy(il.begin(), il.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}
template <typename T>
void Vec<T>::reallocate()
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
template <typename T>
void Vec<T>::reserve(std::size_t n)
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
template <typename T>
void Vec<T>::resize(std::size_t n)
{
	add_rem(n);
}
template <typename T>
void Vec<T>::resize(std::size_t n, const T &s)
{
	add_rem(n, s);
}
template <typename T>
void Vec<T>::add_rem(std::size_t n, const T &s)
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