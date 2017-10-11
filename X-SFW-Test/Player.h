#pragma once
#include"vec2.h"
class player
{
public:
	vec2 pos;

	float speed;

	void update();
	void draw();
};

class projectile
{
public:

};

class GameObject
{



public:
	//std::string name;

	bool enabled;

	vec2 a;

	virtual void update();
	virtual void draw();


};
class circleParticle : public GameObject
{
public:
	float speedX = 0;
	float speedY = 0;
	float timeSpan;	// time it's been alive
	float lifeSpan; // limit to the time it can alive
	float radius;
	vec2 Object;
	virtual void update() override;
	virtual void draw() override;
};