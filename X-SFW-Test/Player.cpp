#include "Player.h"
#include "sfwdraw.h"
#include"Transform.h"


player::player()
{
	accel = { 0,0 };
	speed = 0;
	rad = 10;
	t = 0;
	drag = 10;
	enabled = true;
	button = false;

	up = false;
	down = false;
	left = false;
	right = false;

	myTransform.position = vec2{ 350,400 };
	myTransform.dimension = vec2{1,1};
	myTransform.angle = 0;

	for (int i = 0; i < 8; i++)
	{
		myVerts[i].e_parent = &myTransform;
		myVerts[i].position = {(float)10, (float)0};
		myVerts[i].dimension = vec2{ 1,1 };
	}



}

void player::update()
{
	float increment = 40;
	float spdLim = 500;
	if (enabled)
	{

		//Misc operations===================================================
		t = sfw::getDeltaTime();
		speed = getMag(accel);
		myTransform.position += accel * sfw::getDeltaTime();

		myTransform.angle += sin(t) + 1;

		for (int i = 0; i < 8; i++)
		{
			//myVerts[i].e_parent = &myTransform;
			myVerts[i].position = { (float)cos((45 * (i + 1)) * (PI / 180)), (float)sin(((45 * (i + 1)) * (PI / 180))) };
			myVerts[i].position = myVerts[i].position * 20;
			//myVerts[i].dimension = vec2{ 1,1 };
		}

		//drag----------------------------------
		if (accel.x != 0 && accel.x > 0)
		{
			accel.x -= drag * sfw::getDeltaTime();
		}
		else if (accel.x != 0 && accel.x < 0)
		{
			accel.x += drag * sfw::getDeltaTime();

		}

		if (accel.y != 0 && accel.y > 0)
		{
			accel.y -= drag * sfw::getDeltaTime();
		}
		else if(accel.y != 0 && accel.y < 0)
		{
			accel.y += drag * sfw::getDeltaTime();
		}
		//Gravity---------------------------------------


		accel.y -= 1500 * sfw::getDeltaTime();

		//----------------------------------------------


		//Bounding Boxes=====================================================

		if (myTransform.position.x > 800 || myTransform.position.x < 0)
		{
			
			accel.x = -accel.x;
		}

		if (myTransform.position.y > 600 || myTransform.position.y <0)
		{
			accel.y = -accel.y;
		}

		if (myTransform.position.x > 800)
		{
			myTransform.position.x = 800;
		}

		if (myTransform.position.x < 0)
		{
			myTransform.position.x = 0;
		}

		if (myTransform.position.y > 600)
		{
			myTransform.position.y = 600;
		}

		if (myTransform.position.y < 0)
		{
			myTransform.position.y = 0;
		}
		
		//player inputs======================================================


		//mouse------------------------------------------------------

		if (button)
		{
			for (int i = 0; i < 8; i++)
			{
				//myVerts[i].e_parent = &myTransform;
				myVerts[i].position = myVerts[i].position * 2;
				increment = 300;
				spdLim = 1500;
				rad = 25;
				//drag = 100;
				//myVerts[i].dimension = vec2{ 1,1 };
			}
		}
		else if(!button)
		{
			for (int i = 0; i < 8; i++)
			{
				//myVerts[i].e_parent = &myTransform;
				myVerts[i].position = myVerts[i].position * 1;
				spdLim = 500;
				increment = 40;
				rad = 10;
				drag = speed;
				//myVerts[i].dimension = vec2{ 1,1 };
			}
		}


		//keys-------------------------------------------------------



		if (up == true && accel.y < spdLim)
		{
			accel.y += increment;
		}

		if (right == true && accel.x < spdLim)
		{
			accel.x += increment;
		}



		if (down == true && accel.y > -spdLim)
		{
			accel.y -= increment;
		}

		if (left == true && accel.x > -spdLim)
		{
			accel.x -= increment;
		}
		//-----------------------------------------------------------

		//=============================================================

		
	}



}

void player::draw()
{
	if (enabled)
	{
		DrawMatrix(myTransform.getGlobalTransform(), 40);
		
		for (int i = 0; i < 8; i++)
		{

			//myVerts[i].position = vec2{ sinf(t * i) * i,sinf(t * i) * i };
			DrawMatrix(myVerts[i].getGlobalTransform(), 10);
			//myVerts[i].angle += sinf(t) + 50 * sfw::getDeltaTime();



			//sfw::drawLine(myTransform.position.x, myTransform.position.y, myVerts[i].position.x, myVerts[i].position.y, BLUE);
			if (i < 7)
			{
				sfw::drawLine(myVerts[i].getGlobalPosition().x, myVerts[i].getGlobalPosition().y, myVerts[i +1].getGlobalPosition().x, myVerts[i + 1] .getGlobalPosition().y);
			}
			else
			{
				sfw::drawLine(myVerts[7].getGlobalPosition().x, myVerts[7].getGlobalPosition().y, myVerts[0].getGlobalPosition().x, myVerts[0].getGlobalPosition().y);

			}
			

			
		}
	}

}
