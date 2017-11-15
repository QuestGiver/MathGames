#pragma once

#include"Controller.h"
#include "sfwdraw.h"
#include "Panel.h"

class GameState
{
public:
	GameState();

	player plyr[2];




	panel panels[15];
	
	//AABB pannel[15];// make panel class
	//player boss;


	void update();
	void draw();
private:

};
