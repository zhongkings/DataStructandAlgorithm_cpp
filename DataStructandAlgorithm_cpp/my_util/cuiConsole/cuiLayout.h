#pragma once
#include "cuiWidget.h"
#include "cuiIn.h"
#include "cuiVec2.h"
#include <vector>
#include <map>

namespace cui
{
	class Layout : public Widget, public std::vector<Widget*>
	{
	protected:
		std::map<Vec2, CElementType> posMaps;
		int width, height;
		int cuMax_X, cuMax_Y;
		In* inWidget;
		HANDLE handle;

	public:
		Layout(int width, int height, HANDLE handle);
		Layout(const std::string & title, int width, int height, HANDLE handle);
		~Layout();

		void install(const int& x, const int& y, const CElementType& cet);

		void unload(const int& x, const int& y);

		void clear();

		void clearBuffer();

		virtual void print();


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
	};
};