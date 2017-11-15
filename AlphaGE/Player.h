#pragma once
//#include "Controller.h"
//#include "collider.h"
class transform;
class Rigidbody;
class Collider;
class Controller;


class player// : public transform
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
	bool button;
	bool up;
	bool down;
	bool left;
	bool right;

	Collider *collider;
	
	transform *myTransform;

	Rigidbody *rigbdy;

	Controller *ctrl;

	transform *myVerts[8];

	player();
	~player();

	void update();
	void draw();
};


void doCollision(player &p1, player &p2);