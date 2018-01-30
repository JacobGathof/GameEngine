#pragma once
#include "Shape.h"

class Circle : public Shape
{
public:
	virtual bool intersect(Shape* shape);
	virtual bool contains(Vector2f& pt);
	Circle(Vector2f& c, float rad);
	~Circle();

private:
	Vector2f center;
	float radius;
};

