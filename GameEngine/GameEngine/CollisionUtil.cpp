#include "CollisionUtil.h"
#include "RectHitbox.h"
#include "CircleHitbox.h"
#include "ComplexHitbox.h"


CollisionUtil::CollisionUtil()
{
}


CollisionUtil::~CollisionUtil()
{
}

bool CollisionUtil::collide(CircleHitbox c1, CircleHitbox c2)
{
	float dist = (c1.pos + c1.offset).distanceTo((c2.pos + c2.offset));
	float sumRad = c1.shape.radius + c2.shape.radius;
	std::cout << dist << "   +    " << sumRad << std::endl;
	if (dist < sumRad) {
		return true;
	}

	return false;
}

bool CollisionUtil::collide(RectHitbox r1, RectHitbox r2)
{
	float x1 = r1.pos[0] + r1.offset[0];
	float y1 = r1.pos[1] + r1.offset[1];
	float xScale1 = r1.shape.scale[0];
	float yScale1 = r1.shape.scale[1];

	float x2 = r2.pos[0] + r2.offset[0];
	float y2 = r2.pos[1] + r2.offset[1];
	float xScale2 = r2.shape.scale[0];
	float yScale2 = r2.shape.scale[1];
	if (x1 < x2 + xScale2 && x2 < x1 + xScale1) {
		if (y1 < y2 + yScale2 / 2 && y2 < y1 + yScale1 / 2) {
			return true;
		}
	}
	return false;
}

bool CollisionUtil::collide(ComplexHitbox c1, ComplexHitbox c2)
{
	return false;
}

bool CollisionUtil::collide(CircleHitbox c1, RectHitbox r1)
{

	float distX = abs(c1.pos[0] - r1.pos[0]);
	float distY = abs(c1.pos[1] - r1.pos[1]);

	if (distX > r1.shape.scale[0] / 2 + c1.shape.radius) {
		return false;
	}
	else if (distY > r1.shape.scale[1] / 2 + c1.shape.radius) {
		return false;
	}
	else if (distX < r1.shape.scale[0] / 2) {
		return true;
	}
	else if (distY < r1.shape.scale[1] / 2) {
		return true;
	}

	float distCorner = r1.pos.distanceTo(r1.pos + Vector2f(r1.shape.scale[0] / 2, r1.shape.scale[1] / 2));

	return distCorner <= pow(c1.shape.radius,2);
}

bool CollisionUtil::collide(CircleHitbox c1, ComplexHitbox c2)
{
	return false;
}

bool CollisionUtil::collide(RectHitbox r1, ComplexHitbox c1)
{
	return false;
}
