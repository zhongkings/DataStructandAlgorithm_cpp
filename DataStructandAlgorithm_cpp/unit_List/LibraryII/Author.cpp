#include "Author.h"
#include "Book.h"
#include <ostream>

Author::Author()
{

}

bool Author::operator == (const Author& author) const
{
	return name == author.name;
}

std::ostream& Author::printAuthor(std::ostream& os) const
{
	os << name << std::endl;
	auto it = mybookLs.begin();
	for (it; it != mybookLs.end(); it++)
		os << *it;
	return os;
}

std::ostream& operator << (std::ostream& os, const Author& author)
{
	return author.printAuthor(os);
}