#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <utility>
using std::ostream;
using std::istream;
using std::string;
class Book {
	// overloaded output operator required by exercise 14.8
	friend ostream &operator<<(ostream&, const Book&);
	// overloaded input operator required by exercise 14.12
	friend istream &operator>>(istream&, Book&);
public:
	Book() = default;
	Book(string na, string au = "", string no = "") : 
	    book_name(na), book_author(au), book_no(no) {}
	// copy control constructor
	Book(const Book&) = default; // copy constructor
	Book(Book &&b) noexcept :// move constructor
	    book_name(std::move(b.book_name)),
		book_author(std::move(b.book_author)),
		book_no(std::move(book_no)) {}
	Book& operator=(const Book&) = default; // copy-assignment operator
	Book& operator=(Book&&) noexcept; // move assignment operator
	~Book() = default;
private:
	string book_name;
	string book_author;
	string book_no;
};
// friend declaration outside class
ostream &operator<<(ostream&, const Book&);
istream &operator>>(istream&, Book&);
ostream& operator<<(ostream& os, const Book &b)
{
	os << b.book_name << " " << b.book_author << " " << b.book_no;
	return os;
}
istream& operator>>(istream& is, Book &b)
{
	is >> b.book_name >> b.book_author >> b.book_no;
	if(is)
		b = Book();
	return is;
}
Book& Book::operator=(Book &&rhs) noexcept
{
	if(this != &rhs)
	{
		book_name = std::move(rhs.book_name);
		book_author = std::move(rhs.book_author);
		book_no = std::move(rhs.book_no);
	}
	return *this;
}
#endif