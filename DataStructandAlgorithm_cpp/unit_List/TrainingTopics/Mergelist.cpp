#include "Head.h"
#include <list>
using namespace std;

void MergeList(string msg) {
	cout << msg << endl;
	list<int> intLs1 = {5, 8, 9, 12};
	list<int> intLs2 = {3, 12, 14, 15, 16};
	list<int> mergeLs(intLs1);

	//Êä³öÏûÏ¢
	cout << "List1: " << intLs1 << endl;
	cout << "List2: " << intLs2 << endl;

	for (auto itLs2 = intLs2.begin(); itLs2 != intLs2.end(); itLs2++) {
		auto itmLs = mergeLs.begin();
		for (itmLs; itmLs != mergeLs.end(); itmLs++) {
			if (*itLs2 <= *itmLs) {
				mergeLs.insert(itmLs, *itLs2);
				break;
			}
		}
		if (itmLs == mergeLs.end()) {
			mergeLs.push_back(*itLs2);
		}
	}
	cout << "mergeList: " << mergeLs << endl;
	cout << endl;
}