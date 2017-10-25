#include "Player.h"
#include "sfwdraw.h"
#include"Transform.h"


player::player()
{
	accel = { 0,0 };
	speed = 0;
	rad = 0;
	t = 0;
	drag = 10;
	enabled = true;
	button = false;

	myTransform.position = vec2{ 350,400 };
	myTransform.dimension = vec2{40,2};
	myTransform.angle = 0;

	for (int i = 0; i < 8; i++)
	{
		myVerts[i].position = vec2{ (float)10,(float)0 };
		myVerts[i].dimension = vec2{ 1,1 };
		myVerts[i].angle = 360/(i+1);

		myVerts[i].e_parent = &myTransform;
	}
}

void player::update()
{
	if (enabled)
	{

		//Misc operations===================================================
		t = sfw::getDeltaTime();
		speed = getMag(accel);
		myTransform.position += accel * sfw::getDeltaTime();


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
		//---------------------------------------
		//Bounding Boxes=====================================================

		if (myTransform.position.x > 800 || myTransform.position.x < 0)
		{
			accel.x = -accel.x;
		}

		if (myTransform.position.y > 600 || myTransform.position.y <0)
		{
			accel.y = -accel.y;
		}
		
		//player inputs======================================================


		//mouse------------------------------------------------------
		if (button)
		{
				float l = 0;
			for (size_t i = 0; i < 8; i++)
			{
				do
				{
					myVerts[i].position.x += (float)(10 * sfw::getDeltaTime());
				} while (myVerts[i].position.x < 10);
				l = 0;
			}
		}
		else if(!button)
		{
			for (int i = 0; i < 8; i++)
			{
				myVerts[i].position = vec2{ (float)25,(float)0 };

			}
		}


		//keys-------------------------------------------------------

		//must be greater than drag value to overcome it
		float increment = 40;

		if (sfw::getKey('W') && accel.y < 500)
		{
			accel.y += increment;
		}
		else if (sfw::getKey('D') && accel.x < 500)
		{
			accel.x += increment;
		}



		if (sfw::getKey('S') && accel.y > -500)
		{
			accel.y -= increment;
		}
		else if (sfw::getKey('A') && accel.x > -500)
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
			DrawMatrix(myVerts[i].getGlobalTransform(), 40);
			myVerts[i].angle += sinf(t) + 50 * sfw::getDeltaTime();


			if (i < 8)
			{
				sfw::drawLine(myVerts[i].position.x, myVerts[i].position.y, myVerts[i + 1].position.x, myVerts[i + 1].position.y);
			}
			else
			{
				sfw::drawLine(myVerts[i].position.x, myVerts[i].position.y, myVerts[0].position.x, myVerts[0].position.y);

			}
			

			
		}
	}

}
