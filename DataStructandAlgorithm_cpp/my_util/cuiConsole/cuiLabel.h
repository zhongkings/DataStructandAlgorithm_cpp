#pragma once
#include "cuiOut.h"

namespace cui
{
	class Label : public Out
	{
	public:
		Label(const std::string& content,
			const CPrintStyle& style = enmStyle_Normal,
			const CForeGroundColor& foreColor = enmCFC_White,
			const CBackGroundColor& backColor = enmCBC_Black);

	};
};