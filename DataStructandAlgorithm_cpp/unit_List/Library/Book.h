#pragma once
#include <string>
#include <list>

class Author;
class Patron;

class Book 
{
private:
	std::string name;
	Author* author;
	Patron* patron;

	std::string joinDate; //加入时间
	std::string outDate; //借出时间
public:
	Book(std::string name, std::string authorName);
	Book(std::string name, Author& author);

	std::string& getName();
	void setName(std::string name);

	std::string& getjoinDate();
	void setjoinDate(std::string joinDate);

	std::string& getoutDate();
	void setoutDate(std::string outDate);

	Author& getAuthor();
	void setAuthor(Author& author);

	Patron& getPatron();
	void setPatron(Patron& patron);

	bool operator == (const Book& book);
};