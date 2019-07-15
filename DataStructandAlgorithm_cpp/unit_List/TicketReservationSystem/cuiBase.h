#pragma once
#include <list>
#include <string>
#include "cuiWidget.h"

namespace cui
{
	class Base : public std::list<Widget>
	{
	private:
		static bool init;
		Widget* inWidget;
		int Xmax, Ymax;

		iterator checkPosIsUse(Widget& widget);

		iterator checkPosIsUse(int x, int y);

		class baseListSortOperate {
		public:
			//”√”⁄baseList≈≈–Ú
			bool operator()(const Widget& elem1, const Widget& elem2) const;
		};

	public:
		Base(int Xmax, int Ymax);

		std::istream& blockInput(int x, int y, std::istream& in, int color = White, int style = normalStyle);
		void create(int x, int y, Widget& widget);
		void create(int x, int y, std::string content);

		void show();

		COORD intToCooRD(int x, int y);

		Widget& getWidget(int x, int y);

		Widget& operator[] (COORD pos);

		static void clear();
	};
}
