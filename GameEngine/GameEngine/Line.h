#pragma once
#include "Shape.h"

class Line : public Shape
{
public:
	Line(Vector2f& v1, Vector2f& v2);
	~Line();

	virtual bool contains(Vector2f& pt);

private:
	Vector2f p1;
	Vector2f p2;
};

