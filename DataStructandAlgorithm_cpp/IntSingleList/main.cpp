#include "IntSingleList.h"
#include <iostream>
using namespace std;

ostream& operator << (ostream& os, IntSingleList& isl)
{
	IntSingleList::Iterator begin = isl.Begin();
	while (begin) {
		os << begin->getInfo() << " ";
		begin = begin->getNext();
	}

	

	return os;
}

int main() 
{
	IntSingleList isl;
	for (int i = 0; i < 10; i++)
		isl.addtoTail(i);

	isl.insert(520, 1);
	isl.removeOfValue(520);
	cout << isl;
	cout << "\nsize: " << isl.howsize();
	return 0;
}