#include "cuiBase.h"
#include <iostream>
#include <istream>

namespace cui
{
	//Baselist Sort operate
    bool Base::baseListSortOperate::operator()(const Widget& elem1, const Widget& elem2) const
	{
		if (elem1.pos.Y < elem2.pos.Y)
			return true;
		else if (elem1.pos.Y > elem2.pos.Y)
			return false; //如果相等继续判断下面

		if (elem1.pos.X < elem2.pos.X)
			return true;
		else if (elem1.pos.X > elem2.pos.X)
			return false;

		return false;
	}



	//Base
	bool Base::init = true;
	HANDLE handle;
	CONSOLE_SCREEN_BUFFER_INFO csbInfo;

	Base::Base(int Xmax, int Ymax) : 
	Xmax(Xmax), Ymax(Ymax)
	{
		//初始化in接口，设置为不显示
		inWidget = new Widget(0, 0, White, normalStyle, false);

		if (!init)
			return;

		init = false;
		handle = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(handle, &csbInfo);
	}

	std::istream& Base::blockInput(int x, int y, std::istream& in, int color, int style)
	{
		//设置
		inWidget->pos = { (short)x, (short)y };
		SetConsoleCursorPosition(handle, inWidget->pos);
		SetConsoleTextAttribute(handle, color | style);

		in >> inWidget->content;
		//恢复默认样式
		SetConsoleTextAttribute(handle, White | normalStyle);

		return in;
	}

	void Base::create(int x, int y, Widget& widget)
	{
		widget.pos = { (short)x,(short)y };
		iterator find = checkPosIsUse(widget);

		if (find == end()) {
			push_back(widget);
			sort(baseListSortOperate()); //变动位置需要排序
		}
		else
			*find = widget;
	}

	void Base::create(int x, int y, std::string content)
	{
		Widget widget(x, y, content);
		iterator find = checkPosIsUse(widget);

		if (find == end()) {
			push_back(widget);
			sort(baseListSortOperate()); //变动位置需要排序
		}
		else
			*find = widget;
	}

	void Base::show()
	{
		iterator preIt = begin();
		int countTextInterval = 0;

		for (iterator it = begin(); it != end(); it++)
		{
			//false的直接跳过
			if (!it->show)
				continue;

			//把preIt 设置为 it 的prev
			if (it != begin()) {
				preIt = std::prev(it);
				if (it->pos.Y == preIt->pos.Y) {
					countTextInterval += preIt->length();
					it->curTextInterval = countTextInterval;
				}
				else //y不同就代表换行。
					countTextInterval = 0;
			}

			COORD pos = { it->pos.X + it->curTextInterval, it->pos.Y };
			SetConsoleCursorPosition(handle, pos);
			std::cout << *it;
			
			//恢复默认
			pos = { 0, 0 };
			SetConsoleCursorPosition(handle, pos);

		}
	}

	COORD Base::intToCooRD(int x, int y)
	{
		COORD pos = { x,y };

		return pos;
	}

	Widget& Base::getWidget(int x, int y)
	{
		return *checkPosIsUse(x, y);
	}

	Widget& Base::operator[] (COORD pos)
	{
		return getWidget(pos.X, pos.Y);
	}

	std::list<Widget>::iterator Base::checkPosIsUse(Widget& widget)
	{
		if (widget.pos.X >= Xmax)
			widget.pos.X = Xmax - 1;
		if (widget.pos.Y >= Ymax)
			widget.pos.Y = Ymax - 1;

		for (iterator it = begin(); it != end(); it++) {
			if (it->pos.X == widget.pos.X && it->pos.Y == widget.pos.Y)
				return it;
		}

		return end();
	}

	std::list<Widget>::iterator Base::checkPosIsUse(int x, int y)
	{
		for (iterator it = begin(); it != end(); it++) {
			if (it->pos.X == x && it->pos.Y == y)
				return it;
		}

		return end();
	}

	void Base::clear()
	{
		system("cls");
	}

};