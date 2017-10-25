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



	transform myTransform;

	transform myVerts[8];

	player();

	void update();
	void draw();
};


