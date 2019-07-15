#include "Head.h"
#include <algorithm>
using namespace std;

void SortList_FindIntermediateValue(string msg)
{
	cout << msg << endl;
	
	list<int> intLs = { 16, 98, 22, 11, 10, 8, 13 ,7 ,6 ,99 };
	cout << "Sort front: " << intLs << endl;

	intLs.sort();
	int midValue = -1;
	auto itIntLs = intLs.begin();
	for (int sizeDiv2 = (intLs.size() / 2); sizeDiv2 > 0; sizeDiv2--, itIntLs++) {
		cout << sizeDiv2 << endl;
		midValue = *itIntLs;
	}

	cout << "Sort back: " << intLs << endl;
	cout << "Mid value: " << midValue << endl;

	cout << endl;
}