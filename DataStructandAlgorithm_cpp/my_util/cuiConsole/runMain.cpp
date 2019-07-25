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
	//Widget
	Widget* path       = new Label(*argv, enmStyle_Lines, enmCFC_Purple);
	Widget* CppC       = new Label(16, "Hello C/C++");
	Widget* Java       = new Label(16, "Hello Java");
	Widget* Python     = new Label(16, "Hello Python");
	Widget* JavaScript = new Label(16, "Hello JavaScript");
	Widget* CSHARP     = new Label(16, "Hello CSHARP");
	Widget* Lua        = new Label(16, "Hello Lua");
	Progressbar* progressbar = new Progressbar(0, 100, 16);
	
	//Layout
	Layout layout(10, 10, GetStdHandle(STD_OUTPUT_HANDLE));
	layout.setIn(new Input(enmStyle_Lines, enmCFC_Blue));

	layout.install(0, 0, enmCET_in);
	layout.install(0, 1, enmCET_out);
	layout.install(0, 2, enmCET_out);
	layout.install(1, 2, enmCET_out);
	layout.install(0, 3, enmCET_out);
	layout.install(1, 3, enmCET_out);
	layout.install(0, 4, enmCET_out);
	layout.install(1, 4, enmCET_out);
	layout.install(0, 5, enmCET_out);

	layout.push_back(path);
	layout.push_back(CppC);
	layout.push_back(Java);
	layout.push_back(Python);
	layout.push_back(JavaScript);
	layout.push_back(CSHARP);
	layout.push_back(Lua);
	layout.push_back(progressbar);

	while (true)
	{
		layout.clear();
		layout.print();
		stringstream ss(layout.select());
		float changeValue = 0;
		ss >> changeValue;
		progressbar->setChange(changeValue);
	}
	return 0;
}