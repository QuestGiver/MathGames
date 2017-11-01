#include "Shapes.h"
#include "mathUtils.h"


circle operator*(const mat3 & M, const circle & C)
{
	circle ret = C;

	ret.position = (M * vec3{ (C.position.x, C.position,(float)1) }).xy;

	vec2 scale;
	scale.x = getMag(M[0].xy);
	scale.y = getMag(M[1].xy);
	//average?

	ret.radius *= fmaxf(scale.x, scale.y);

	return ret;


}



AABB operator*(const mat3 & M, const AABB & B)
{

	AABB retval;

	vec2 TL = { B.position.x - B.extents.x, B.position.y + B.extents.y }; //TL
	vec2 TR = B.position + B.extents; // TR
	vec2 BL = B.position - B.extents; // BL
	vec2 BR = { B.position.x + B.extents.x, B.position.y - B.extents.y };  // 

	TR = (M * vec3{ TR.x, TR.y,1 }).xy;
	BL = (M * vec3{ BL.x, BL.y,1 }).xy;
	TL = (M * vec3{ TL.x, TL.y,1 }).xy;
	BR = (M * vec3{ BR.x, BR.y,1 }).xy;


	vec2 Mincorner = min(TR, min(BL, min(TL, BR)));
	vec2 MaxCorner = max(TR, max(BL, max(TL, BR)));

	retval.position = (Mincorner + MaxCorner) / 2;
	retval.extents = (MaxCorner - Mincorner) / 2;

	return retval;
}

//void Draw(const AABB & A)
//{
//	vec2 c = A.position - A.extents; //BL
//	vec2 b = A.position + A.extents; // TR
//	vec2 a = { c.x, b.y }; // TL
//	vec2 d = { b.x,c.y }; // BR
//
//
//	sfw::drawLine(c.x, c.y, a.x, a.y, GREEN);
//	sfw::drawLine(a.x, a.y, b.x, b.y, GREEN);
//	sfw::drawLine(b.x, b.y, d.x, d.y, GREEN);
//	sfw::drawLine(d.x, d.y, c.x, c.y, GREEN);
//}
