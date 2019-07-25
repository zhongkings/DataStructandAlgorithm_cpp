#pragma once
#include "cuiIn.h"

namespace cui
{
	class Input : public In
	{
	public:
		Input(const CPrintStyle& style = enmStyle_Normal,
			  const CForeGroundColor& foreColor = enmCFC_White,
			  const CBackGroundColor& backColor = enmCBC_Black);

		std::string in();
	};
};