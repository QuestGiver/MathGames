#include "sfwdraw.h"
#include"mathUtils.h"
#include"vec2.h"
#include"vec3.h"
#include "Player.h"
#include"Transform.h"
#include<cmath>
int main()
{
	sfw::initContext();
	sfw::setBackgroundColor(BLACK);
	//player me;

	//me.speed = 1000 * sfw::getDeltaTime();

	//me.pos = {400, 300};

	transform myTransform;
	myTransform.position = vec2{ 350,400 };
	myTransform.dimension = vec2{40,2};
	//myTransform.angle = 0;

	transform myBaby;
	myBaby.position = vec2{ 30,50 };
	myBaby.dimension = vec2{ 40,40 };
	//myBaby.angle = 0;
	myBaby.e_parent = &myTransform;

	transform myAbs[200];
	for (int i = 0; i < 200; i++)
	{
		myAbs[i].position = vec2{ (float)30+i,(float)50+i };
		myAbs[i].dimension = vec2{ 1,1 };
		//myBaby.angle = 0;

		myAbs[i].e_parent = &myTransform;
	}

	while (sfw::stepContext())
	{
		//me.update();
		//me.draw();
		float t = sfw::getDeltaTime();
		myTransform.angle += 9 *  sfw::getDeltaTime();
		myTransform.dimension = vec2{ sinf(t) + 5, sinf(t) + 1 };

		DrawMatrix(myTransform.getGlobalTransform(), 40);
		DrawMatrix(myBaby.getGlobalTransform(), 40);

		for (int i = 0; i < 200; i++)
		{
			myAbs[i].dimension = vec2{ sinf(t +i) + 0, sinf(t + i) + 0 };
			myAbs[i].position = vec2{ sinf(t * i) * i,sinf(t * i) * i };
			DrawMatrix(myAbs[i].getGlobalTransform(), 40 + i);
			//myAbs[i].angle += sinf(t) + 5 + i * sfw::getDeltaTime();
		}




	}
	sfw::termContext();
}
