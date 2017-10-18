#pragma once
#include"mathUtils.h"
#include"Mat3.h"
#include"vec2.h"
#include"sfwdraw.h"
class transform
{
public:
	vec2 position;
	vec2 dimension;
	float angle;

	transform();

	mat3 getLocalTransform() const;

private:

};

void DrawMatrix(const mat3 &t, float drawing_scale);

