#pragma once
#include "cuiWidget.h"

namespace cui
{
	class In : virtual public Widget
	{
	public:
		virtual std::string in();
	};
};