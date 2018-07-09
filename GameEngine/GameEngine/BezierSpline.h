#pragma once
#include "Shape.h"

class BezierSpline : public Shape
{
public:
	BezierSpline();
	BezierSpline(Vector2f& p1, Vector2f& p2, Vector2f& p3, Vector2f& p4);
	~BezierSpline();

	virtual bool contains(Vector2f& pt) { return false; }
	void draw();
	Vector2f positionAt(float t);
	Vector2f velocityAt(float t);
	Vector2f accelerationAt( float t);

	Vector2f p1;
	Vector2f p2;
	Vector2f p3;
	Vector2f p4;

private:

};

