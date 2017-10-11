#include "mathUtils.h"
#include "vec2.h"
#include <assert.h>

int main()
{
	
	//int val = min(1, 3);
	vec2 test = {5,20};
	vec2 testB = {13,4};

	vec2 result = test + testB;

	vec2 num = { 0,0 };

	num += test;

	bool eq = num == test;

	{
		vec2 a = { 0,0 };
		vec2 b = { 0,0 };


		//You have just now stated that if these two don't match, pause the universe.
		assert(a == b);
	}

	while (true)
	{

	}
}