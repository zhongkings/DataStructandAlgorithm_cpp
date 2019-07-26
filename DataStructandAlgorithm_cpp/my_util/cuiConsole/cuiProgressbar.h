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
		Widget marchWidget;

	public:
		Progressbar(const float& min, const float& max, const int& length,
			const CPrintStyle& marchstyle = enmStyle_Normal,
			const CForeGroundColor& marchfroeColor = enmCFC_Green,
			const CBackGroundColor& marchbackColor = enmCBC_Black,
			const CPrintStyle& pathstyle = enmStyle_Normal,
			const CForeGroundColor& pathfroeColor = enmCFC_White,
			const CBackGroundColor& pathbackColor = enmCBC_Black);

		virtual ~Progressbar();

		void setMin(const float& min);
		float getMin() const;

		void setMax(const float& max);
		float getMax() const;

		void setChange(const float& value);
		float getChange() const;

		Widget& getPathChars();

		Widget& getMarchChars();

		virtual void print();
	};
};