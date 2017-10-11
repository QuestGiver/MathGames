#include "vec3.h"

#include "cmath"
#include <climits>
#include <cfloat>
vec3 operator+(const vec3 & lhs, const vec3 & rhs)
{
	//vec2 result;
	//result.x = lhs.x + rhs.x;
	//result.y = lhs.y + lhs.y;

	//return result;

	return{ lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z };


}

vec3 & operator+=(vec3 & lhs, const vec3 & rhs)
{
	lhs = lhs + rhs;
	return lhs;
}

bool operator==(const vec3 & lhs, const vec3 &rhs)
{
	//FLT_EPSILON is the smallest a float can be be
	if (abs(lhs.x - rhs.x) < FLT_EPSILON && abs(lhs.y - rhs.y) < FLT_EPSILON && abs(lhs.z - rhs.z) < FLT_EPSILON)
	{
		return true;
	}
	return false;
}

bool operator!=(const vec3 & lhs, const vec3 & rhs)
{
	return !(lhs == rhs);
}

vec3 operator-(const vec3 lhs, const vec3 rhs)
{
	return{ lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z };
}

vec3 operator*(const vec3 lhs, const float rhs)
{
	return{ lhs.x * rhs, lhs.y * rhs, lhs.z * rhs };
}

vec3 operator*(const float lhs, const vec3 rhs)
{
	return{ lhs * rhs.x, lhs * rhs.y, lhs * rhs.z };
}

vec3 operator/(const vec3 lhs, const float rhs)
{
	return{ lhs.x / rhs, lhs.y / rhs, lhs.z / rhs };
}

vec3 operator/(const float rhs, const vec3 lhs)
{
	return{ rhs / lhs.x,rhs / lhs.y, rhs /lhs.z };
}

vec3 operator-(const vec3 & rhs)
{
	return{ rhs.x * -1, rhs.y * -1, rhs.z * -1 };
}

bool operator!=(const vec3 lhs, const vec3 rhs)
{
	return !(lhs == rhs);
}

vec3 &operator-=(vec3 & lhs, const vec3 & rhs)
{
	lhs = lhs - rhs;
	return lhs;
}

vec3 & operator*=(vec3 & lhs, const float & rhs)
{
	lhs = lhs * rhs;
	return lhs;
}

vec3 & operator*=(const float & lhs, vec3 & rhs)
{
	rhs = rhs * lhs;
	return rhs;
}

vec3 & operator/=(vec3 & lhs, const float & rhs)
{
	lhs = lhs / rhs;
	return lhs;
}

vec3 & operator/=(const float & lhs, vec3 & rhs)
{
	rhs = rhs / lhs;
	return rhs;
}
