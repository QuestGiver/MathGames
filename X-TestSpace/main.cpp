#include "mathUtils.h"
#include "vec2.h"
#include "vec3.h"
#include "Mat3.h"
#include <assert.h>

int main()
{
	
	////int val = min(1, 3);
	//vec2 test = {5,20};
	//vec2 testB = {13,4};

	//vec2 result = test + testB;

	//vec2 num = { 0,0 };

	//num += test;

	//bool eq = num == test;

	//{
	//	vec2 a = { 0,0 };
	//	vec2 b = { 0,0 };


	//	//You have just now stated that if these two don't match, pause the universe.
	//	assert(a == b);
	//}
	mat3 I = mat3::identity();
	mat3 Z = mat3::zero();
	mat3 A = { 1,2,3,4,5,6,7,8,9 };
	mat3 V = {1,2,3};

	assert(I + Z == I);
	assert(Z + I == I);
	assert(I - Z == I);
	assert(!(Z-I == I));
	assert(transpose(I) == I);
	assert(A*I == A);
	assert(I*A == A);
	assert(I*V == V);
	assert(inverse(I) == I);


	mat3 T = scale(vec2{ 1,2 }) * rotate(90) * translate(vec2{ 3,0 });

	assert((T[2].xy == vec2{ 0,6 }));
	

	while (true)
	{

	}
}