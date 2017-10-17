#pragma once
#include "vec3.h"
union mat3
{
	float m[9];
	float mm[3][3];
	vec3 c[3];

	vec3 &operator[](size_t idx);//column accessor
	const vec3 &operator[](size_t idx) const;

	static mat3 identity(); //creates and returns an identity matrix.
};

mat3 operator+(const mat3 &A, const mat3 &B);//not reaaallly used
mat3 operator-(const mat3 &A, const mat3 &B);//not reaaaalllly used
mat3 operator*(const mat3 &A, const mat3 &B);//combine transformation
mat3 operator*(const mat3 &A, const vec3 &V);//apply a transformation

mat3 transpose(const mat3 &A);//flip the rows and columns

//Unknowns
float determinant(const mat3 &A);
mat3 inverse(const mat3 &A);