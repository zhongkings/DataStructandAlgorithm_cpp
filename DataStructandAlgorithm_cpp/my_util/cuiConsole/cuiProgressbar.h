#pragma once
#include "cuiOut.h"

namespace cui
{
	class Progressbar : public Out
	{
	private:
		float minValue;
		float maxValue;
		float changeValue;
		std::string marchChars;

	public:
		Progressbar(const float& min, const float& max, const int& length,
			const CPrintStyle& style = enmStyle_Normal,
			const CForeGroundColor& froeColor = enmCFC_HighWhite,
			const CBackGroundColor& backColor = enmCBC_Black);

		void setMin(const float& min);
		float getMin() const;

		void setMax(const float& max);
		float getMax() const;

		void setChange(const float& value);
		float getChange() const;

		void setPathChars(const std::string& pathChars);
		std::string getPathChars(const std::string& pathChars) const;

		void setMarchChars(const std::string& marchChars);
		std::string getMarchChars(const std::string& marchChars) const;

		std::string print();
	};
};