#pragma once
#include "cuiWidget.h"

namespace cui
{
	class Input : public Widget
	{
	public:
		Input(int x, int y, int color = White, int format = lineasStyle);

		std::istream& blockBegin(std::istream& in);
		std::istream& Begin(std::istream& in);
	};
};