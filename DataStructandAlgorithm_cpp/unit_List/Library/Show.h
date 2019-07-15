#pragma once

class Book;
class Author;
class Patron;

class Show
{
public:
	static void showBook(Book& book, bool isshowauthor = false);
	static void showAuthor(Author& author, bool isshowbook = false);
	static void showPatron(Patron& patron, bool isshowbook = false);
};