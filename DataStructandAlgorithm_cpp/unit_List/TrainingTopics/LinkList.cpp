#include "Head.h"
using namespace std;

void LinkList(string msg)
{
	cout << msg << endl;

	list<int> intLs1 = { 1,2,8,4,5 };
	list<int> intLs2 = { 9,10,12,14 };
	cout << "intLs1: " << intLs1 << endl;
	cout << "intLs2: " << intLs2 << endl;

	auto itIntLs2 = intLs2.begin();
	for (itIntLs2; itIntLs2 != intLs2.end(); itIntLs2++)
		intLs1.push_back(*itIntLs2);
	cout << "intLs1 splice intLs2: " << intLs1 << endl;

	cout << endl;
}