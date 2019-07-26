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
	Layout layout(10, 10, GetStdHandle(STD_OUTPUT_HANDLE));

	layout.install(0, 0, enmCET_out);
	layout.install(1, 0, enmCET_out);
	layout.install(2, 0, enmCET_out);

	Label*  path = new Label(16, "HelloCCC");
	Label*  cpp  = new Label(16, "Hello C++");
	Progressbar* prog  = new Progressbar(0, 100, 16);
	prog->setChange(20);

	layout.push_back(path);
	layout.push_back(cpp);
	layout.push_back(prog);

	while (true) {
		layout.clearBuffer();
		layout.print();
	}

	return 0;
}