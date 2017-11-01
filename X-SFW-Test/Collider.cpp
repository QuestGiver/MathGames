#include "Collider.h"
#include"Shape.h"
#include <cmath>




bool Collider::isColliding(vec2 a, vec2 b, float Rad1, float Rad2)
{
	vec2 c1 = a;
	vec2 c2 = b;
	float r1 = Rad1;
	float r2 = Rad2;


	float sum = r1 + r2;
	//d = distance
	float d = sqrt(pow(c2.x - c1.x, 2) + pow(c2.y - c1.y, 2));
	//collide(d, sum);
	if (d < sum)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Collider::colResponce(player & C1, player & C2, float R1, float R2)
{
	vec2 p1Pos = C1.myTransform.getGlobalPosition();
	vec2 p2Pos = C2.myTransform.getGlobalPosition();

	float sum = R1 + R2;
	float d = sqrt(pow(p1Pos.x - p2Pos.x, 2) + pow(p1Pos.y - p2Pos.y, 2)) + 0.0001f;
	float x = (p2Pos.x - p1Pos.x) / d;
	float y = (p2Pos.y - p1Pos.y) / d;
	float p = 2 * (p1Pos.x * x + p1Pos.y * y - p2Pos.x * x - p2Pos.y * y) / (C1.speed + C2.speed);

	C1.accel.x = p1Pos.x - p * C1.speed * x;
	C1.accel.y = p1Pos.y - p * C1.speed * y;

	//return C1.accel;
	//C2.accel.x = C2.position.x + p * C2.speed * x;
	//C2.accel.y = C2.position.y + p * C2.speed * y;

}

Collider::Collider()
{
}





Collision collides(const transform & At, const Collider & Ac, const transform & Bt, const Collider & Bc)
{
	return intersect_AABB(Ac.getGlobalBox(At), Bc.getGlobalBox(Bt));
}


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


