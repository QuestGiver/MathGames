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

Collision intersect_Circle(const circle & A, const circle & B);

Collision intersect_ID(float Amin, float Amax, float Bmin, float Bmax);

Collision intersect_AABB(const AABB &A, const AABB & B);

Collision intersect_Circle(const circle & A, const circle & B);

Collision intersect_circle_AABB(const circle &A, const AABB &B);

void static_resolution(vec2 &pos, vec2 & vel, const Collision & hit, float elasticity = 0.1f);

void dynamic_resolution(vec2 &Apos, vec2 & Avel, float Amass, vec2 & Bpos, vec2 & Bvel, float Bmass, const Collision & hit, float elasticity = 1.0f);