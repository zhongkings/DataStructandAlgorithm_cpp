#include "Book.h"
#include "Author.h"
#include "Patron.h"
#include "libData.h"

Book::Book(std::string name, std::string authorName) : 
name(name), patron(NULL)
{
	//��ӽ�bookLs
	int id = libData::findNumber(name[0]);
	libData::bookLs[id].push_back(this);

	//����ʱ��
	joinDate = libData::getCurrenTime();
	outDate = "NULL";

	//�ҵ������Ȼ���˳�
	Author* author = NULL;
	id = libData::findNumber(authorName[0]);
	auto it = libData::authorLs[id].begin();
	for (it; it != libData::authorLs[id].end(); it++) {
		author = *it;
		if (author->getName() == authorName) {
			author->addBook(*this);
			this->author = author;
			return;
		}

		author = NULL;
	}

	//û���ҵ����½�һ��
	author = new Author(authorName);
	author->addBook(*this);	
	this->author = author;
}

Book::Book(std::string name, Author& author) :
name(name), author(&author), patron(NULL)
{
	//����ʱ��
	joinDate = libData::getCurrenTime();
	outDate = "NULL";

	//��ӽ�bookLs
	int id = libData::findNumber(name[0]);
	libData::bookLs[id].push_back(this);

	this->author->addBook(*this);
}

std::string& Book::getName() 
{
	return name;
}

void Book::setName(std::string name)
{
	this->name = name;
}

std::string& Book::getjoinDate()
{
	return joinDate;
}

void Book::setjoinDate(std::string joinDate)
{
	this->joinDate = joinDate;
}

std::string& Book::getoutDate()
{
	return outDate;
}

void Book::setoutDate(std::string outDate)
{
	this->outDate = outDate;
}

Author& Book::getAuthor() 
{
	return *author;
}

void Book::setAuthor(Author& author)
{
	this->author = &author;
}

Patron& Book::getPatron()
{
	return *patron;
}

void Book::setPatron(Patron& patron)
{
	this->outDate = libData::getCurrenTime();
	this->patron = &patron;
}

bool Book::operator == (const Book& book)
{
	if (this->name != book.name)
		return false;
	if (this->author->getName() != book.author->getName())
		return false;

	return true;
}