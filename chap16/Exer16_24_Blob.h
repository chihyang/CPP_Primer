#ifndef EXER16_24_BLOB_H
#define EXER16_24_BLOB_H
#include <string>
#include <vector>
#include <initializer_list>
#include <memory>
#include <utility>
#include <stdexcept>
template <typename T> class BlobPtr;
template <typename T> class ConstBlobPtr;
template <typename T> class Blob;
template <typename T> bool operator==(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator!=(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator<(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator<=(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator>(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator>=(const Blob<T>&, const Blob<T>&);
template <typename T> class Blob {
	friend class BlobPtr<T>;
	friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
	friend bool operator!=<T>(const Blob<T>&, const Blob<T>&);
	friend bool operator< <T>(const Blob<T>&, const Blob<T>&);
	friend bool operator<=<T>(const Blob<T>&, const Blob<T>&);
	friend bool operator><T>(const Blob<T>&, const Blob<T>&);
	friend bool operator>=<T>(const Blob<T>&, const Blob<T>&);
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;
	typedef typename std::vector<T>::difference_type difference_type;
	// constructors
	Blob();
	Blob(std::initializer_list<T> il);
	// template member function required by exercise 16.24
	template <typename It> Blob(It b, It e);
	// size
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	// elements
	void push_back(const T &t) { data->push_back(t); }
	void push_back(T &&t) { data->push_back(std::move(t)); }
	void pop_back();
	T& front();
	T& back();
	// const version from exercise 12.2
	const T& front() const;
	const T& back() const;
	T& operator[] (size_type);
	const T& operator[] (size_type) const;
	T& at(size_type);
	const T& at(size_type) const;
	// use count
	size_type use_count() const { return data->use_count(); }
private:
	std::shared_ptr<std::vector<T>> data;
	void check(size_type, const std::string&) const;
};
// constructors
template <typename T>
Blob<T>::Blob(): data(std::make_shared<std::vector<T>>()) {}
template <typename T>
Blob<T>::Blob(std::initializer_list<T> il): data(std::make_shared<std::vector<T>>(il)) {}
template <typename T>
template <typename It>
Blob<T>::Blob(It b, It e) : data(std::make_shared<std::vector<T>>(b, e)) {}
// check index
template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
	if(i >= data->size())
		throw std::out_of_range(msg);
}
// add and remove elements
template <typename T>
void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}
// element access
template <typename T>
T& Blob<T>::front()
{
	check(0, "front on empty Blob");
	data->front();
}
template <typename T>
T& Blob<T>::back()
{
	check(0, "back on empty Blob");
	data->back();
}
template <typename T>
const T& Blob<T>::front() const
{
	check(0, "front on empty Blob");
	data->front();
}
template <typename T>
const T& Blob<T>::back() const
{
	check(0, "back on empty Blob");
	data->back();
}
template <typename T>
T& Blob<T>::operator[](size_type i)
{
	check(i, "index out of range");
	return (*data)[i];
}
template <typename T>
const T& Blob<T>::operator[](size_type i) const
{
	check(i, "index out of range");
	return (*data)[i];
}
template <typename T>
T& Blob<T>::at(size_type i)
{
	check(i, "index out of range");
	return data->at(i);
}
template <typename T>
const T& Blob<T>::at(size_type i) const
{
	check(i, "index out of range");
	return data->at(i);
}
// relational operators
template <typename T>
inline bool operator==(const Blob<T> &lhs, const Blob<T> &rhs)
{
	return *lhs.data == *rhs.data;
}
template <typename T>
inline bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs)
{
	return !(lhs == rhs);
}
template <typename T>
inline bool operator<(const Blob<T> &lhs, const Blob<T> &rhs)
{
	return *lhs.data < *rhs.data;
}
template <typename T>
inline bool operator<=(const Blob<T> &lhs, const Blob<T> &rhs)
{
	return (lhs < rhs || lhs == rhs);
}
template <typename T>
inline bool operator>(const Blob<T> &lhs, const Blob<T> &rhs)
{
	return !(lhs < rhs || lhs == rhs);
}
template <typename T>
inline bool operator>=(const Blob<T> &lhs, const Blob<T> &rhs)
{
	return !(lhs < rhs);
}
// ******************************
// nonconst version of BlobPtr
// ******************************
template <typename T> bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator!=(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator<(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator<=(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator>(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator>=(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator+(const BlobPtr<T>&, const BlobPtr<T>&);
// using class member that are types, see section 16.1.3, page 669
template <typename T> BlobPtr<T> operator+(const BlobPtr<T>&, typename Blob<T>::difference_type);
template <typename T> BlobPtr<T> operator-(const BlobPtr<T>&, typename Blob<T>::difference_type);
template <typename T> typename Blob<T>::difference_type operator-(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T>
class BlobPtr {
	friend bool operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&);
	friend bool operator!=<T>(const BlobPtr<T>&, const BlobPtr<T>&);
	friend bool operator< <T>(const BlobPtr<T>&, const BlobPtr<T>&);
	friend bool operator<=<T>(const BlobPtr<T>&, const BlobPtr<T>&);
	friend bool operator><T>(const BlobPtr<T>&, const BlobPtr<T>&);
	friend bool operator>=<T>(const BlobPtr<T>&, const BlobPtr<T>&);
	friend BlobPtr<T> operator+<T>(const BlobPtr<T>&, typename Blob<T>::difference_type);
	friend BlobPtr<T> operator-<T>(const BlobPtr<T>&, typename Blob<T>::difference_type);
	friend typename Blob<T>::difference_type operator-<T>(const BlobPtr<T>&, const BlobPtr<T>&);
public:
	typedef typename std::vector<T>::size_type size_type;
	BlobPtr();
	BlobPtr(Blob<T> &a, size_type sz = 0): wptr(a.data), curr(sz) {}
	// deference
	T& operator*() const;
	// subscript
	T& operator[](size_type);
	const T& operator[](size_type) const;
	// increment/decrement
	BlobPtr& operator++();
	BlobPtr& operator--();
	BlobPtr& operator++(int);
	BlobPtr& operator--(int);
	// compound assignment
	BlobPtr& operator+=(typename Blob<T>::difference_type); // addition
	BlobPtr& operator-=(typename Blob<T>::difference_type); // subtraction
private:
	std::shared_ptr<std::vector<T>> check(size_type, const std::string&) const;
	std::weak_ptr<std::vector<T>> wptr;
	size_type curr;
};
template <typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(size_type i, const std::string& msg) const
{
	auto ret = wptr.lock();
	if(!ret)
		throw std::runtime_error("unbound BlobPtr");
	if(i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}
// constructors
template <typename T>
BlobPtr<T>::BlobPtr(): curr(0) {}
// deference
template <typename T>
T& BlobPtr<T>::operator*() const
{
	auto p = check(curr, "deference past end");
	return (*p)[curr];
}
// subscript
template <typename T>
T& BlobPtr<T>::operator[](size_type n)
{
	auto p = check(curr + n, "subscript past end");
	return (*p)[curr + n];
}
template <typename T>
const T& BlobPtr<T>::operator[](size_type n) const
{
	auto p = check(curr + n, "subscript past end");
	return (*p)[curr + n];
}
// relational operator
template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	return lhs.curr == rhs.curr;
}
template <typename T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	return !(lhs == rhs);
}
template <typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	return lhs.curr < rhs.curr;
}
template <typename T>
bool operator<=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	return (lhs < rhs || lhs == rhs);
}
template <typename T>
bool operator>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	return !(lhs < rhs || lhs == rhs);
}
template <typename T>
bool operator>=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	return !(lhs < rhs);
}

// decrement and increment
template <typename T> 
BlobPtr<T>& BlobPtr<T>::operator++()
{
	auto p = check(curr, "increment past end of BlobPtr");
	++curr;
	return *this;
}
template <typename T> 
BlobPtr<T>& BlobPtr<T>::operator--()
{
	--curr;
	auto p = check(curr, "decrement past begin of BlobPtr");
	return *this;
}
template <typename T> 
BlobPtr<T>& BlobPtr<T>::operator++(int)
{
	auto ret = *this;
	--*this;
	return ret;
}
template <typename T> 
BlobPtr<T>& BlobPtr<T>::operator--(int)
{
	auto ret = *this;
	--*this;
	return ret;
}
template <typename T> 
BlobPtr<T>& BlobPtr<T>::operator+=(typename Blob<T>::difference_type n)
{
	curr += n;
	check(curr, "pointer addition past end of BlobPtr");
	return *this;
}
template <typename T> 
BlobPtr<T>& BlobPtr<T>::operator-=(typename Blob<T>::difference_type n)
{
	curr -= n;
	check(curr, "pointer subtraction past begin of BlobPtr");
	return *this;
}
// addition and subtraction
template <typename T>
BlobPtr<T> operator+(const BlobPtr<T> &sp, typename Blob<T>::difference_type n)
{
	auto sum = sp;
	sum += n;
	return sum;
}
template <typename T>
BlobPtr<T> operator-(const BlobPtr<T> &sp, typename Blob<T>::difference_type n)
{
	auto sum = sp;
	sum -= n;
	return sum;
}
template <typename T>
typename Blob<T>::difference_type operator-(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	return lhs.curr - rhs.curr;
}
#endif