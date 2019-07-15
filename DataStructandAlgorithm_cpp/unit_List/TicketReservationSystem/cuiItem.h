#pragma once
#include "cuiWidget.h"

namespace cui
{
	class Item : public Widget
	{
	public:
		Item(int x, int y, std::string content, int color = White, int format = normalStyle);
	};
};