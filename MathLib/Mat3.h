#pragma once
#include "vec3.h"
#include"vec2.h"
union mat3
{	
	vec3 c[3];
	float m[9];
	float mm[3][3];


	vec3 &operator[](size_t idx);//column accessor
	const vec3 &operator[](size_t idx) const;

	static mat3 identity(); //creates and returns an identity matrix.
	static mat3 zero();
};

bool operator==(const mat3 &A, const mat3 &B);

mat3 operator+(const mat3 &A, const mat3 &B);//not reaaallly used
mat3 operator-(const mat3 &A, const mat3 &B);//not reaaaalllly used

//A*I ==A
mat3 operator*(const mat3 &A, const mat3 &B);//combine transformation
vec3 operator*(const mat3 &A, const vec3 &V);//apply a transformation

//I(T) == A
mat3 transpose(const mat3 &A);//flip the rows and columns

//Unknowns
float determinant(const mat3 &A);
mat3 inverse(const mat3 &A);

//Translations
//[x 0 0]
//[0 y 0]
//[0 0 1]
mat3 translate (const vec2 &t);

//scale
//[x 0 0]
//[0 y 0]
//[0 0 1]
mat3 scale(const vec2 &s);

//Rotation
//A[0] x axis
//A[1] y axis
//[cos(a) -sin(a) 0]
//[sin(a) cos(a)  0]
//[0      0       0]
mat3 rotate(float deg);
