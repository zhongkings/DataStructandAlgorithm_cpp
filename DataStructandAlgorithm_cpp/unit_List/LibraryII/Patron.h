#pragma once
#include <string>
#include <list>

class CheckedOutBook;
class Patron
{
private:
	std::string name;
	std::list<CheckedOutBook> mychbookLs;
	std::ostream& printPatron(std::ostream&) const;
	friend std::ostream& operator << (std::ostream& os, const Patron& patron);
	friend void checkOutBook();
	friend void returnBook();
	friend class Book;
public:
	Patron();
	bool operator == (const Patron& patron) const;
};