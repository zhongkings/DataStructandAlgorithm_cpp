#pragma once
#include <list>

class Book;
class Author;
class CheckedOutBook
{
private:
	std::list<Book>::iterator bookIt;
	std::list<Author>::iterator authorIt;
	friend void checkOutBook();
	friend void returnBook();
	friend class Patron;

public:
	CheckedOutBook(std::list<Author>::iterator& authorIt, std::list<Book>::iterator& bookIt);
	bool operator == (const CheckedOutBook& bk) const;
};