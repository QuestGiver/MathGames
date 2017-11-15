#include "GameState.h"
int main()
{
	GameState myGame;
	sfw::initContext();
	sfw::setBackgroundColor(BLACK);
	while (sfw::stepContext())
	{
		myGame.update();
		myGame.draw();
	}

	sfw::termContext();
}