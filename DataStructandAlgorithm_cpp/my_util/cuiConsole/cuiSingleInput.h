#pragma once
#include "cuiIn.h"

namespace cui
{
	class SingleInput : public In
	{
	public:
		SingleInput(const CPrintStyle& style = enmStyle_Normal,
			        const CForeGroundColor& foreColor = enmCFC_White,
			        const CBackGroundColor& backColor = enmCBC_Black);

		std::string in();

		void setIstream(const std::istream& is);
		std::istream getIstream() const;
	};
};