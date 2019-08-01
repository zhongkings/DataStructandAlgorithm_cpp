#include "cuiWidget.h"
#include <iostream>

cui::Widget::Widget(const std::string& content,
	const CPrintStyle & style, const CForeGroundColor & foreColor, const CBackGroundColor & backColor) :
    content(content), x(0), y(0), length((int)content.size()), style(style), 
	foreColor(foreColor), backColor(backColor)
{

}

cui::Widget::Widget(const std::string& content, const int& length,
	const CPrintStyle& style, const CForeGroundColor& foreColor, const CBackGroundColor& backColor) :
	content(content), x(0), y(0), length(length), style(style),
	foreColor(foreColor), backColor(backColor)
{

}

cui::Widget::~Widget()
{
	
}

void cui::Widget::setPos(const short& x, const short& y)
{
	this->x = x;
	this->y = y;
}

void cui::Widget::setX(const short& x)
{
	this->x = x;
}

short cui::Widget::getX() const
{
	return x;
}

void cui::Widget::setY(const short& y)
{
	this->y = y;
}

short cui::Widget::getY() const
{
	return y;
}

int cui::Widget::getWidth() const
{
	return length;
}

int cui::Widget::getHeight() const
{
	return 0;
}

void cui::Widget::setStyle(const CPrintStyle& style)
{
	this->style = style;
}


void cui::Widget::setContent(const std::string& content)
{
	this->content = content;
	length = (int)content.size();
}

cui::CPrintStyle cui::Widget::getStyle() const
{
	return style;
}

std::string cui::Widget::getContent() const
{
	return content;
}

void cui::Widget::setForeColor(const CForeGroundColor& foreColor)
{
	this->foreColor = foreColor;
}

cui::CForeGroundColor cui::Widget::getForeColor() const
{
	return foreColor;
}

void cui::Widget::setBackColor(const CBackGroundColor& backColor)
{
	this->backColor = backColor;
}

cui::CBackGroundColor cui::Widget::getBackColor() const
{
	return backColor;
}

void cui::Widget::print()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), foreColor | backColor | style);
	std::cout << content;
}