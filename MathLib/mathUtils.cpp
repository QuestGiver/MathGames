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

float getMag(vec2 vect2_a)
{
	return sqrtf((vect2_a.x * vect2_a.x) + (vect2_a.y * vect2_a.y));
}

float getVecDirec(vec2 vect2_a)
{
	float theta = 0;
	if (vect2_a.x > 0 && vect2_a.y > 0 || vect2_a.x > 0 && vect2_a.y < 0)
	{
		theta = atanf(vect2_a.y / vect2_a.x);
	}
	else if (vect2_a.x < 0 && vect2_a.y > 0 || vect2_a.x < 0 && vect2_a.y < 0)
	{
		theta = atanf(vect2_a.y / vect2_a.x) + 180;
	}
	return theta;
	
}

vec2 normVec(vec2 vect2_a)
{
	return (1 / getMag(vect2_a)) * vect2_a;
}

vec2 &normalizeVec(vec2 & vect2_a)
{
	vect2_a = normVec(vect2_a);
	return vect2_a;
}

float dotProd(vec2 vect2_a, vec2 vect2_b)
{
	return (vect2_a.x * vect2_b.x) + (vect2_a.y * vect2_b.y);
	//return getMag(vect2) + getMag(vect2_b);// * vectAngle(vect2, vect2_b);
}

float vectAngle(vec2 vect2_a, vec2 vect2_b)
{


	return acos(dotProd(vect2_a, vect2_b) / (getMag(vect2_a) * getMag(vect2_b)));

	//return atan2(vect2_b.x, vect2.x) - atan2(vect2.y, vect2_b.y);
}

float pointDist(vec2 vect2_a, vec2 vect2_b)
{
	return sqrt(pow(vect2_b.x - vect2_a.x,2) + pow(vect2_b.y - vect2_a.y, 2));
}

vec2 perpVect(vec2 vect2_a)
{
	return{vect2_a.y,vect2_a.x *-1};
}

vec2 lerp(vec2 start, vec2 end, float time)
{
	return start + (end - start) * time;
}

vec2 min(vec2 vect2_a, vec2 vect2_b)
{
	return{ vect2_a.x < vect2_b.x ? vect2_a.x : vect2_b.x, vect2_a.y < vect2_b.y ? vect2_a.y : vect2_b.y };
}

vec2 max(vec2 vect2_a, vec2 vect2_b)
{
	return{ vect2_a.x > vect2_b.x ? vect2_a.x : vect2_b.x, vect2_a.y > vect2_b.y ? vect2_a.y : vect2_b.y };
}

vec2 project(const vec2 & v, const vec2 & axis)
{
	return dotProd(v, axis) * axis;
}

vec2 reflect(const vec2 & v, const vec2 & axis)
{
	return 2 * project(v, axis) - v;
}



//Segregation line between vec2's and vec3's---------------------------------------------------------
//Not all vectors are not created equal


vec3 crossProd(vec3 _A, vec3 _B)
{
	return { (_A.y * _B.z) - (_A.z * _B.y), (_A.z * _B.x) - (_A.x * _B.z), (_A.x * _B.y) - (_A.y * _B.x) };
}

float dotProd(vec3 _A, vec3 _B)
{
	return (_A.x * _B.x) + (_A.y * _B.y) + (_A.z * _B.z);
}

float getMag(vec3 _A)
{
	return sqrt(pow(_A.x, 2) + pow(_A.y, 2) + pow(_A.z, 2));
}

vec3 lerp(vec3 start, vec3 end, float percent)
{
	return(start + percent * (end - start));
}

vec3 normVec(vec3 _A)
{
	return (1 / getMag(_A)) * _A;
}

vec3 & normalizeVec(vec3 & _A)
{
	_A = normVec(_A);
	return _A;
}

float vectAngle(vec3 _A, vec3 _B)
{

	return acos(dotProd(_A, _B) / (getMag(_A) * getMag(_B)));
}

vec3 min(vec3 _A, vec3 _B)
{
	return{ _A.x < _B.x ? _A.x : _B.x, _A.y < _B.y ? _A.y : _B.y, _A.z < _B.z ? _A.z : _B.z  };

}

vec3 max(vec3 _A, vec3 _B)
{
	return{ _A.x > _B.x ? _A.x : _B.x, _A.y > _B.y ? _A.y : _B.y, _A.z > _B.z ? _A.z : _B.z };

}







