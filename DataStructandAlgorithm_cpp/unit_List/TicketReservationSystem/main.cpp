#include "cuiBase.h"
#include "cuiWidget.h"
#include "cuiItem.h"
#include "cuiInput.h"
#include <iostream>
using namespace std;
using namespace cui;

int main(int argc, char **argv) 
{
	Base base(3, 2);

	while (true) {
		base.clear();
		base.show();
	}
	return 0;
}
