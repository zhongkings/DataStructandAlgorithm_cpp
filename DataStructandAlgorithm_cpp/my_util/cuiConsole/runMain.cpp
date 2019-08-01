#include <iostream>
#include <sstream>
#include "cuiData.h"
#include "cuiWidget.h"
#include "cuiLayout.h"
#include "cuiInput.h"
#include "cuiLabel.h"
#include "cuiProgressbar.h"
#include "cuiList.h"
using namespace std;
using namespace cui;


int main(int argc, char **argv)
{
	Layout layout("RunMain--Test", 10, 10, GetStdHandle(STD_OUTPUT_HANDLE));
	layout.install(0, 0, enmCET_out);
	layout.install(1, 0, enmCET_out);
	layout.install(0, 1, enmCET_out);
	layout.install(0, 2, enmCET_in);
	layout.install(0, 3, enmCET_out);

	Label*  path = new Label(10, "Hello C++");
	Label*  cpp  = new Label(10, "Hello Cpp");
	Progressbar* prog  = new Progressbar(0, 100, 10);

	List* list = new List(4, 4, 10, "Title");
	vector<string> str;
	str.push_back("12345678");
	str.push_back("12345678");
	str.push_back("12345678");
	str.push_back("12345678");
	str.push_back("12345678");
	str.push_back("12345678");
	str.push_back("12345678");
	str.push_back("12345678");
	list->pushContainer(str);

	layout.push_back(path);
	layout.push_back(cpp);
	layout.push_back(prog);
	layout.push_back(list);

	while (true) {
		layout.clearBuffer();
		layout.print();

		string inputStr = layout.select();
		if (inputStr == "quit")
			break;
		else {
			float value;
			stringstream ss;
			ss << inputStr;
			ss >> value;
			prog->setChange(value);
		}
	}

	return 0;
}