#include "Book.h"
#include "Author.h"
#include "Patron.h"
#include "Show.h"
#include <iostream>

void Show::showBook(Book& book, bool isshowauthor)
{
	std::cout << book.getName() << " -- " << book.getAuthor().getName() 
		                        << " -- " << book.getjoinDate() << std::endl;
}

void Show::showAuthor(Author& author, bool isshowbook)
{
	std::cout << author.getName() << std::endl;
	
	if (!isshowbook)
		return;

	auto it = author.getBooks().begin();
	for (it; it != author.getBooks().end(); it++) {
		Book* em = *it;
		std::cout << "  ";
		showBook(*em);
	}
}

void Show::showPatron(Patron& patron, bool isshowbook)
{
	std::cout << patron.getName() << std::endl;

	if (!isshowbook)
		return;

	auto it = patron.getReturnBooks().begin();
	for (it; it != patron.getReturnBooks().end(); it++) {
		Book* em = *it;
		std::cout << "  ";
		showBook(*em);
	}
}