#pragma once
#include <string>

class Patron;
class Book 
{
private:
	Patron* patron;
	std::string title;
	std::ostream& printBook(std::ostream& os) const;
	friend std::ostream& operator << (std::ostream& os, const Book& book);
	friend class CheckedOutBook;
	friend Patron;
	friend void includeBook();
	friend void checkOutBook();
	friend void returnBook();

public:
	Book();

	bool operator == (const Book& book) const;
};