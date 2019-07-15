#pragma once
#include <string>
#include <list>

class Book;
class Patron;

class Author
{
private:
	std::string name;
	std::list<Book> mybookLs;
	std::ostream& printAuthor(std::ostream&) const;
	friend std::ostream& operator << (std::ostream& os, const Author& author);
	friend void includeBook();
	friend void checkOutBook();
	friend void returnBook();
	friend class CheckedOutBook;
	friend Patron;

public:
	Author();
	bool operator == (const Author& author) const;
};