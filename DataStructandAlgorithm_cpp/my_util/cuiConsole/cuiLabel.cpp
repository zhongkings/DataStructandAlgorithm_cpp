#include "cuiLabel.h"
#include <iostream>

cui::Label::Label(const std::string& content,
	const CPrintStyle& style,
	const CForeGroundColor& foreColor,
	const CBackGroundColor& backColor) : Widget(content, style, foreColor, backColor)
{

}

cui::Label::Label(const int& length, const std::string& content,
	const CPrintStyle& style,
	const CForeGroundColor& foreColor,
	const CBackGroundColor& backColor) : Widget(content, length, style, foreColor, backColor)
{

}

cui::Label::~Label()
{

}

void cui::Label::print()
{
	std::string str;
	if (content.size() < length) {
		str = content;
		str.append(length - content.size(), ' ');
	}
	else if (content.size() > length) {
		for (int i = 0; i < length; i++)
			str.push_back(content[i]);
	}
	else
		str = content;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), foreColor | backColor | style);
	std::cout << str;
}