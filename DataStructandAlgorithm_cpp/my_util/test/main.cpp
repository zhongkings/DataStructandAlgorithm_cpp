#include <iostream>
#include <list>
#include <string>
#include <memory>
#include <vector>
using namespace std;
#define MAX 10

class IntClass
{
public:
	int value;

	IntClass(int value) : value(value) {}
	IntClass():value(10) {}

	~IntClass() {
		cout << "Îö¹¹º¯Êý" << endl;
	}
};

void printPtr(int *p)
{
	cout << p << endl;
}

int main()
{
	int* p1 = new int(102);
	int* p2 = p1;
	cout << p1 << endl;
	cout << p2 << endl;
	printPtr(p1);

	return 0;
}