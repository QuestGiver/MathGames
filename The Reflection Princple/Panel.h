#pragma once
#include "Rigidbody.h"
#include "Collider.h"

class panel : public transform
{



public:
	float dt;//time

	float speed;// getMag(accel);
	bool enabled;

	//vec2 accel;					|\                      
	//								| \ Depricated Variables,
	//float rad;					| /  Subsumed by Rigidbody and shapes
	//float drag;					|/

	//input variables

	//AABB aabb;

	Collider collider;

	Rigidbody rigbdy;

	transform panelTransform;

	panel();

	void update();
	void draw();
};


void doCollision(player &p, panel &otherP);