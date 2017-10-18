#pragma once
#include"vec2.h"
#include "vec3.h"
#include<cmath>
int min(int a, int b);

float getMag(vec2 vect2_a);
//angle of a single 2D vector
float getVecDirec(vec2 vect2_a);
//returns a normalized vector
vec2 normVec(vec2 vect2_a);
//returns a normalized vector via a reference
vec2 &normalizeVec(vec2 & vect2_a);
//The dot product
float dotProd(vec2 vect2_a, vec2 vect2_b);
//the angle between two vectors
float vectAngle(vec2 vect2_a, vec2 vect2_b);
//distance between 2 points
float pointDist(vec2 vect2_a, vec2 vect2_b);
//returns the perpendicular vector
vec2 perpVect(vec2 vect2_a);
//returns a a linearly blended vector between the specified
//start and end vector at an alpha/time represented by the
//normalized value of a/t
vec2 lerp(vec2 start, vec2 end, float time);

vec2 min(vec2 vect2_a,vec2 vect2_b);

vec2 max(vec2 vect2_a, vec2 vect2_b);

#define EPSILON 0.0000006



//vec3 Items----------------------------------------------------------------------------------------




vec3 crossProd(vec3 _A, vec3 _B );

float dotProd(vec3 _A, vec3 _B);

float getMag(vec3 _A);

vec3 lerp(vec3 start, vec3 end, float percent);

vec3 normVec(vec3 _A);

vec3 &normalizeVec(vec3 & _A);
//the angle between two vectors
float vectAngle(vec3 _A, vec3 _B);

vec3 min(vec3 _A, vec3 _B);

vec3 max(vec3 _A, vec3 _B);



