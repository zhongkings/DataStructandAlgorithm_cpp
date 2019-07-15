#pragma once
#include "cuiData.h"
#include <string>

namespace cui
{
	class Widget
	{
	protected:
		std::string content;
		int color;
		int style;
		int curTextInterval;
		bool show;
		COORD pos;
	public:
		 //Input
		 Widget(COORD pos, int color = White, int style = normalStyle, bool show = false);
		 Widget(int x, int y, int color = White,int style = normalStyle, bool show = false);
		 //Item
		 Widget(COORD pos, std::string content, int color = White, int style = normalStyle, bool show = true);
		 Widget(int x, int y, std::string content, int color = White, int style = normalStyle, bool show = true);

		 void setContent(std::string content);
		 std::string& getContent();

		 int length() const;


		 void setPos(COORD pos);
		 void setPos(int x, int y);
		 COORD getPos();

		 void setX(int x);
		 int getX();

		 void setY(int y);
		 int getY();

		 void setShow(bool show);
		 bool getShow() const;

		 void setColor(int color);
		 int getColor() const;

		 void setStyle(int style);
		 int getStyle() const;

		 std::ostream& print(std::ostream& os);

		 friend bool operator == (const Widget& w1, const Widget& w2);

		 friend bool operator == (const COORD& c1, const COORD& c2);

		 friend std::ostream& operator << (std::ostream& os, Widget& widget);

		 friend class Base;
	};
}
