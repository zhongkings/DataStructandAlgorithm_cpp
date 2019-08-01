#include "cuiProgressbar.h"
#include <iostream>

cui::Progressbar::Progressbar(const float& min, const float& max, const int& length,
	const CPrintStyle& marchstyle,
	const CForeGroundColor& marchfroeColor,
	const CBackGroundColor& marchbackColor,
	const CPrintStyle& pathstyle,
	const CForeGroundColor& pathfroeColor,
	const CBackGroundColor& pathbackColor) :
	minValue(min), maxValue(max), changeValue(maxValue / 2),
    Widget("-", length, pathstyle, pathfroeColor, pathbackColor), marchWidget(">", marchstyle, marchfroeColor, marchbackColor)
{
	
}

cui::Progressbar::~Progressbar()
{

}

void cui::Progressbar::setMin(const float& min)
{
	this->minValue = min;
}

float cui::Progressbar::getMin() const
{
	return minValue;
}

void cui::Progressbar::setMax(const float& max)
{
	this->maxValue = max;
}

float cui::Progressbar::getMax() const
{
	return maxValue;
}

void cui::Progressbar::setChange(const float& value)
{
	if (value > maxValue)
		changeValue = maxValue;

	this->changeValue = value;
}

float cui::Progressbar::getChange() const
{
	return changeValue;
}

cui::Widget& cui::Progressbar::getPathChars()
{
	return *this;
}

cui::Widget& cui::Progressbar::getMarchChars()
{
	return marchWidget;
}

void cui::Progressbar::print()
{
	float percentage = changeValue / maxValue;
	float printCount = percentage * (float)length;
	for (int i = 0; i < length; i++) {
		if (i < printCount) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), marchWidget.getForeColor() | marchWidget.getBackColor() | marchWidget.getStyle());
			std::cout << marchWidget.getContent();
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), foreColor | backColor | style);
			std::cout << content;
		}
	}
}