#include "libData.h"
#include "Book.h"
#include "Author.h"
#include "Patron.h"
#include "CheckedOutBook.h"
#include <iostream>
#include <string>
#include <algorithm>

std::list<Author> libData::catalog['Z' + 1];
std::list<Patron> libData::people['Z' + 1];

template<class T>
std::ostream& operator<< (std::ostream& os, std::list<T>& list)
{
	auto it = list.begin();
	for (it; it != list.end(); it++)
		os << *it;

	return os;
}

std::string getInput(std::string msg, bool isCapfirstUp = false)
{
	std::cout << msg << std::endl;

	std::string inputStr;
	std::getline(std::cin, inputStr);

	//判断是否小写字母
	if (isCapfirstUp)
		inputStr[0] = toupper(inputStr[0]);

	return inputStr;
}

void libData::status(){
	std::cout << "Library has the following books: \n\n";
	for (int A = 'A'; A <= 'Z'; A++)
		if (!catalog[A].empty())
			std::cout << catalog[A];
}

void includeBook()
{
	Author newAuthor;
	Book newBook;
	newAuthor.name = getInput("Enter author's name: ", true);
	newBook.title = getInput("Enter the title of the book: ");

	auto oldAuthor = std::find(libData::catalog[newAuthor.name[0]].begin(), libData::catalog[newAuthor.name[0]].end(), newAuthor);
	if (oldAuthor == libData::catalog[newAuthor.name[0]].end()) {
		newAuthor.mybookLs.push_front(newBook);
		libData::catalog[newAuthor.name[0]].push_front(newAuthor);
	}
	else (*oldAuthor).mybookLs.push_front(newBook);
}

void checkOutBook()
{
	Patron patron;
	Author author;
	Book book;
	std::list<Author>::iterator authorRef;
	std::list<Book>::iterator bookRef;
	std::list<Patron>::iterator patronRef;

	//输入借书人的姓名
	patron.name = getInput("Enter patron's name: ", true);
	if (patron.name == "#menu") return; //退出当前功能

	while (true) {
		author.name = getInput("Enter author's name: ", true);
		if (author.name == "#menu") return; //退出当前功能

		authorRef = std::find(libData::catalog[author.name[0]].begin(), libData::catalog[author.name[0]].end(), author);
		if (authorRef == libData::catalog[author.name[0]].end())
			std::cout << "Misspelled author's name \n";
		else break;
	}
	while (true) {
		book.title = getInput("Enter the title of the book: ");
		if (book.title == "#menu") return; //退出当前功能

		bookRef = std::find((*authorRef).mybookLs.begin(), (*authorRef).mybookLs.end(), book);
		if (bookRef == (*authorRef).mybookLs.end())
			std::cout << "Misspelled title. \n";
		else if (bookRef->patron != NULL)
			std::cout << "Sorry,the books have been lent out. \n";
		else break;
	}

	patronRef = std::find(libData::people[patron.name[0]].begin(), libData::people[patron.name[0]].end(), patron);
	CheckedOutBook cob(authorRef, bookRef);
	if (patronRef == libData::people[patron.name[0]].end())
	{
		patron.mychbookLs.push_front(cob);
		libData::people[patron.name[0]].push_front(patron);
		bookRef->patron = &*libData::people[patron.name[0]].begin(); //赋值最后插入的patron
	}
	else {
		patronRef->mychbookLs.push_front(cob);
		bookRef->patron = &*patronRef;
	}
}

void returnBook() 
{
	Patron patron;
	Book book;
	Author author;
	std::list<Patron>::iterator patronRef;
	std::list<Book>::iterator bookRef;
	std::list<Author>::iterator authorRef;

	while (true) {
		patron.name = getInput("Enter patron's name: ", true);
		if (patron.name == "#menu") return; //退出当前功能

		patronRef = std::find(libData::people[patron.name[0]].begin(), libData::people[patron.name[0]].end(), patron);
		if (patronRef == libData::people[patron.name[0]].end())
			std::cout << "Patron's name misspelled \n";
		else break;
	}
	while (true) {
		author.name = getInput("Enter author's name: ", true);
		if (author.name == "#menu") return; //退出当前功能

		authorRef = std::find(libData::catalog[author.name[0]].begin(), libData::catalog[author.name[0]].end(), author);
		if (authorRef == libData::catalog[author.name[0]].end())
			std::cout << "Author's name misspelled \n";
		else break;
	}
	while (true) {
		book.title = getInput("Enter the title the book: ");
		if (book.title == "#menu") return; //退出当前功能

		bookRef = std::find(authorRef->mybookLs.begin(), authorRef->mybookLs.end(), book);
		if (bookRef == authorRef->mybookLs.end())
			std::cout << "Misspelied title. \n";
		else break;
	}

	CheckedOutBook cob(authorRef, bookRef);
	bookRef->patron = NULL;
	patronRef->mychbookLs.remove(cob);
}