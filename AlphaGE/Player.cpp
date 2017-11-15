#include "Player.h"
#include "sfwdraw.h"
#include "Controller.h"
#include "Collider.h"


player::player()
{
	//rad = 1;			|\
	//drag = 10;		| |Depricated and subsumed, refer to header
	//accel = { 0,0 };	|/

	collider = new Collider();

	collider->box.extents = { 20, 20 };
	
	speed = 0;

	dt = 0;
	
	enabled = true;
	button = false;

	up = false;
	down = false;
	left = false;
	right = false;

	myTransform = new transform();
	myTransform->position = vec2{ 350,400 };
	myTransform->dimension = vec2{1,1};
	myTransform->angle = 0;

	//myVerts[8] = new transform[8];

	for (int i = 0; i < 8; i++)
	{
		myVerts[i] = new transform();
		myVerts[i]->e_parent = myTransform;
		myVerts[i]->position = {(float)10, (float)0};
		vec2 pos = { (float)cos((45 * (i + 1)) * (PI / 180)), (float)sin(((45 * (i + 1)) * (PI / 180))) };
		myVerts[i]->position = pos * 20;
		myVerts[i]->dimension = vec2{ 1,1 };
	}

	//circ = new circle();
	//circ->position = myTransform->getGlobalPosition();
	//circ->radius = circ->radius;


	rigbdy = new Rigidbody();
	//ctrl = new Controller();

}

player::~player()
{
	delete myTransform;
	delete collider;

	myTransform = 0;
	collider = 0;
}



void player::update()
{

	

	rigbdy->integrate(*myTransform,sfw::getDeltaTime());

	if (enabled)
	{
		//myTransform.angle += sin(dt) + 1;

		//Misc operations===================================================

		dt = sfw::getDeltaTime();
		speed = getMag(rigbdy->acceleration);


		for (int i = 0; i < 8; i++)
		{
			//myVerts[i].e_parent = &myTransform;
			
			//myVerts[i]->position = myVerts[i]->position * 20;
			//myVerts[i].dimension = vec2{ 1,1 };
		}


		//Gravity---------------------------------------


		rigbdy->acceleration.y -= 1500 * sfw::getDeltaTime();

		//----------------------------------------------


		//Bounding Boxes=====================================================

		if (myTransform->position.x > 800 || myTransform->position.x < 0)
		{
			
			rigbdy->acceleration.x = -rigbdy->acceleration.x;
		}

		if (myTransform->position.y > 600 || myTransform->position.y <0)
		{
			rigbdy->acceleration.y = -rigbdy->acceleration.y;
		}



		//Bounciness is moar fun
		//			-TA
		if (myTransform->position.x > 800)
		{
			myTransform->position.x = 800;
		}

		if (myTransform->position.x < 0)
		{
			myTransform->position.x = 0;
		}

		if (myTransform->position.y > 600)
		{
			myTransform->position.y = 600;
		}

		if (myTransform->position.y < 0)
		{
			myTransform->position.y = 0;
		}
		
		//player inputs======================================================


		ctrl->poll(*rigbdy, *this);
		clamp({ 500,0 }, rigbdy->acceleration, { 0,500 });
		clamp({ 500,0 }, rigbdy->velocity, { 0,500 });
		////mouse------------------------------------------------------




		//if (button)
		//{
		//	for (int i = 0; i < 8; i++)
		//	{
		//		//myVerts[i].e_parent = &myTransform;
		//		myVerts[i].position = myVerts[i].position * 2;
		//		increment = 300;
		//		spdLim = 1500;
		//		rad = 25;
		//		//drag = 100;
		//		//myVerts[i].dimension = vec2{ 1,1 };
		//	}
		//}
		//else if(!button)
		//{
		//	for (int i = 0; i < 8; i++)
		//	{
		//		//myVerts[i].e_parent = &myTransform;
		//		myVerts[i].position = myVerts[i].position * 1;
		//		spdLim = 500;
		//		increment = 40;
		//		rad = 10;
		//		drag = speed;
		//		//myVerts[i].dimension = vec2{ 1,1 };
		//	}
		//}


		////keys-------------------------------------------------------



		//if (up == true && accel.y < spdLim)
		//{
		//	accel.y += increment;
		//}

		//if (right == true && accel.x < spdLim)
		//{
		//	accel.x += increment;
		//}



		//if (down == true && accel.y > -spdLim)
		//{
		//	accel.y -= increment;
		//}

		//if (left == true && accel.x > -spdLim)
		//{
		//	accel.x -= increment;
		//}
		////-----------------------------------------------------------

		////=============================================================

		
	}



}


void DrawVecLine(const vec2 &a, const vec2 &b, int color)
{
	sfw::drawLine(a.x, a.y, b.x, b.y, color);
}

void drawAABB(const AABB & box)
{
	vec2 TR = box.position + box.extents;
	vec2 BL = box.position - box.extents;
	vec2 TL = { box.position.x - box.extents.x, box.position.y + box.extents.y };
	vec2 BR = { TR.x, BL.y };

	DrawVecLine(TR, TL, MAGENTA);
	DrawVecLine(TL, BL, MAGENTA);
	DrawVecLine(BL, BR, MAGENTA);
	DrawVecLine(BR, TR, MAGENTA);


}

void player::draw()
{




	if (enabled)
	{

		drawAABB(collider->getGlobalBox(*myTransform));
		myTransform->DrawMatrix( 40);

		for (int i = 0; i < 8; i++)
		{

			//myVerts[i].position = vec2{ sinf(t * i) * i,sinf(t * i) * i };
			myVerts[i]->e_parent;
			myVerts[i]->DrawMatrix( 10);
			//myVerts[i].angle += sinf(t) + 50 * sfw::getDeltaTime();



			//sfw::drawLine(myTransform.position.x, myTransform.position.y, myVerts[i].position.x, myVerts[i].position.y, BLUE);
			if (i < 7)
			{
				vec2 line1;
				line1.x = myVerts[i]->getGlobalPosition().x;
				line1.y = myVerts[i]->getGlobalPosition().y;
				vec2 line2;
				line2.x = myVerts[i + 1]->getGlobalPosition().x;
				line2.y = myVerts[i + 1]->getGlobalPosition().y;
				sfw::drawLine(line1.x,line1.y ,line2.x ,line2.y , GREEN);
			}
			else
			{
				sfw::drawLine(myVerts[7]->getGlobalPosition().x, myVerts[7]->getGlobalPosition().y, myVerts[0]->getGlobalPosition().x, myVerts[0]->getGlobalPosition().y,GREEN);

			}
			
			sfw::drawCircle(myVerts[1]->getGlobalPosition().x, myVerts[1]->getGlobalPosition().y, 3, 3, BLUE);
			sfw::drawCircle(myVerts[4]->getGlobalPosition().x, myVerts[4]->getGlobalPosition().y, 3, 3);
			sfw::drawCircle(myVerts[6]->getGlobalPosition().x, myVerts[6]->getGlobalPosition().y, 3, 3);
		}
	}

}

void doCollision(player & p1, player & p2)
{
	Collision hit = collides(p1.myTransform, p1.collider, p2.myTransform, p2.collider);
	
	if (hit.penetrationDepth > 0)
	{
		dynamic_resolution(p1.myTransform->position, p1.rigbdy->velocity,
			p1.rigbdy->mass, p2.myTransform->position, p2.rigbdy->velocity,
			p2.rigbdy->mass, hit,3);
	}


}
