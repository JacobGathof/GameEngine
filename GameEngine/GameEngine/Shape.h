#pragma once
#include "Vector2f.h"

class Shape
{
public:
	virtual bool intersect(Shape* shape) { return false; };
	virtual bool contains(Vector2f& pt) = 0;

	Shape();
	~Shape();

};

