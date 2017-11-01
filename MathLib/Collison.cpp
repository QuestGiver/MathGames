#include "Collison.h"
#include "Shapes.h"

Collision intersect_ID(float Amin, float Amax, float Bmin, float Bmax)
{
	Collision ret;

	float lPD = Bmax - Amin;
	float rPD = Amax - Bmin;

	ret.penetrationDepth = min(lPD, rPD);
	ret.penetrationDepth = copysign(1, rPD - lPD);
	return ret;
}

Collision intersect_AABB(const AABB & A, const AABB & B)
{
	Collision xres = intersect_ID(A.mn().x, A.mx().x, B.mn().x, B.mx().x);
	Collision yres = intersect_ID(A.mn().y, A.mx().y, B.mn().y, B.mx().y);

	xres.axis = vec2{ 1,0 };
	yres.axis = vec2{ 0,1 };

	return xres.penetrationDepth < yres.penetrationDepth ? xres : yres;
}

Collision intersect_Circle(const circle & A, const circle & B)
{
	Collision ret;
	ret.axis = normVec(B.position - A.position);
	ret.handedness = -1;

	float Ap = dotProd(ret.axis, A.position);
	float Bp = dotProd(ret.axis, B.position);

	float Amin = Ap - A.radius;
	float Amax = Ap + A.radius;

	float Bmin = Bp - B.radius;
	float Bmax = Bp + B.radius;

	ret.penetrationDepth = intersect_ID(Amin, Amax, Bmin, Bmax).penetrationDepth;

	return ret;

}

Collision intersect_AABB_Circle(const AABB & A, const circle & B)
{
	return Collision();
}


