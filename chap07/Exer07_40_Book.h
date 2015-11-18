// Note: this is a redefinition from chapter 14. It covers contents beyond chapter 7.
#ifndef EXER07_40_BOOK_H
#define EXER07_40_BOOK_H
#include <string>
#include <utility>
using std::string;
class Book {
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