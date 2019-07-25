#pragma once
#include "cuiOut.h"
#include "cuiIn.h"
#include "cuiVec2.h"
#include <list>
#include <map>
#include <tuple>

namespace cui
{
	class Layout : public std::list<Widget*>
	{
	protected:
		typedef std::tuple<int, int> IIple;
		std::map<Vec2, CElementType> posMaps;

		int width, height;
		int cuMax_X, cuMax_Y;
		Widget spaceChar;
		In* inWidget;
		HANDLE handle;

	public:
		Layout(int width, int height, HANDLE handle);
		~Layout();

		void install(const int& x, const int& y, const CElementType& cet);

		void unload(const int& x, const int& y);

		void nextPage();

		void prevPage();

		void clear();

		void print();

		std::string select();

		// set/get
		void setIn(In* in);
		In getIn() const;

		void setHandle(HANDLE handle);
		HANDLE getHandle() const;

		void setWidth(const int& width);
		int getWidth() const;

		void setHeight(const int& height);
		int getHeight() const;

		int getcuMax_X() const;

		int getcuMax_Y() const;

		Widget& getSpaceChar();
	};
};