#pragma once
#include "cuiData.h"
#include <string>

namespace cui
{
	class Widget {
	protected:
		short x;
		short y;
		int length;
		std::string content;
		CPrintStyle style;
		CPrintDirction dirction;
		CForeGroundColor foreColor;
		CBackGroundColor backColor;

	public:
		Widget(const short& x = 0, const short& y = 0, const std::string& content = "",
			   const CPrintStyle& style = enmStyle_Normal,
			   const CForeGroundColor& foreColor = enmCFC_White,
			   const CBackGroundColor& backColor = enmCBC_Black);

		void setPos(const short& x, const short& y);

		void setX(const short& x);
		short getX() const;

		void setY(const short& y);
		short getY() const;

		void setLength(const int& length);
		int getLength() const;

		void setStyle(const CPrintStyle& style);
		CPrintStyle getStyle() const;

		void setContent(const std::string& content);
		std::string getContent() const;

		void setDirction(const CPrintDirction& dirction);
		CPrintDirction getDirction() const;

		void setForeColor(const CForeGroundColor& foreColor);
		CForeGroundColor getForeColor() const;

		void setBackColor(const CBackGroundColor& foreColor);
		CBackGroundColor getBackColor() const;

		virtual std::string print();
	};
};