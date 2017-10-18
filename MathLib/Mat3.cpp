#include "Mat3.h"
#include "vec3.h"
#include "mathUtils.h"
vec3 & mat3::operator[](size_t idx)
{
	return c[idx];
}

const vec3 & mat3::operator[](size_t idx) const
{
	return c[idx];
}

mat3 mat3::identity()
{
	return mat3{ 1,0,0,
				 0,1,0,
				 0,0,1 };
}

mat3 mat3::zero()
{
	return mat3{ 0,0,0,
				 0,0,0,
				 0,0,0 };
}

bool operator==(const mat3 & A, const mat3 & B)
{
	//mat3 retval = mat3::zero();
	//bool result = false;
	//for (int i = 0; i < 9; i++)
	//{
	//	if (A.m[i] == B.m[i])
	//	{
	//		result = true;
	//	}
	//}
	//return result;


	return A[0] == B[0] &&
		   A[1] == B[1] &&
		   A[2] == B[2];
}

mat3 operator+(const mat3 & A, const mat3 & B)
{
	mat3 retval = mat3::zero();

	for (int i = 0; i < 9; i++)
	{
		retval.m[i] = A.m[i] + B.m[i];
	}

	return retval;
}

mat3 operator-(const mat3 & A, const mat3 & B)
{
	mat3 retval = mat3::zero();

	for (int i = 0; i < 9; i++)
	{
		retval.m[i] = A.m[i] - B.m[i];
	}

	return retval;
}

mat3 operator*(const mat3 & A, const mat3 & B)
{
	mat3 retval;
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			retval[y][x] = dotProd(vec3{ A[0][x],A[1][x],A[2][x] }, B[y]);
		}
	}
	return retval;


	//mat3 At = transpose(A);
	//for (int y = 0; y < 3; y++)
	//{
	//	for (int x = 0; x < 3; x++)
	//	{
	//		retval[y][x] = dotProd(At[x], B[y]);
	//	}
	//}
	//return retval;
}

vec3 operator*(const mat3 & A, const vec3 & V)
{
	mat3 At = transpose(A);
	return vec3{ dotProd(At[0],V),dotProd(At[1],V),dotProd(At[2],V)};
}

mat3 transpose(const mat3 & A)
{
	mat3 retval;
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			retval[x][y] = A[y][x];
		}
	}
	return retval;
}

float determinant(const mat3 & A)
{
	return dotProd(A[0], crossProd(A[1], A[2]));
}

mat3 inverse(const mat3 & A)
{
	float di = 1 / determinant(A);
	return transpose(mat3{
		crossProd(A[1], A[2]) * di,
		crossProd(A[2], A[0]) * di,
		crossProd(A[0], A[1]) * di });
}

mat3 translate(const vec2 & t)
{
	mat3 retval = mat3::identity();
	retval[2].xy = t;
	return retval;
}

mat3 scale(const vec2 & s)
{
	return mat3{s.x,  0, 0,
				  0,s.y, 0,
				  0,  0, 1};
}

mat3 rotate(float deg)
{
	deg = (3.14159265358979323846264338327950288419716939937510582 / 180) * deg;
	return{ cos(deg),  sin(deg), 0, // x-axis
		   -sin(deg),  cos(deg), 0, // y-axis
		           0,         0, 1  // position
		  };
}
