#include "IntSingleList.h"
#include "SkipList.h"
#include "SkipList.cpp"
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
	return 0;
}