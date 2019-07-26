#include "cuiInput.h"
#include <iostream>

cui::Input::Input(const CPrintStyle& style,
	const CForeGroundColor& foreColor,
	const CBackGroundColor& backColor) : Widget("", style, foreColor, backColor)
{

}

cui::Input::~Input()
{

}

std::string cui::Input::in()
{
	std::string str;
	std::cin >> str;

	return str;
}
