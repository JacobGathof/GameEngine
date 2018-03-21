#include "RectHitbox.h"

#include "CircleHitbox.h"
#include "ComplexHitbox.h"


RectHitbox::RectHitbox(Rect rect, Vector2f off)
{
	shape = rect;
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

void RectHitbox::draw()
{
	shape.center = pos;
	shape.draw();
}
