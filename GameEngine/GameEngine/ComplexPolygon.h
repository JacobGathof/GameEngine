#pragma once
#include "Shape.h"
#include "List.h"
#include "Vector2f.h"

class ComplexPolygon : public Shape
{
public:
	ComplexPolygon(Vector2f vert[]);
	ComplexPolygon();
	~ComplexPolygon();

	List<Vector2f> vertices;

	void draw(float gt);
	virtual bool contains(Vector2f& pt);
};

