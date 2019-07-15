#pragma once
#include <list>
#include <string>

class Book;

class Patron
{
private:
	std::string name;
	std::list<Book*> returnBooks;

public:
	Patron(std::string name);

	std::string& getName();
	void setNmae(std::string name);

	void borrowBook(Book& book);
	void returnBook(Book& book);

	std::list<Book*>& getReturnBooks();
};