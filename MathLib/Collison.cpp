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

void static_resolution(vec2 & pos, vec2 & vel, const Collision & hit, float elasticity)
{
	//for position, we need to correct:
	pos += hit.axis * hit.handedness * hit.penetrationDepth;

	//for velocity we need to reflect:
	vel = -reflect(vel, hit.axis * hit.handedness) * elasticity;

}

void dynamic_resolution(vec2 & Apos, vec2 & Avel, float Amass,
						vec2 & Bpos, vec2 & Bvel, float Bmass,
						const Collision & hit, float elasticity)
{
	//Law of conservation
	/*
		mass*vel = momentum
		AP + BP = `AP + `BP

		Avel * Amass + Bvel * Bmass = fAvel * Amass + fBmass
		Avel - Bvel = -(fBvel - fAvel)

		fBvel = Bvel - Avel + fAvel;

		///

		Avel * Amass + = fAvel * Amass - Avel * Bmass + fAvel * Bmass;


		AV - BV = `BV - `AV // Relative velocity

	*/
	vec2 normal = hit.axis * hit.handedness;

	vec2 Rvel = Avel - Bvel;

	float j = //impulse magnitude - the total energy applied across the normal
	-(1 + elasticity) * dotProd(normal, normal * (1 / Amass + 1 / Bmass));



	Avel += (j / Amass) * normal;
	Bvel -= (j / Bmass) * normal;

	Apos += normal * (hit.penetrationDepth * Amass/Bmass);
	Bpos -= normal * (hit.penetrationDepth * Bmass/Amass);
}


