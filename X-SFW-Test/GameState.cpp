#include "GameState.h"

void gameState::init()
{
	for (int i = 0; i < 8; i++)
	{
		myBounds[i] = { {0,0},{3,3} };
	}
}

gameState::gameState()
{
	init();
}

void gameState::update()
{
	float time1 = 0;
	time1 += sfw::getDeltaTime();
	float timer1 = 1;

	float time2 = 0;
	time2 += sfw::getDeltaTime();
	float timer2 = 1;

	
	//PLayers=============================================================
	//P1---------------------------------------------------------

	if (sfw::getKey(32))
	{
		plyr.button = true;

		if (collider.isColliding(plyr.position, plyr2.position, plyr.rad, plyr2.rad) == true && time1 > timer1)
		{
			collider.colResponce(plyr, plyr2, plyr.rad, plyr2.rad);
			time1 = 0;
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

		if (collider.isColliding(plyr.position, plyr2.position, plyr.rad, plyr2.rad) == true && time2 > timer2)
		{
			collider.colResponce(plyr2, plyr, plyr2.rad, plyr.rad);
			time2 = 0;
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
	//plyr.draw();
	plyr2.draw();
	Draw(plyr.myTransform.getGlobalTransform() * parentBounds);

	for (int i = 0; i < 8; i++)
	{
		Draw(plyr.myVerts[i].getGlobalTransform() * myBounds[i]);
	}

	sfw::drawLine(plyr.getGlobalPosition().x, plyr.getGlobalPosition().y, plyr2.getGlobalPosition().x, plyr2.getGlobalPosition().y, GREEN);
}


