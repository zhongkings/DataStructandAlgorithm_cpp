#include "Book.h"
#include "Patron.h"
#include <ostream>

Book::Book() :
patron(NULL)
{

}

bool Book::operator== (const Book& book) const
{
	return title == book.title;
}

std::ostream& Book::printBook(std::ostream& os) const
{
	os << " * " << title;
	if (patron != NULL)
		os << "- checked out to " << patron->name;
	os << std::endl;

	return os;
}

std::ostream& operator << (std::ostream& os, const Book& book)
{
	return book.printBook(os);
}