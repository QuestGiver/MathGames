#pragma once
#include "vec2.h"
#include "Transform.h"
class Collider : public transform
{
	//Defaults
	//Player();
	//Explicit
	//Player(bool Enabled, int HP, int Atk);
	//Collision(); 
	//Paul smells like poo

	float d;
public:
	


	float speed;

	bool isColliding(vec2 a, vec2 b, float R1, float R2);

	void colResponce(transform & C1, transform & C2, float R1, float R2, );

	//collision(point a, point b, float R1, float R2);
};