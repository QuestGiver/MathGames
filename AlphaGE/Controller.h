#pragma once
//controller -> rigidbody -> transform
#include "Rigidbody.h"
//#include "sfwdraw.h"
#include "Player.h"

//Poll for input and apply changes to the rigidbody

class Controller
{
	
public:
	void poll(Rigidbody & rb, player & p)
	{
		transform t = *p.myTransform;
		//mouse------------------------------------------------------





		//if (p.button)
		//{
		//	for (int i = 0; i < 8; i++)
		//	{

		//	}
		//}

		//else if(!button)
		//{
		//	for (int i = 0; i < 8; i++)
		//	{

		//	}
		//}


		//keys-------------------------------------------------------



		if (p.up == true)
		{
			p.rigbdy->force += {0,50};
		}

		if (p.right == true)
		{
			p.rigbdy->force += { 50,0 };
		}


		if (p.down == true)
		{
			p.rigbdy->force += { 0,-50 };
		}

		if (p.left == true)
		{
			p.rigbdy->force += { -50,0 };
		}

		p.rigbdy->integrate(t, p.dt);


		//-----------------------------------------------------------

		//=============================================================

	}

	void poll(Rigidbody & rb, transform & t)
	{



	};
	//controller -> rigidbody -> transform
};