#include "ComplexHitbox.h"
#include "CircleHitbox.h"
#include "RectHitbox.h"



ComplexHitbox::ComplexHitbox(ComplexPolygon* p, Vector2f off)
{
	shape = p;
	offset = off;
}

ComplexHitbox::~ComplexHitbox()
{
	delete shape;
}

bool ComplexHitbox::collide(Hitbox * s)
{
	return s->collide(this);
}

bool ComplexHitbox::collide(CircleHitbox * h)
{
	return CollisionUtil::collide(*h,*this);
}

bool ComplexHitbox::collide(RectHitbox * h)
{
	return CollisionUtil::collide(*h,*this);
}

bool ComplexHitbox::collide(ComplexHitbox * h)
{
	return CollisionUtil::collide(*h,*this);
}

void ComplexHitbox::draw()
{
	shape->base = pos;
	for (int i = 0; i < shape->vertices.size(); i++) {
		shape->vertices.get(i) += pos;
	}

	shape->draw();
}
