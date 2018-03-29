#include "RectHitbox.h"

#include "CircleHitbox.h"
#include "ComplexHitbox.h"


RectHitbox::RectHitbox(Rect rect, Vector2f off)
{
	shape = rect;
	pos = shape.center;

	Vector2f topRight = shape.center + (shape.scale / 2);
	Vector2f bottomLeft = shape.center - (shape.scale / 2);
	Vector2f topLeft = Vector2f(shape.center[0] - shape.scale[0]/2, shape.center[1] + shape.scale[1] / 2);
	Vector2f bottomRight = Vector2f(shape.center[0] + shape.scale[0] / 2, shape.center[1] - shape.scale[1] / 2);

	vertices.add(topRight);
	vertices.add(topLeft);
	vertices.add(bottomLeft);
	vertices.add(bottomRight);

	offset = off;
}

RectHitbox::~RectHitbox()
{
}

bool RectHitbox::collide(Hitbox * s)
{
	return s->collide(this);
}

bool RectHitbox::collide(CircleHitbox * h)
{
	return CollisionUtil::collide(*h,*this);
}

bool RectHitbox::collide(RectHitbox * h)
{
	return CollisionUtil::collide(*h,*this);
}

bool RectHitbox::collide(ComplexHitbox * h)
{
	return CollisionUtil::collide(*this, *h);
}

void RectHitbox::updatePos(Vector2f p)
{
	Hitbox::updatePos(p);
	shape.center = pos;
}

void RectHitbox::draw()
{
	shape.draw();
}
