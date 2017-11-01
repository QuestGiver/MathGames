#pragma once
#include "Player.h"

class Collider
{
	//Defaults
	//Player();
	//Explicit
	//Player(bool Enabled, int HP, int Atk);
	//Collision(); 


	float d;
public:
	




	bool isColliding(vec2 a, vec2 b, float Rad1, float Rad2);

	void colResponce(player & C1, player & C2, float R1, float R2);
	Collider();



	//collision(point a, point b, float R1, float R2);


	//---------------------------------------------------------------
	AABB box;

	AABB getGlobalBox(const transform & t) const
	{
		t.getGlobalTransform() * box;
	}

	//Collider(const AABB &a_box = { {0,0}, {1,1} }) : box(a_box)
	//{

	//}
};


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

Collision collides(const transform & At, const Collider & Ac, const transform & Bt, const Collider & Bc)