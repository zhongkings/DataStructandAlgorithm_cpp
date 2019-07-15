#include "Head.h"
using namespace std;

void TheSameList(string msg)
{   cout << msg << endl;

	list<int> intLs1 = { 5, 10, 15, 20 };
	list<int> intLs2 = { 5, 9, 18, 20 };
	list<int> intLs3 = { 5, 10, 15, 20 };
	bool Ls1eqLs2 = true;
	bool Ls1eqLs3 = true;

	cout << "intLs1: " << intLs1 << endl;
	cout << "intLs2: " << intLs2 << endl;
	cout << "intLs3: " << intLs3 << endl;

	auto itLs1 = intLs1.begin();
	auto itLs2 = intLs2.begin();
	for (; itLs1 != intLs1.end() && itLs2 != intLs2.end(); itLs1++, itLs2++) {
		if (*itLs1 != *itLs2) {
			Ls1eqLs2 = false;
			break;
		}
	}
	itLs1 = intLs1.begin();
	auto itLs3 = intLs3.begin();
	for (; itLs1 != intLs1.end() && itLs3 != intLs3.end(); itLs1++, itLs3++) {
		if (*itLs1 != *itLs3) {
			Ls1eqLs3 = false;
			break;
		}
	}

	if (Ls1eqLs2)
		std::cout << "intLs1 == intLs2" << endl;
	else
		std::cout << "intLs1 != intLs2" << endl;
	if (Ls1eqLs3)
		std::cout << "intLs1 == intLs3" << endl;
	else
		std::cout << "intLs1 != intLs3" << endl;

	cout << endl; 
}