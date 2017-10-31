#pragma once
#include "vec2.h"
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

	Rigidbody() : velocity{ 0,0 },
			   	  acceleration{0,0},
				  force{0,0},
				  mass(1),
				  impulse{0,0},
				  drag(0.25f),
				  angularVelocity(0),
				  angularAcceleration(0),
				  torque(1),
				  angularDrag(0.25)
	{

	}

	void integrate(transform &T, float dt)
	{
		acceleration += force / mass;
		velocity += acceleration * dt + impulse/mass;
		T.position += velocity * dt;

		impulse = force = { 0,0 };

		force = -velocity * drag;

		//-------------------

		angularAcceleration = torque / mass;
		angularVelocity += angularAcceleration * dt;
		T.angle += angularVelocity * dt;
		torque = -angularVelocity * angularDrag;
	}



};