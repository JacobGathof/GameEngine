#include "RectHitbox.h"

#include "CircleHitbox.h"
#include "ComplexHitbox.h"


RectHitbox::RectHitbox(Vector2f& scale, Vector2f& off) : shape(Vector2f(0, 0), scale)
{
	pos = shape.center;

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

void RectHitbox::updatePos(Vector2f& p)
{
	Hitbox::updatePos(p);
	shape.center = pos;
}

void RectHitbox::draw()
{
	shape.draw();
}

Shape * RectHitbox::getShape()
{
	return &shape;
}
