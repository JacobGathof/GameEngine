#pragma once
#include "Shape.h"
#include "ResourceManager.h"

class Circle : public Shape
{
public:
	virtual bool contains(Vector2f& pt);
	Circle(Vector2f& c, float rad);
	~Circle();
	void draw();
	Vector2f center;
	float radius;

	bool intersects(Circle* c);

private:
	
};

