#pragma once
//#include "Controller.h"

class transform;
class Rigidbody;
struct circle;
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

	circle *circ;


	
	transform *myTransform;

	Rigidbody *rigbdy;

	Controller *ctrl;

	transform *myVerts[8];



	player();

	void update();
	void draw();
};


