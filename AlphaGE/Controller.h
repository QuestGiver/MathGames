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
			p.rigbdy->force += normVec(t.getGlobalTransform()[1].xy) * 200;
		}

		if (p.right == true)
		{
			p.rigbdy->torque += -1000;
		}


		if (p.down == true)
		{
			p.rigbdy->force -= p.rigbdy->velocity * 5;
			rb.torque += -rb.angularVelocity * 5;
		}

		if (p.left == true)
		{
			p.rigbdy->torque += 1000;
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