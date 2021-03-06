#pragma once
#include "Player.h"
#include "Collison.h"
#include "Transform.h"


class Collider
{
	//Defaults
	//Player();
	//Explicit
	//Player(bool Enabled, int HP, int Atk);
	//Collision(); 



public:
	
	AABB box;

	AABB getGlobalBox(const transform & t) const
	{
		return t.getGlobalTransform() * box;
	}

	/*AABB getGlobalBox(const transform * t) const
	{
	return t->getGlobalTransform() * box;
	}*/

	Collider(const AABB &a_box = { { 0,0 },{ .5,.5 } }) : box(a_box)
	{

	}



	//bool isColliding(vec2 a, vec2 b, float Rad1, float Rad2);

	//void colResponce(player & C1, player & C2, float R1, float R2);
	//Collider();



	//collision(point a, point b, float R1, float R2);


	//---------------------------------------------------------------
	

	

};

Collision collides(const transform &At, const Collider &Ac, const transform &Bt, const Collider &Bc);
Collision collides(const transform *At, const Collider *Ac, const transform *Bt, const Collider *Bc);

