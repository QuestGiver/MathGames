#include "mathUtils.h"

int min(int a, int b)
{

	//if (a < b)
	//{
	//	return a;

	//}
	//else
	//{
	//	return b;
	//}

	//<type> variable = (condition)? if:else
	return a > b ? a : b;
}

float getMag(vec2 vect2)
{
	return sqrtf((vect2.x * vect2.x) + (vect2.y * vect2.y));
}

float getVecDirec(vec2 vect2)
{
	float theta = 0;
	if (vect2.x > 0 && vect2.y > 0 || vect2.x > 0 && vect2.y < 0)
	{
		theta = atanf(vect2.y / vect2.x);
	}
	else if (vect2.x < 0 && vect2.y > 0 || vect2.x < 0 && vect2.y < 0)
	{
		theta = atanf(vect2.y / vect2.x) + 180;
	}
	return theta;
	
}

vec2 normVec(vec2 vect2)
{
	return (1 / getMag(vect2)) * vect2;
}

vec2 normalizeVec(vec2 & vect2)
{
	return normVec(vect2);
}

float dotProd(vec2 vect2, vec2 vect2_b)
{
	return (vect2.x * vect2_b.x) + (vect2.y * vect2_b.y);
	//return getMag(vect2) + getMag(vect2_b);// * vectAngle(vect2, vect2_b);
}

float vectAngle(vec2 vect2, vec2 vect2_b)
{
	//note: create normalized version

	return acos(dotProd(vect2, vect2_b) / (getMag(vect2) * getMag(vect2_b)));

	//return atan2(vect2_b.x, vect2.x) - atan2(vect2.y, vect2_b.y);
}

float pointDist(vec2 vect2, vec2 vect2_b)
{
	return sqrt(pow(vect2_b.x - vect2.x,2) + pow(vect2_b.y - vect2.y, 2));
}

vec2 perpVect(vec2 vect2)
{
	return{vect2.y,vect2.x *-1};
}

vec2 lerp(vec2 start, vec2 end, float time)
{
	return start + (end - start) * time;
}

vec2 min(vec2 vect2_a, vec2 vect2_b)
{
	return{ vect2_a.x < vect2_b.y ? vect2_a.x : vect2_b.x, vect2_a.x < vect2_b.y ? vect2_a.y : vect2_b.y };
}

vec2 max(vec2 vect2_a, vec2 vect2_b)
{
	return{ vect2_a.x > vect2_b.y ? vect2_a.x : vect2_b.x, vect2_a.x > vect2_b.y ? vect2_a.y : vect2_b.y };
}





