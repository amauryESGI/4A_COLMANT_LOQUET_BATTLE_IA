#ifndef __UTIL_HPP__
#define __UTIL_HPP__
#include <algorithm>
class Util
{
public:
	static float width;
	static float heigth;
	static float clip(float n, float limit)
	{
		return std::max(0.f, std::min(n, limit));
	}
};
#endif