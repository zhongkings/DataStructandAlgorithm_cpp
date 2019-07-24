#pragma once
#include "cuiOut.h"

namespace cui
{
	class Progressbar : public Out
	{
	private:
		int min;
		int max;
		int change;

	public:
		Progressbar(const int& min, const int& max, const int& change,
			        const CPrintStyle& style = enmStyle_Normal,
			        const CForeGroundColor& foreColor = enmCFC_White,
			        const CBackGroundColor& backColor = enmCBC_Black);

		void setMin(const int& min);
		int getMin() const;

		void setMax(const int& max);
		int getMax() const;

		void setChange(const int& change);
		int getChange() const;

		virtual std::string print();
	};
};