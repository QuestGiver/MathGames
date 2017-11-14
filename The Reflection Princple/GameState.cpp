#include "GameState.h"

GameState::GameState()
{
	//init values
	
}

void GameState::update()
{
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
