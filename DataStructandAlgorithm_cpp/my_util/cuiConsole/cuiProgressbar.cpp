#include "cuiProgressbar.h"

cui::Progressbar::Progressbar(const float& min, const float& max, const int& length,
	const CPrintStyle& style,
	const CForeGroundColor& froeColor,
	const CBackGroundColor& backColor) : 
	minValue(min), maxValue(max), changeValue(maxValue / 2),
    Widget("-", length, style, froeColor, backColor), marchChars(">")
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

void cui::Progressbar::setPathChars(const std::string& pathChars)
{
	this->content = pathChars;
}

std::string cui::Progressbar::getPathChars(const std::string& pathChars) const
{
	return content;
}

void cui::Progressbar::setMarchChars(const std::string& marchChars)
{
	this->marchChars = marchChars;
}

std::string cui::Progressbar::getMarchChars(const std::string& marchChars) const
{
	return marchChars;
}


std::string cui::Progressbar::print()
{
	std::string str;
	float percentage = changeValue / maxValue;
	float printCount = percentage * (float)length;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), foreColor | backColor | style);
	for (int i = 0; i < length; i++) {
		if (i < printCount)
			str.append(marchChars);
		else
			str.append(content);
	}

	return str;
}