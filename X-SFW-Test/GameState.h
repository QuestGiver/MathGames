#pragma once
#include "Collider.h"
#include<cmath>
class gameState
{
public:


	Collider collider;
	player plyr;
	player plyr2;
	gameState();





	void init();
	void update();
	void draw();
};