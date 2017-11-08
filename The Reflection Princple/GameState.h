#pragma once
#include"Collider.h"
#include"Controller.h"

class GameState
{
public:
	GameState();

	player plyr[2];
	AABB pannel[15];
	player boss;


	void update();
	void draw();
private:

};
