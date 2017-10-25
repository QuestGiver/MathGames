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
	if (sfw::getKey(32))
	{
		plyr.button = true;
		if (collider.isColliding(plyr.position, plyr2.position, plyr.rad, plyr2.rad))
		{
			plyr.accel = collider.colResponce(plyr, plyr2, plyr.rad, plyr2.rad);
		}
	}
	else
	{
		plyr.button = false;
	}


	if (sfw::getKey('W'))
	{
		plyr.up = true;
	}
	else
	{
		plyr.up = false;
	}


	if (sfw::getKey('D'))
	{
		plyr.right = true;
	}
	else
	{
		plyr.right = false;
	}



	if (sfw::getKey('S'))
	{
		plyr.down = true;
	}
	else
	{
		plyr.down = false;
	}

	if (sfw::getKey('A'))
	{
		plyr.left = true;
	}
	else
	{
		plyr.left = false;
	}

	plyr.update();
	//P2---------------------------------------------------------
	if (sfw::getMouseButton(MOUSE_BUTTON_LEFT))
	{
		plyr2.button = true;
		if (collider.isColliding(plyr.position, plyr2.position, plyr.rad, plyr2.rad))
		{
			plyr2.accel = collider.colResponce(plyr2, plyr, plyr2.rad, plyr.rad);
		}
	}
	else
	{
		plyr2.button = false;
	}


	if (sfw::getKey(KEY_UP))
	{
		plyr2.up = true;

	}
	else
	{
		plyr2.up = false;
	}


	if (sfw::getKey(KEY_RIGHT))
	{
		plyr2.right = true;
	}
	else
	{
		plyr2.right = false;
	}



	if (sfw::getKey(KEY_DOWN))
	{
		plyr2.down = true;
	}
	else
	{
		plyr2.down = false;
	}

	if (sfw::getKey(KEY_LEFT))
	{
		plyr2.left = true;
	}
	else
	{
		plyr2.left = false;
	}



	plyr2.update();
	//====================================================================
}

void gameState::draw()
{
	plyr.draw();
	plyr2.draw();
}


