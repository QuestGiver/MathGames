#pragma once
#include "Mat3.h"
#include "mathUtils.h"
#include "Shapes.h"
struct Collision
{
	float penetrationDepth;// if penetration is negative, that's the distance
	float handedness;// does "A" need to move left or right along the axis
	vec2 axis;
};

Collision intersect_ID(float Amin, float Amax, float Bmin, float Bmax);

Collision intersect_AABB(const AABB &A, const AABB & B);

Collision intersect_Circle(const circle & A, const circle & B);

Collision intersect_AABB_Circle(const AABB &A, const circle &B);