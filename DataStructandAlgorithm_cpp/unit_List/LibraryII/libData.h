#pragma once
#include <list>
#include <ostream>

class Author;
class Patron;

class libData
{
private:
	static std::list<Author> catalog['Z' + 1];
	static std::list<Patron> people['Z' + 1];

public:
	static void status();

	template <class T>
	friend std::ostream& operator<< (std::ostream& os, std::list<T>& list);

	friend std::string getInput(std::string msg, bool isCapfirstUp);

	friend void includeBook();
	friend void checkOutBook();
	friend void returnBook();
};