#include "Head.h"
using namespace std;

int main(int argc, char** argv)
{
	cout << argc << " " << *argv << endl << endl;
	MergeList("Two ordered lists are combined to form an ordered list.");
	TheSameList("See if linked lists are the same.");
	ReverseList("Reverse a linked list.");
	LinkList("Splice List.");
	SortList_FindIntermediateValue("Sort the list and find the intermediate value.");
	return 0;
}