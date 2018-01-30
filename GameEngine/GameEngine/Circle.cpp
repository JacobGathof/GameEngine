#include "Circle.h"



bool Circle::contains(Vector2f & pt)
{
	return (center-pt).lengthSquared() < radius*radius;
}

Circle::Circle(Vector2f& c, float rad){
	center = c;
	radius = rad;
}


Circle::~Circle()
{
}
