#pragma once
//internal variables share mem space,
//this is the size of the largest element, be it a struct or an array
union vec3
{
	//access by array
	float v[3];

	//access by individual component
	struct { float x, y, z; };
};

//&lhs = left hand side and &rhs = right hand side
vec3 operator+(const vec3 &lhs, const vec3 &rhs);

vec3 &operator+=(vec3 &lhs, const vec3 &rhs);

bool operator==(const vec3 &lhs, const vec3 &rhs);

bool operator!=(const vec3 &lhs, const vec3 &rhs);

vec3 operator-(const vec3 lhs, const vec3 rhs);

vec3 operator*(const vec3 lhs, const float rhs);

vec3 operator*(const float lhs, const vec3 rhs);

vec3 operator/(const vec3 lhs, const float rhs);

vec3 operator/(const float rhs, const vec3 lhs);

vec3 operator-(const vec3 &rhs);

bool operator!=(const vec3 lhs, const vec3 rhs);

vec3 &operator-=(vec3 &lhs, const vec3 &rhs);

vec3 &operator*=(vec3 &lhs, const float &rhs);

vec3 &operator*=(const float &lhs, vec3 &rhs);

vec3 &operator/=(vec3 & lhs, const float &rhs);

vec3 &operator/=(const float &lhs, vec3 &rhs);