#include "cuiLayout.h"
#include "cuiInput.h"
#include <iostream>

cui::Layout::Layout(int width, int height, HANDLE handle) :
width(width), height(height), handle(handle), inWidget(new Input()), cuMax_X(0), cuMax_Y(0)
{

}
 
cui::Layout::~Layout()
{
	
}

void cui::Layout::install(const int& x, const int& y, const CElementType& cet)
{
	if (x < 0 || y < 0)
		return;
	if (x >= width || y >= height)
		return;
	if (x > cuMax_X)
		cuMax_X = x;
	if (y > cuMax_Y)
		cuMax_Y = y;

	//看看是否有同样的位置
	auto posMapit = posMaps.begin();
	for (posMapit; posMapit != posMaps.end(); posMapit++) {
		if (posMapit->first.x == x && posMapit->first.y == y)
			break;
	}

	if (posMapit != posMaps.end()) {
		posMapit->second = cet;
	}
	else {
		Vec2 vec(x, y);
		posMaps.insert(std::make_pair(vec, cet)); //没有就添加一个
	}
}

void cui::Layout::unload(const int& x, const int& y)
{
	if (x < 0 || y < 0)
		return;
	if (x >= width || y >= height)
		return;
	if (x > cuMax_X || y > cuMax_X)
		return;

	auto it = posMaps.begin();
	for (it; it != posMaps.end(); it++) {
		Vec2 vec = it->first;

		if (vec.x == x && vec.y == y)
			break;
	}

	if (it != posMaps.end())
		posMaps.erase(it);
	else
		return;

	//当删除的等最大值，就要重新查找最大值
	if (x == cuMax_X || y == cuMax_Y) {
		cuMax_X = 0;
		cuMax_Y = 0;
		it = posMaps.begin();
		for (it; it != posMaps.end(); it++) {
			Vec2 vec = it->first;
			if (vec.x > cuMax_X)
				cuMax_X = vec.x;
			if (vec.y > cuMax_Y)
				cuMax_Y = vec.y;
		}
	}
}

void cui::Layout::clear()
{
	cuMax_X = 0;
	cuMax_Y = 0;

	while (size()) {
		auto it = (--end());
		Widget* widget = *it;
		pop_back();

		delete widget;
	}

	posMaps.clear();
}

void cui::Layout::clearBuffer()
{
	SetConsoleTextAttribute(handle, enmCFC_White | enmCBC_Black | enmStyle_Normal);
	system("cls");
}

void cui::Layout::print()
{
	auto posIt = posMaps.begin();
	auto it = begin();  //list
	int cuInterval = 0; //检查字符串的长度
	int cuY = 0; //检查是否换一行
	bool ifaddspaceChar = true;

	for (posIt; posIt != posMaps.end() && it != end(); posIt++) {
		Vec2 vec = posIt->first;

		if (cuY != vec.y) {
			cuInterval = 0;
			cuY = vec.y;
		}

		COORD pos = { vec.x + cuInterval, vec.y };
		switch (posIt->second) {
		case enmCET_out:
			(*it)->setPos(pos.X, pos.Y);
			SetConsoleCursorPosition(handle, pos);

			//打印widget
			(*it)->print();
			cuInterval += (*it)->getLength();
			it++;
			break;

		case enmCET_in:
			inWidget->setX(pos.X);
			inWidget->setY(pos.Y);
			//这次for不需要outLs迭代
			break;
		}

		std::cout << std::flush; //刷新
	}
}

std::string cui::Layout::select()
{
	COORD pos = { inWidget->getX(), inWidget->getY() };
	SetConsoleCursorPosition(handle, pos);
	SetConsoleTextAttribute(handle, inWidget->getForeColor() | inWidget->getBackColor() | inWidget->getStyle());
	return inWidget->in();
}

//set/get
void cui::Layout::setIn(In* in)
{
	if (this->inWidget != NULL)
		delete this->inWidget;

	this->inWidget = in;
}

cui::In cui::Layout::getIn() const
{
	return *inWidget;
}

void cui::Layout::setHandle(HANDLE handle)
{
	this->handle = handle;
}

HANDLE cui::Layout::getHandle() const
{
	return handle;
}

void cui::Layout::setWidth(const int& width)
{
	this->width = width;
}

int cui::Layout::getWidth() const
{
	return width;
}

void cui::Layout::setHeight(const int& height)
{
	this->height = height;
}

int cui::Layout::getHeight() const
{
	return height;
}

int cui::Layout::getcuMax_X() const
{
	return cuMax_X;
}

int cui::Layout::getcuMax_Y() const
{
	return cuMax_Y;
}