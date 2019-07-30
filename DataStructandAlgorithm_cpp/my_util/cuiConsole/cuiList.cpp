#include "cuiList.h"
#include "cuiLabel.h"
cui::List::List(const short& width, const short& height, const int& length, const std::string& title,
	const CPrintStyle& style = enmStyle_Normal, const CForeGroundColor& foreColor = enmCFC_White,
	const CBackGroundColor& backColor = enmCBC_Black) : Widget(title, length, style, foreColor, backColor), 
	width(width), height(height), rowAndcol(false)
{
	
}

cui::List::~List()
{
	clear();
}

void cui::List::pushVector(const std::vector<std::string>& strVs)
{
	for (auto it = strVs.begin(); it != strVs.end(); it++) {
		Widget* newLabel = new Label(length, *it);
		push_back(newLabel);
	}
}

void cui::List::pushWidget(Widget* widget)
{
	push_back(widget);
}

void cui::List::create(const std::string& str)
{
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
	return width;
}

void cui::List::setHeight(const int& height)
{
	this->height = height;
}
int cui::List::getHeight() const
{
	return height;
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
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, foreColor | backColor | style);
	std::cout << content; //print title

}
