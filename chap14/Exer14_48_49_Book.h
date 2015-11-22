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
	// overloaded equality operator required by exercise 14.17
	friend bool operator==(const Book&, const Book&);
	friend bool operator!=(const Book&, const Book&);
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
	Book& operator=(const string&); // take an ISBN as parameter, required by exercise 14.25
	~Book() = default;
	// meaningless bool conversion required by exercise 14.49, just for test
	explicit operator bool() const { return book_name.empty() &&
	    book_author.empty() && book_no.empty(); }
private:
	string book_name;
	string book_author;
	string book_no;
};
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
Book& Book::operator=(const string &isbn)
{
	book_no = isbn;
	return *this;
}
// friend definition
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
}bool operator==(const Book &lhs, const Book &rhs)
{
	return lhs.book_name == rhs.book_name &&
	       lhs.book_author == rhs.book_name &&
		   lhs.book_no == rhs.book_no;
}
bool operator!=(const Book &lhs, const Book &rhs)
{
	return !(lhs == rhs);
}
#endif