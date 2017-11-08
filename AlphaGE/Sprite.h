#pragma once
#include "Transform.h"
#include "sfwdraw.h"
class Sprite
{
public:
	int handle;
	vec2 dim;
	vec2 offset;




	Sprite(int a_handle, int width, int height) : handle(a_handle), dim{ width, height }, offset{ 0,0 }
	{

	}


	void draw(const transform &t, const mat3 &cam = mat3::identity())
	{
		mat3 M = cam * t.getGlobalTransform()*translate(offset) * scale(dim);

		sfw::drawTextureMatrix3(handle, 0, WHITE, M.m);
	}

	void draw(const AABB & A)
	{
		vec2 c = A.position - A.extents; //BL
		vec2 b = A.position + A.extents; // TR
		vec2 a = { c.x, b.y }; // TL
		vec2 d = { b.x,c.y }; // BR


		sfw::drawLine(c.x, c.y, a.x, a.y, GREEN);
		sfw::drawLine(a.x, a.y, b.x, b.y, GREEN);
		sfw::drawLine(b.x, b.y, d.x, d.y, GREEN);
		sfw::drawLine(d.x, d.y, c.x, c.y, GREEN);
	}

};
