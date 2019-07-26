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
		
		virtual ~SingleInput();

		std::string in();
	};
};