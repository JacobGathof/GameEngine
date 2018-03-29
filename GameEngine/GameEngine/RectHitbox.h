#pragma once

#include "Hitbox.h"
#include "Rectangle.h"
#include "List.h"

class RectHitbox : public Hitbox
{
public:
	RectHitbox(Rect rect, Vector2f offset);
	~RectHitbox();

	Rect shape;
	
	List<Vector2f> vertices;

	virtual bool collide(Hitbox * s);
	virtual bool collide(CircleHitbox * h);
	virtual bool collide(RectHitbox * h);
	virtual bool collide(ComplexHitbox * h);
	virtual void updatePos(Vector2f p);
	virtual void draw();

};

