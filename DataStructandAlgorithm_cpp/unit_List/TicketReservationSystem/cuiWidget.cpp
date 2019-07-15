#include "cuiWidget.h"
#include <ostream>


namespace cui
{
	Widget::Widget(COORD pos, int color, int style, bool show) :
	pos(pos), color(color), style(style), show(show), curTextInterval(0)
	{

	}

	Widget::Widget(int x, int y, int color, int style, bool show) :
	color(color), style(style), show(show), curTextInterval(0)
	{
		pos = { (short)x,(short)y };
	}

	Widget::Widget(COORD pos, std::string content, int color, int style, bool show) :
	pos(pos), content(content), color(color), style(style), show(show), curTextInterval(0)
	{

	}
	Widget::Widget(int x, int y, std::string content, int color, int style, bool show) :
	content(content), color(color), style(style), show(show), curTextInterval(0)
	{
		pos = { (short)x,(short)y };
	}

	void Widget::setContent(std::string content) 
	{
		this->content = content;
	}
	
	std::string& Widget::getContent()
	{
		return content;
	}

	void Widget::setPos(int x, int y)
	{
		pos = { (short)x,(short)y };
	}

	void Widget::setPos(COORD pos)
	{
		this->pos = pos;
	}

	COORD Widget::getPos()
	{
		return pos;
	}

	void Widget::setX(int x)
	{
		pos.X = x;
	}

	int Widget::getX()
	{
		return pos.X;
	}

	void Widget::setY(int y)
	{
		pos.Y = y;
	}

	int Widget::getY()
	{
		return pos.Y;
	}

	int Widget::length() const
	{
		return content.size();
	}

	void Widget::setShow(bool show)
	{
		this->show = show;
	}

	bool Widget::getShow() const
	{
		return show;
	}

	void Widget::setColor(int color)
	{
		this->color = color;
	}

	int Widget::getColor() const
	{
		return color;
	}

	void Widget::setStyle(int style)
	{
		this->style = style;
	}

	int Widget::getStyle() const
	{
		return style;
	}

	std::ostream& Widget::print(std::ostream& os)
	{
		SetConsoleTextAttribute(handle, color | style);
		os << content << std::endl;
		//»Ö¸´Ä¬ÈÏÑùÊ½
		SetConsoleTextAttribute(handle, White | normalStyle);

		return os;
	}

	bool operator == (const Widget& w1, const Widget& w2)
	{
		if (w1.content != w2.content)
			return false;
		if (!(w1.pos == w2.pos))
			return false;
		if (w1.color != w2.color && w1.style != w2.style)
			return false;

		return true;
	}

	bool operator == (const COORD& c1, const COORD& c2)
	{
		return c1.X != c2.X && c1.Y != c2.Y;
	}

	std::ostream& operator << (std::ostream& os, Widget& widget)
	{
		return widget.print(os);
	}
}
