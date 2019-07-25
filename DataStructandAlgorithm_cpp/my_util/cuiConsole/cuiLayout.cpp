#include "cuiLayout.h"
#include "cuiInput.h"
#include <iostream>

cui::Layout::Layout(int width, int height, HANDLE handle) :
width(width), height(height), handle(handle), spaceChar(" | "), inWidget(new Input()), cuMax_X(0), cuMax_Y(0)
{

}
 
cui::Layout::~Layout()
{
	if (inWidget != NULL)
		delete inWidget;

	auto it = begin();
	for (it; it != end(); it++) {
		if ((*it) != NULL)
			delete (*it);
	}

	std::list<Widget*>::clear();
	posMaps.clear();
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

	Vec2 vec(x, y);
	posMaps.insert(std::make_pair(vec, cet));
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

	//��ɾ���ĵ����ֵ����Ҫ���²������ֵ
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

void cui::Layout::nextPage()
{

}

void cui::Layout::prevPage()
{

}


void cui::Layout::clear()
{
	SetConsoleTextAttribute(handle, enmCFC_White | enmCBC_Black | enmStyle_Normal);
	system("cls");
}

void cui::Layout::print()
{
	auto posIt = posMaps.begin();
	auto it = begin(); //list
	int cuInterval = 0;
	int cuY = 0; //����Ƿ�һ��
	for (posIt; posIt != posMaps.end() && it != end(); posIt++) {
		Vec2 vec = posIt->first;
		if (cuY != vec.y) {
			cuInterval = 0;
			cuY = vec.y;
		}
		COORD pos = { vec.x + cuInterval, vec.y };

		switch (posIt->second) {
		case enmCET_out:
			(*it)->setX(pos.X);
			(*it)->setY(pos.Y);
			SetConsoleCursorPosition(handle, pos);
			std::cout << (*it)->print();
			cuInterval += (*it)->getLength();

			//����Ƿ�����X���������Ǿ���Ӽ����
			if (pos.X < cuMax_X) {
				std::cout << spaceChar.print();
				cuInterval += spaceChar.getLength();
			}

			it++;
			break;
		case enmCET_in:
			inWidget->setX(pos.X);
			inWidget->setY(pos.Y);
			//���ѭ������ҪoutLs����
			break;
		}

		std::cout << std::flush; //ˢ��
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

cui::Widget& cui::Layout::getSpaceChar()
{
	return spaceChar;
}