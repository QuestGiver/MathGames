#include "Player.h"
#include "sfwdraw.h"
void player::update()
{
	vec2 movement = {0,0};
	speed = 0;// 100 * sfw::getDeltaTime();
	if (sfw::getKey('W'))
	{
		movement.y += 1;
	}
	if (sfw::getKey('A'))
	{
		movement.x -= 1;
	}
	if (sfw::getKey('S'))
	{
		movement.y -= 1;
	}
	if (sfw::getKey('D'))
	{
		movement.x += 1;
	}




	if (pos.x > 800)
	{
		pos.x = 0;
	}
	if (pos.x < 0)
	{
		pos.x = 800;
	}
	if (pos.y > 600)
	{
		pos.y = 0;
	}


	movement *= speed;
	pos += movement;
}

void player::draw()
{
	sfw::drawCircle(pos.x,pos.y,30.0f);
}