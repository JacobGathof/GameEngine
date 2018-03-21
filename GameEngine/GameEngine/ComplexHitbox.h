#pragma once

#include "Hitbox.h"
#include "ComplexPolygon.h"
class CircleHitbox;
class RectHitbox;

class ComplexHitbox : public Hitbox
{
public:
	ComplexHitbox(ComplexPolygon p, Vector2f off);
	~ComplexHitbox();

	ComplexPolygon shape;

	virtual bool collide(Hitbox * s);
	virtual bool collide(CircleHitbox * h);
	virtual bool collide(RectHitbox * h);
	virtual bool collide(ComplexHitbox * h);
	virtual void draw(float dt);
};

