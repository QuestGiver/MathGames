#pragma once
#include"Collider.h"
//#include<cmath>


class gameState
{
public:


	Collider collider;
	player plyr;
	player plyr2;
	AABB parentBounds = { {0,0}, {10,10} };
	AABB myBounds[8];
	gameState();



	void init();
	void update();
	void draw();
};