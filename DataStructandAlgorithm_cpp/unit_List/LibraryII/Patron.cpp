#include "Patron.h"
#include "CheckedOutBook.h"
#include "Author.h"
#include "Book.h"
#include <ostream>

Patron::Patron()
{
	
}

bool Patron::operator == (const Patron& patron) const
{
	return name == patron.name;
}

std::ostream& Patron::printPatron(std::ostream& os) const
{
	os << name;
	if (!mychbookLs.empty()) {
		os << "has the following books: \n";
		auto it = mychbookLs.begin();
		for (it; it != mychbookLs.end(); it++) {
			os << " * " << it->authorIt->name << ", "
			   << it->bookIt->title << std::endl;
		}
	}
	else os << " has on books \n";

	return os;
}

std::ostream& operator << (std::ostream& os, const Patron& patron)
{
	return patron.printPatron(os);
}