#include "CheckedOutBook.h"
#include "Book.h"
#include "Author.h"

CheckedOutBook::CheckedOutBook(std::list<Author>::iterator& authorIt, std::list<Book>::iterator& bookIt) :
	bookIt(bookIt), authorIt(authorIt)
{

}

bool CheckedOutBook::operator == (const CheckedOutBook& bk) const
{
	if (bookIt->title != bk.bookIt->title)
		return false;
	if (authorIt->name != bk.authorIt->name)
		return false;

	return true;
}