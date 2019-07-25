#pragma once
#include "cuiSingleInput.h"
#include <conio.h>

cui::SingleInput::SingleInput(const CPrintStyle& style,
	const CForeGroundColor& foreColor,
	const CBackGroundColor& backColor) : Widget("", style, foreColor, backColor)
{

}

std::string cui::SingleInput::in()
{
	std::string str;
	str = _getch();
	return str;
}