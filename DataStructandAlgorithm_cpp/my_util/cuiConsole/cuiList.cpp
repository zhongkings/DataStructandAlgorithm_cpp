#ifdef CUILIST
#include "cuiList.h"
#include "cuiLabel.h"
#include <iostream>

cui::List::List(const short& width, const short& height, const int& length, const std::string& title,
	const CPrintStyle& style, const CForeGroundColor& foreColor,
	const CBackGroundColor& backColor) : Widget(title, length, style, foreColor, backColor), 
	width(width), height(height), rowAndcol(false)
{
	
}

cui::List::~List()
{
	clear();
}

template<class Container>
void cui::List::pushContainer(const Container& strCs)
{
	for (auto it = strCs.begin(); it != strCs.end(); it++) {
		if (size() >= (width * height))
			return;

		Widget* newLabel = new Label(length, *it);
		push_back(newLabel);
	}
}

void cui::List::pushWidget(Widget* widget)
{
	if (size() >= (width * height))
		return;

	push_back(widget);
}

void cui::List::create(const std::string& str)
{
	if (size() >= (width * height))
		return;

	Widget* newLabel = new Label(length, str);
	push_back(newLabel);
}

void cui::List::clear()
{
	while (size()) {
		auto it = (--end());
		Widget* widget = *it;
		pop_back();

		delete widget;
	}
}

//set/get
void cui::List::setTitle(const std::string& title)
{
	content = title;
}
std::string cui::List::getTitle() const
{
	return content;
}		

void cui::List::setWidth(const int& width)
{
	this->width = width;
}
int cui::List::getWidth() const
{
	return (width * length) + x;
}

void cui::List::setHeight(const int& height)
{
	this->height = height;
}
int cui::List::getHeight() const
{
	return height + y;
}

void cui::List::setRowShow()
{
	this->rowAndcol = false;
}

void cui::List::setColShow()
{
	this->rowAndcol = true;
}

void cui::List::print()
{
	short cuX = 0;
	short cuY = 1;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x, y };
	SetConsoleTextAttribute(handle, foreColor | backColor | style);
	SetConsoleCursorPosition(handle, pos);
	std::cout << content; //print title

	for (auto it = begin(); it != end(); it++) {
		pos = { (short)(cuX * length) + x, cuY + y };
		SetConsoleCursorPosition(handle, pos);
		(*it)->print();

		cuX++;
		if (cuX >= width) {
			cuY++;
			cuX = 0;
		}
	}
}

#endif