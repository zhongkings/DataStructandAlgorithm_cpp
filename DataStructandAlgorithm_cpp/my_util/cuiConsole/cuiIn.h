#pragma once
#include "cuiWidget.h"
#include <istream>

namespace cui
{
	class In : virtual public Widget
	{
	protected:
		std::istream& is;

	public:
		std::string in();

		void setIstream(const std::istream& is);
		std::istream getIstream() const;
	};
};