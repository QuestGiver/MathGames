#include "sfwdraw.h"
#include"mathUtils.h"
#include"vec2.h"
#include"vec3.h"
#include "Player.h"
#include"Transform.h"
int main()
{
	sfw::initContext();
	sfw::setBackgroundColor(BLACK);
	//player me;

	//me.speed = 1000 * sfw::getDeltaTime();

	//me.pos = {400, 300};

	transform myTransform;
	myTransform.position = vec2{ 300,400 };
	myTransform.dimension = vec2{1,1};




	while (sfw::stepContext())
	{
		//me.update();
		//me.draw();
		float t = sfw::getDeltaTime();
		myTransform.angle += 90 *  sfw::getDeltaTime();
		myTransform.dimension = vec2{ sinf(t) + 20, sinf(t) + 1 };
		DrawMatrix(myTransform.getLocalTransform(), 40);




	}
	sfw::termContext();
}
