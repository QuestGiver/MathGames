#include "GameState.h"

void gameState::init()
{

}

gameState::gameState()
{
	init();
}

void gameState::update()
{
	//PLayers=============================================================
	//P1---------------------------------------------------------
	if (sfw::getMouseButton(MOUSE_BUTTON_LEFT))
	{
		plyr.button = true;
	}
	else
	{
		plyr.button = false;
	}
	plyr.update();
	//P2---------------------------------------------------------
	//====================================================================
}

void gameState::draw()
{
	plyr.draw();
}


