#pragma once
#include "cuiWidget.h"

namespace cui
{
	class In : virtual public Widget
	{
	public:
		virtual ~In() {}
		virtual std::string in() { return ""; }
	};
};