#include "Patron.h"
#include "Book.h"
#include "libData.h"

Patron::Patron(std::string name) :
name(name)
{
	int id = libData::findNumber(name[0]);
	libData::patronLs[id].push_back(this);
}

std::string& Patron::getName()
{
	return name;
}

void Patron::setNmae(std::string name)
{
	this->name = name;
}

void Patron::borrowBook(Book& book)
{
	returnBooks.push_back(&book);
}

void Patron::returnBook(Book& book)
{
	returnBooks.remove(&book);
}

std::list<Book*>& Patron::getReturnBooks()
{
	return returnBooks;
}