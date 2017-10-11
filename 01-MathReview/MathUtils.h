#pragma once

struct point
{
	float x;
	float y;
};

struct bezier
{
	float x;
	float y;
	float z;
	float w;
};

float sqr(float v);
float cube(float v);
float dbl(float v);
float degToRad(float deg);
float radToDeg(float rad);
float qudratic(float a,float x, float b, float c);
float linBlend(float start, float end, float alpha);
float dst(point a, point b);
float PlanePointDst( float x, float y, float z,float a, float b, float c, float d);
float Cubezier(float t, bezier p, float l);
//Quadratic equation in a nutshell
point QuadEquate(float a, float b, float c);//, point &z);