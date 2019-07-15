#pragma once
#include <list>
#include <string>
class Book;
class Author;
class Patron;

class libData
{
public:
	static void Load();
	static void Save();
	static std::string getCurrenTime();
	static int findNumber(char c);
	static char lowToUp(char c);

	static std::list<Book*> *bookLs;
	static std::list<Author*> *authorLs;
	static std::list<Patron*> *patronLs;
};