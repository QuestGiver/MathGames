#include "Panel.h"
#include <iostream>
#include "sfwdraw.h"
panel::panel()
{
	dt = 0;
	speed = 0;
	enabled = true;
	collider.box.extents = { 5,5 };
}

void panel::update()
{




}
void DrawVecLinez(const vec2 &a, const vec2 &b, int color)
{
	sfw::drawLine(a.x, a.y, b.x, b.y, color);
}

void drawAABBz(const AABB & box)
{
	vec2 TR = box.position + box.extents;
	vec2 BL = box.position - box.extents;
	vec2 TL = { box.position.x - box.extents.x, box.position.y + box.extents.y };
	vec2 BR = { TR.x, BL.y };

	DrawVecLinez(TR, TL, MAGENTA);
	DrawVecLinez(TL, BL, MAGENTA);
	DrawVecLinez(BL, BR, MAGENTA);
	DrawVecLinez(BR, TR, MAGENTA);


}
void panel::draw()
{
	drawAABBz(collider.getGlobalBox(panelTransform));
}



void doCollision(player & p, panel & otherP)
{
	Collision hit = collides(*p.myTransform, *p.collider, otherP.panelTransform, otherP.collider);
	
	if (hit.penetrationDepth > 0)
	{
		//static_resolution(p.myTransform->position, p.rigbdy->velocity, hit);
		dynamic_resolution(p.myTransform->position, p.rigbdy->velocity, p.rigbdy->mass, otherP.panelTransform.position, otherP.rigbdy.velocity, otherP.rigbdy.mass,hit);
	}
}
