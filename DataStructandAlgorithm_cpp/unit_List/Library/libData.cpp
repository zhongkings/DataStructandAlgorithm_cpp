#include "libData.h"
#include "Book.h"
#include "Author.h"
#include "Patron.h"
#include <ctime>
#include <ostream>
#include <fstream>

std::list<Book*>* libData::bookLs = new std::list<Book*>[26];
std::list<Author*>* libData::authorLs = new std::list<Author*>[26];
std::list<Patron*>* libData::patronLs = new std::list<Patron*>[26];

std::string libData::getCurrenTime()
{
	//譜崔序秘扮寂
	time_t t = time(0);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y/%m/%d/%X %A", localtime(&t));
	return tmp;
}

int libData::findNumber(char c)
{
	if (c > 'Z')
		c = lowToUp(c);

	return c - 'A';
}

char libData::lowToUp(char c)
{
	/*A、B、C、D、E、F、G、H、I、J、K、
	  L、M、N、O、P、Q、R、S、T、U、V、
	  W、X、Y、Z*/
	switch (c) {
	case 'a': return 'A';
	case 'b': return 'B';
	case 'c': return 'C';
	case 'd': return 'D';
	case 'e': return 'E';
	case 'f': return 'F';
	case 'g': return 'G';
	case 'h': return 'H';
	case 'i': return 'I';
	case 'j': return 'J';
	case 'k': return 'K';

	case 'l': return 'L';
	case 'm': return 'M';
	case 'n': return 'N';
	case 'o': return 'O';
	case 'p': return 'P';
	case 'q': return 'Q';
	case 'r': return 'R';
	case 's': return 'S';
	case 't': return 'T';
	case 'u': return 'U';
	case 'v': return 'V';

	case 'w': return 'W';
	case 'x': return 'X';
	case 'y': return 'Y';
	case 'z': return 'Z';
	}

	return 'A';
}