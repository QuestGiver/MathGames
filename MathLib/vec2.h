#pragma once

//internal variables share mem space,
//this is the size of the largest element, be it a struct or an array
union vec2
{
	//access by array
	float v[2];

	//access by individual component
	struct { float x, y; };

	// access by unidentified index
	float &operator[](size_t idx);
	float operator[](size_t idx) const;


};

//&lhs = left hand side and &rhs = right hand side
vec2 operator+(const vec2 &lhs, const vec2 &rhs);

vec2 &operator+=(vec2 &lhs, const vec2 &rhs);

bool operator==(const vec2 &lhs, const vec2 &rhs);

bool operator!=(const vec2 &lhs, const vec2 &rhs);

vec2 operator-(const vec2 lhs, const vec2 rhs);

vec2 operator*(const vec2 lhs, const float rhs);

vec2 operator*(const float lhs, const vec2 rhs);

vec2 operator/(const vec2 lhs, const float rhs);

vec2 operator/(const float rhs,const vec2 lhs);

vec2 operator-(const vec2 &rhs);

bool operator!=(const vec2 lhs, const vec2 rhs);

vec2 &operator-=(vec2 &lhs, const vec2 &rhs);

vec2 &operator*=(vec2 &lhs, const float &rhs);

vec2 &operator*=(const float &lhs, vec2 &rhs);

vec2 &operator/=(vec2 & lhs, const float &rhs);

vec2 &operator/=(const float &lhs, vec2 &rhs);

