#include "Collider.h"
#include <cmath>
bool Collider::isColliding(vec2 a, vec2 b, float Rad1, float Rad2)
{
	float sum = Rad1 + Rad2;
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

void Collider::colResponce(player & C1, player & C2, float R1, float R2)
{
	vec2 p1Pos = C1.myTransform.getGlobalPosition();
	vec2 p2Pos = C2.myTransform.getGlobalPosition();

	float sum = R1 + R2;
	float d = sqrt(pow(p1Pos.x - p2Pos.x, 2) + pow(p1Pos.y - p2Pos.y, 2)) + 0.0001f;
	float x = (p2Pos.x - p1Pos.x) / d;
	float y = (p2Pos.y - p1Pos.y) / d;
	float p = 2 * (p1Pos.x * x + p1Pos.y * y - p2Pos.x * x - p2Pos.y * y) / (C1.speed + C2.speed);

	C1.accel.x = p1Pos.x - p * C1.speed * x;
	C1.accel.y = p1Pos.y - p * C1.speed * y;

	//return C1.accel;
	//C2.accel.x = C2.position.x + p * C2.speed * x;
	//C2.accel.y = C2.position.y + p * C2.speed * y;

}

Collider::Collider()
{
	d = 0;
}




