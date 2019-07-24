#include <iostream>
#include <string>
#include <conio.h>
#include "cuiData.h"
using namespace std;
using namespace cui;

static HANDLE handle;

void DrawBox(int xMax, int yMax, char c = ' ')
{
	for (int y = 0; y < yMax; y++) {
		for (int x = 0; x < xMax; x++) {
			//Up Border
			if (x == 0 && y == 0)
				cout << "©³";
			else if (x == xMax - 1 && y == 0)
				cout << "©·";
			else if (x > 0 && y == 0)
				cout << "©¥";

			//Down Border
			if (x == 0 && y == yMax - 1)
				cout << "©»";
			else if (x == xMax - 1 && y == yMax - 1)
				cout << "©¿";
			else if (x > 0 && y == yMax - 1)
				cout << "©¥";

			//Mid
			else if (x == 0 && y > 0)
				cout << "©§";
			else if (x == xMax - 1 && y > 0)
				cout << "©§";
			else if (x > 0 && y > 0)
				cout << c;

		}
		cout << endl;
	}

	cout << endl;
	return;
}

void BoxString(const string& str, bool up = true, bool down = true, bool left = true, bool right = true)
{
	int xMax = str.size() + 2;
	int yMax = count(begin(str), end(str), '\n') + 3;
	int index = 0;
	for (int y = 0; y < yMax; y++) {
		for (int x = 0; x < xMax; x++) {
			//Up Border
			if (x == 0 && y == 0 && up && left)
				cout << "©³";
			else if (x == xMax - 1 && y == 0 && up && right)
				cout << "©·";
			else if (x > 0 && y == 0 && up)
				cout << "©¥";

			//Down Border
			if (x == 0 && y == yMax - 1 && down && left)
				cout << "©»";
			else if (x == xMax - 1 && y == yMax - 1 && down && right)
				cout << "©¿";
			else if (x > 0 && y == yMax - 1 && down)
				cout << "©¥";

			//Mid
			else if (x == 0 && y > 0 && left)
				cout << "©§";
			else if (x == xMax - 1 && y > 0 && right)
				cout << "©§";
			else if (x > 0 && y > 0 && index < str.size()) {
				cout << str[index++];
			}

		}
		cout << endl;
	}

	return;
}

int main()
{
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, enmCFC_Purple);
	while (true)
	{
		char c = _getch();
		cout << (int)c << endl;
	}

	return 0;
}