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


	float sum = R1 + R2;
	float d = sqrt(pow(C1.position.x - C2.position.x, 2) + pow(C1.position.y - C2.position.y, 2));
	float x = (C2.position.x - C1.position.x) / d;
	float y = (C2.position.y - C1.position.y) / d;
	float p = 2 * (C1.position.x * x + C1.position.y * y - C2.position.x * x - C2.position.y * y) / (C1.speed + C2.speed);

	C1.accel.x = C1.position.x - p * C1.speed * x;
	C1.accel.y = C1.position.y - p * C1.speed * y;

	C2.accel.x = C2.position.x + p * C2.speed * x;
	C2.accel.y = C2.position.y + p * C2.speed * y;

}

Collider::Collider()
{
	d = 0;
}




