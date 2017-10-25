#pragma once
#include "Transform.h"
class player : public transform
{

	float t;

public:
	//magnitude of accel

	bool enabled;

	vec2 accel;
	float speed;// getMag(accel);
	float rad;
	float drag;


	bool button;
	bool up;
	bool down;
	bool left;
	bool right;


	transform myTransform;

	transform myVerts[8];

	player();

	void update();
	void draw();
};


