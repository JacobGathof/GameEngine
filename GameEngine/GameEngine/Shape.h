#pragma once
#include "Vector2f.h"
#include "List.h"

class Shape
{
public:
	virtual bool intersect(Shape* shape) { return false; };
	virtual bool contains(Vector2f& pt) = 0;
	virtual List<Vector2f>& getVertices();
	Shape();
	~Shape();

protected:
	List<Vector2f> vertices;


};

