#include "Shapes.h"
#include "mathUtils.h"

circle operator*(const mat3 & M, const circle & C)
{
	circle ret = C;

	ret.position = (M * vec3{ (C.position.x, C.position,1) }).xy;

	vec2 scale;
	scale.x = getMag(M[0].xy);
	scale.y = getMag(M[1].xy);
	//average?

	ret.radius *= fmaxf(scale.x, scale.y);

	return ret;


}



AABB operator*(const mat3 & M, const AABB & B)
{

}
