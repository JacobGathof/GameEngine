#pragma once

#include "Shape.h"
#include "Vector2f.h"
#include "ResourceManager.h"

class Rect : public Shape
{
public:
	Rect(Vector2f pos, Vector2f size);
	Rect();
	~Rect();

	Vector2f center;
	Vector2f scale;

	virtual bool contains(Vector2f& pt);
	void draw();
};

