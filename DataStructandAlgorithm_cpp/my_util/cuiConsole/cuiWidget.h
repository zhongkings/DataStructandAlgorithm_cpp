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
		CForeGroundColor foreColor;
		CBackGroundColor backColor;

	public:
		Widget(const std::string& content = "",
			   const CPrintStyle& style = enmStyle_Normal,
			   const CForeGroundColor& foreColor = enmCFC_White,
			   const CBackGroundColor& backColor = enmCBC_Black);

		Widget(const std::string& content, const int &length,
			const CPrintStyle& style = enmStyle_Normal,
			const CForeGroundColor& foreColor = enmCFC_White,
			const CBackGroundColor& backColor = enmCBC_Black);

		void setPos(const short& x, const short& y);

		void setX(const short& x);
		short getX() const;

		void setY(const short& y);
		short getY() const;

		int getLength() const;

		void setStyle(const CPrintStyle& style);
		CPrintStyle getStyle() const;

		void setContent(const std::string& content);
		std::string getContent() const;

		void setForeColor(const CForeGroundColor& foreColor);
		CForeGroundColor getForeColor() const;

		void setBackColor(const CBackGroundColor& backColor);
		CBackGroundColor getBackColor() const;

		virtual std::string print();
	};
};