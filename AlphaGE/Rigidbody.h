#pragma once
#include "Transform.h"

class Rigidbody
{
public:
	vec2 velocity,//speed & direction
		 acceleration,//sum of all forces, A = F/M
		 force,
		 impulse;

	float mass,
		  drag;

	float angularVelocity,
		  angularAcceleration,
		  torque;
	float angularDrag;

				 //delta position==============================================================================================================
	Rigidbody() : velocity{ 0,0 },//speed and direction

			   	  acceleration{0,0},//unit by which speed is increased, sum of all forces, A = F/M

				  force{0,0},//a unit by which acceleration is modified

				  mass(1),//the mass of the object

				  impulse{0,0},//a unit by which acceleration is modified, larger mass lessens effect

				  drag(0.25f),//a constant force which decreases overall speed

				//delta angle=====================================================================================================================
				  angularVelocity(0), //the speed by which an object turns

				  angularAcceleration(0),//the unit by which angular velocity is impacted

				  torque(1),//unit by which the angular acceleration is modified, larger mass lessens effect

				  angularDrag(0.25)
	{

	}

	void integrate(transform &T, float dt)
	{
		


		acceleration = force / mass;
		velocity += acceleration * dt + impulse / mass;
		T.position += velocity * dt;
		impulse = { 0,0 };
		force = -velocity * drag;
		// angular motion (sort of)
		angularAcceleration = torque / mass;
		angularVelocity += angularAcceleration * dt;
		T.angle += angularVelocity * dt;
		torque = -angularVelocity * angularDrag;
	}
	//void integrate(transform *T, float dt)
	//{



	//	acceleration += force / mass;
	//	velocity += acceleration * dt + impulse / mass;
	//	T->position += velocity * dt;


	//	force = -velocity * drag;
	//	impulse = force = { 0,0 };
	//	//-------------------

	//	angularAcceleration = torque / mass;
	//	angularVelocity += angularAcceleration * dt;
	//	T->angle += angularVelocity * dt;
	//	torque = -angularVelocity * angularDrag;
	//}


};