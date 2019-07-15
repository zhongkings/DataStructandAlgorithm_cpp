#pragma once
#include <list>
#include <string>

class Book;

class Author 
{
private:
	std::string name;
	std::list<Book*> mybookLs;

public:
	Author(std::string name);
	
	std::string& getName();
	void setNmae(std::string name);

	std::list<Book*>& getBooks();

	void addBook(Book& book);
	void removeBook(Book& book);
	void removeBook(std::string bookname);
};