#include "Collider.h"
#include <cmath>
bool Collider::isColliding(vec2 a, vec2 b, float R1, float R2)
{
	float sum = R1 + R2;
	//d = distance
	float d = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
	//collide(d, sum);
	if (d < sum)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Collider::colResponce(transform & C1, transform & C2, float R1, float R2)
{
	float sum = R1 + R2;
	float d = sqrt(pow(C1.position.x - C2.position.x, 2) + pow(C1.position.y - C2.position.y, 2));
	float x = (C2.position.x - C1.position.x)/d;
	float y = (C2.position.y - C1.position.y)/d;
	float p = 2 * (C1.position.x * x + C1.position.y * y - C2.position.x * x - C2.position.y * y)/(speed);

}
