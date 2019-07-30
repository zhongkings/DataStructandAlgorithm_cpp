#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main()
{
	vector<int> v1 = { 31, 12, 11, 0, 1, 2, 3,4,5,6,7,8,9 };
	vector<int> v2 = { 0, 1, 2, 3,4,5,6,7,8,9 };
	sort(begin(v1), end(v1));
	for (auto itv1 = begin(v1); itv1 != end(v1); itv1++) {
		for (auto itv2 = begin(v2); itv2 != end(v2); itv2++) {
			if ((*itv1) == (*itv2))
				itv1 = v1.erase(itv1);
		}
	}

	for (auto it = begin(v1); it != end(v1); it++)
		cout << *it << endl;

	return 0;
}