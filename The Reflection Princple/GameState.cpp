#include "GameState.h"

GameState::GameState()
{
	//init values
	plyr[0].myTransform->position = { 200,200 };
	plyr[1].myTransform->position = { 400,400 };
}

void GameState::update()
{
	doCollision(plyr[0], plyr[1]);

	//p1-----------
	if (sfw::getKey('W') == true)
	{
		plyr[0].up = true;
	}
	else
	{
		plyr[0].up = false;
	}
	//

	if (sfw::getKey('S') == true)
	{
		plyr[0].down = true;
	}
	else
	{
		plyr[0].down = false;
	}
	//

	if (sfw::getKey('D') == true)
	{
		plyr[0].right = true;
	}
	else
	{
		plyr[0].right = false;
	}
	//

	if (sfw::getKey('A') == true)
	{
		plyr[0].left = true;
	}
	else
	{
		plyr[0].left = false;
	}




	//p2-----------
	//p1-----------
	if (sfw::getKey(KEY_UP) == true)
	{
		plyr[1].up = true;
	}
	else
	{
		plyr[1].up = false;
	}
	//

	if (sfw::getKey(KEY_DOWN) == true)
	{
		plyr[1].down = true;
	}
	else
	{
		plyr[1].down = false;
	}
	//

	if (sfw::getKey(KEY_RIGHT) == true)
	{
		plyr[1].right = true;
	}
	else
	{
		plyr[1].right = false;
	}
	//

	if (sfw::getKey(KEY_LEFT) == true)
	{
		plyr[1].left = true;
	}
	else
	{
		plyr[1].left = false;
	}
	//----

	for (int i = 0; i < 2; i++)
	{
		plyr[i].update();
	}
}

void GameState::draw()
{
	for (int i = 0; i < 2; i++)
	{
		plyr[i].draw();
	}
}
