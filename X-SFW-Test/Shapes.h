#pragma once
#include "Mat3.h"
struct circle
{
	vec2 position;
	float radius;


	
};

//Axis ALigned Bounding Box
//rect without rotaion
struct AABB
{
	vec2 position;

	//four points
	//position width and hight
	//min max
	//min = smallest x and y
	//max = largest x and y
	vec3 extents;

};

circle operator*(const mat3 &M, const circle &C);

AABB operator*(const mat3 &M, const AABB &B);