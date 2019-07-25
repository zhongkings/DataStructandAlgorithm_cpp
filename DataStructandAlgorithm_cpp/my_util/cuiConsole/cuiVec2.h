#pragma once
#include <tuple>

namespace cui
{
	class Vec2
	{
	public:
		short x;
		short y;

		Vec2(const short& x, const short& y) : x(x), y(y)
		{

		}

		bool operator < (const Vec2& vec2) const
		{
			if (y > vec2.y)
				return false;
			if (y < vec2.y)
				return true;

			if (x > vec2.x)
				return false;
			if (x < vec2.x)
				return true;

			return true;
		}
	};
};