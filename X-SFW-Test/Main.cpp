#include "sfwdraw.h"
#include"mathUtils.h"
#include"vec2.h"
#include"vec3.h"
#include "Player.h"
int main()
{
	sfw::initContext();
	player me;

	//me.speed = 1000 * sfw::getDeltaTime();

	me.pos = {400, 300};

	while (sfw::stepContext())
	{
		me.update();
		me.draw();
	}
	sfw::termContext();
}
