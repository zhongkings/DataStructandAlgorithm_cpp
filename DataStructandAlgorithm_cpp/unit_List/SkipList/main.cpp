#include "SkipList.h"
#include "SkipList.cpp"
#include <iostream>
using namespace std;

int main() 
{
	SkipList<int> skipL;
	skipL.insert(150);
	skipL.insert(100);
	skipL.insert(200);

	cout << "chooseLevel: " << skipL.chooseLevel() << endl;
	skipL.choosePowers();

	int serachKey = 200;
	if (skipL.search(serachKey))
		cout << *skipL.search(serachKey) << endl;
	else
		cout << "ÊÇNULL" << endl;
	return 0;
}