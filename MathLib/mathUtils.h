#pragma once
#include"vec2.h"
#include<cmath>
int min(int a, int b);
float getMag(vec2 vect2);
//angle of a single 2D vector
float getVecDirec(vec2 vect2);
//returns a normalized vector
vec2 normVec(vec2 vect2);
//returns a normalized vector via a reference
vec2 normalizeVec(vec2 & vect2);
float dotProd(vec2 vect2, vec2 vect2_b);
//the angle between two vectors
float vectAngle(vec2 vect2, vec2 vect2_b);
//distance between 2 points
float vectDist(vec2 vect2, vec2 vect2_b);
//returns the perpendicular vector
vec2 perpVect(vec2 vect2);
//returns a a linearly blended vector between the specified
//start and end vector at an alpha/time represented by the
//normalized value of a/t
vec2 lerp(vec2 start, vec2 end, float time);

vec2 min(vec2 vect2_a,vec2 vect2_b);

vec2 max(vec2 vect2_a, vec2 vect2_b);