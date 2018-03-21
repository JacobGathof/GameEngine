#pragma once

#include "Hitbox.h"
#include "ComplexHitbox.h"
#include "RectHitbox.h"
#include "Circle.h"

class CircleHitbox : public Hitbox
{
public:
	CircleHitbox(Circle c, Vector2f off);
	~CircleHitbox();

	Circle shape = Circle(Vector2f(1,2), 1);

	virtual bool collide(Hitbox * s);
	virtual bool collide(CircleHitbox * h);
	virtual bool collide(RectHitbox * h);
	virtual bool collide(ComplexHitbox * h);
	virtual void draw();
};

