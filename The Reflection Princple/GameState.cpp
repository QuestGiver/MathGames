#include "GameState.h"
#include <random>
#include <time.h>

GameState::GameState()
{
	srand(time(NULL));
	//init values
	plyr[0].myTransform->position = { 200,200 };
	plyr[0].color = GREEN;


	plyr[1].myTransform->position = { 400,400 };
	plyr[1].color = WHITE;

	for (int i = 0; i < 15; i++)
	{
		panels[i].panelTransform.position = { (float)(rand() % 800 + 1),(float)(rand() % 600 + 1) };
		panels[i].panelTransform.dimension = {1,1 };
		panels[i].collider.box.position = { 0,0 };
		panels[i].rigbdy.drag = 0;
	}

	for (int i = 0; i < 15; i++)
	{
		panels[i].rigbdy.angularVelocity = (float)(30);
		int p = rand() % 100 + 0;
		if (p >= 50)
		{
			panels[i].collider.box.extents = { 0,30};
		}
		else
		{

			panels[i].collider.box.extents = { 30,0 };
		}

	}
}

void GameState::update()
{
	doCollision(plyr[0], plyr[1]);

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			doCollision(plyr[j], panels[i]);
		}

	}


	for (int i = 0; i < 15; i++)
	{
		if (panels[i].panelTransform.position.x > 800)
		{
			panels[i].panelTransform.position.x = 0;
		}
		else if (panels[i].panelTransform.position.x < 0)
		{
			panels[i].panelTransform.position.x = 800;
		}

		if (panels[i].panelTransform.position.y > 600)
		{
			panels[i].panelTransform.position.y = 0;
		}
		else if (panels[i].panelTransform.position.y < 0)
		{
			panels[i].panelTransform.position.y = 600;
		}



		if (panels[i].collider.box.extents.x == 30)
		{
			panels[i].panelTransform.position.x += 5;
		}

		if (panels[i].collider.box.extents.y == 30)
		{
			panels[i].panelTransform.position.y += 5;
		}
	}





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
	for (int i = 0; i < 15; i++)
	{
		panels[i].update();
	}
}

void GameState::draw()
{
	for (int i = 0; i < 2; i++)
	{
		plyr[i].draw();
	}

	for (int i = 0; i < 15; i++)
	{
		panels[i].draw();
	}
}
