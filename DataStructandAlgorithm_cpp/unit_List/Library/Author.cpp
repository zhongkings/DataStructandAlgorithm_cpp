#include "Author.h"
#include "Book.h"
#include "libData.h"

Author::Author(std::string name) : 
name(name) 
{
	int id = libData::findNumber(name[0]);
	libData::authorLs[id].push_back(this);
}

std::string& Author::getName()
{
	return name;
}

void Author::setNmae(std::string name)
{
	this->name = name;
}

std::list<Book*>& Author::getBooks()
{
	return mybookLs;
}

void Author::addBook(Book& book) 
{
	mybookLs.push_back(&book);
}

void Author::removeBook(Book& book)
{
	mybookLs.remove(&book);
}

void Author::removeBook(std::string bookname)
{
	auto it = mybookLs.begin();
	for (it; it != mybookLs.end(); it++)
	{
		Book* em = *it;
		if (em->getName() == bookname) {
			mybookLs.erase(it);
			break;
		}
	}
}