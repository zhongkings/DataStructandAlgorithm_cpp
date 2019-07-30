#include <iostream>
#include <sstream>
#include "cuiData.h"
#include "cuiWidget.h"
#include "cuiLayout.h"
#include "cuiInput.h"
#include "cuiLabel.h"
#include "cuiProgressbar.h"
using namespace std;
using namespace cui;


int main(int argc, char **argv)
{
	Layout layout("RunMain--Test", 10, 10, GetStdHandle(STD_OUTPUT_HANDLE));
	layout.install(0, 0, enmCET_out);
	layout.install(1, 0, enmCET_out);
	layout.install(2, 0, enmCET_out);
	layout.install(0, 1, enmCET_in);

	Label*  path = new Label(10, "Hello   C");
	Label*  cpp  = new Label(10, "Hello C++");
	Progressbar* prog  = new Progressbar(0, 100, 10);

	layout.push_back(path);
	layout.push_back(cpp);
	layout.push_back(prog);

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