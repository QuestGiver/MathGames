#include "MathUtils.h"
#include "cmath"

float sqr(float v)
{
	return v*v;
}

float cube(float v)
{
	return v*v*v;
}

float dbl(float v)
{
	return 2*v;
}

float degToRad(float deg)
{
	return deg * 3.14159265359 / 180;
}

float radToDeg(float rad)
{
	return rad * 3.14159265359/180;
}

//sqr(x) + b*x + c
float qudratic(float a, float x, float b, float c)
{
	return sqr(x) + b*x + c;
}

float linBlend(float start, float end, float alpha)
{
	return start+ alpha * (end-start);
}

float dst(point a, point b)
{
	return sqrtf(sqr(b.x - a.x) + sqr(b.y - a.y));
}

float PlanePointDst( float x, float y, float z,float a, float b, float c, float d)
{
	return (a*x + b * y + c*z + d)/ sqrtf(sqr(a) + sqr(b) + sqr(c));
}

float Cubezier(float t, bezier p, float l)
{
	return cube(l-t) * p.x + 3 * sqr(l-t) * t * p.y + 3 * (l-t) * sqr(t) * p.z + cube(t) * p.w;
}

point QuadEquate(float a, float b, float c)//, point z)
{
	point z;
	z.x = (-b + sqrtf(sqr(b) - (4 * a * c))) / dbl(a);
	z.y = (-b - sqrtf(sqr(b) - 4 * a * c)) / dbl(a);
	return z;

}




