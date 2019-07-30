#pragma once
#include "cuiOut.h"
#include <vector>

namespace cui
{
	class List : public Out, public std::vector<Widget*>
	{
	private:
		short width, height;
		bool rowAndcol;
	public:
		List(const short& width, const short& height, const int& length, const std::string& title,
			 const CPrintStyle& style = enmStyle_Normal, const CForeGroundColor& foreColor = enmCFC_White,
			 const CBackGroundColor& backColor = enmCBC_Black);

		~List();

		void pushVector(const std::vector<std::string>& strVs);
		void pushWidget(Widget* widget);
		void create(const std::string& str);

		void clear();

		//set/get
		void setTitle(const std::string& title);
		std::string getTitle() const;

		void setWidth(const int& width);
		int getWidth() const;

		void setHeight(const int& height);
		int getHeight() const;

		void setRowShow();
		void setColShow();

		virtual void print();
	};
};