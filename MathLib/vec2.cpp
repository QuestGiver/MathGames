#include "vec2.h"
#include "cmath"
#include <climits>
#include <cfloat>
#include"mathUtils.h"
vec2 operator+(const vec2 & lhs, const vec2 & rhs)
{
	//vec2 result;
	//result.x = lhs.x + rhs.x;
	//result.y = lhs.y + lhs.y;

	//return result;

	return{lhs.x + rhs.x, lhs.y + rhs.y};


}

vec2 & operator+=(vec2 & lhs, const vec2 & rhs)
{
	lhs = lhs + rhs;
	return lhs;
}

bool operator==(const vec2 & lhs, const vec2 &rhs)
{
	//FLT_EPSILON is the smallest a float can be be
	if (abs(lhs.x - rhs.x) < EPSILON && abs(lhs.y - rhs.y) < EPSILON)
	{
		return true;
	}
	return false;
}

bool operator!=(const vec2 & lhs, const vec2 & rhs)
{
	return !(lhs == rhs);
}

vec2 operator-(const vec2 lhs, const vec2 rhs)
{
	return{lhs.x - rhs.x, lhs.y - rhs.y};
}

vec2 operator*(const vec2 lhs, const float rhs)
{
	return{lhs.x * rhs, lhs.y * rhs};
}

vec2 operator*(const float lhs, const vec2 rhs)
{
	return{lhs * rhs.x, lhs * rhs.y};
}

vec2 operator/(const vec2 lhs, const float rhs)
{
	return{ lhs.x/rhs, lhs.y/rhs };
}

vec2 operator/( const float rhs, const vec2 lhs)
{
	return{ rhs/ lhs.x,rhs / lhs.y  };
}

vec2 operator-(const vec2 & rhs)
{
	return{rhs.x * -1, rhs.y * -1};
}

bool operator!=(const vec2 lhs, const vec2 rhs)
{
	return{lhs.x != rhs.x ? true : false && lhs.y != rhs.y ? true : false };
}

vec2 &operator-=(vec2 & lhs, const vec2 & rhs)
{
	lhs = lhs - rhs;
	return lhs;
}

vec2 & operator*=(vec2 & lhs, const float & rhs)
{
	lhs = lhs * rhs;
	return lhs;
}

vec2 & operator*=(const float & lhs, vec2 & rhs)
{
	rhs = rhs * lhs;
	return rhs;
}

vec2 & operator/=(vec2 & lhs, const float & rhs)
{
	lhs = lhs / rhs;
	return lhs;
}

vec2 & operator/=(const float & lhs, vec2 & rhs)
{
	rhs = rhs / lhs;
	return rhs;
}


float & vec2::operator[](size_t idx)
{
	return v[idx];
}

float vec2::operator[](size_t idx) const
{
	return v[idx];
}

vec2 clamp(const vec2 &a_min, const vec2 &a_val, const vec2 &a_max)
{
	return max(a_min, min(a_val, a_max));
}

vec2 snap(const vec2 &a_min, const vec2 &a_val, const vec2 &a_max)
{
	return vec2{ snap(a_min.x, a_val.x, a_max.x),
		snap(a_min.y, a_val.y, a_max.y) };
}
