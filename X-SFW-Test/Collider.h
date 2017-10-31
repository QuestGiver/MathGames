#pragma once
#include "vec2.h"
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
};