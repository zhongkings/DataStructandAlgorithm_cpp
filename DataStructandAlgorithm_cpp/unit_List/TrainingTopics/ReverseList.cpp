#include "Head.h"
using namespace std;

void ReverseList(string msg)
{
	cout << msg << endl;

	list<int> intLs = { 0, 10, 15, 17, 2, 3, 4, 5, 9 };
	list<int> reintLs;
	cout << "Reverse front: " << intLs << endl;

	//Reverse
	auto itIntls = intLs.begin();
	for (itIntls; itIntls != intLs.end(); itIntls++) {
		reintLs.push_front(*itIntls);
	}
	cout << "Reverse back: " << reintLs << endl;

	cout << endl;
}