#include "Line.h"


Line::Line(Vector2f & v1, Vector2f & v2)
{
	p1 = v1;
	p2 = v2;
}

Line::~Line()
{
}

bool Line::contains(Vector2f & pt)
{
	return p1[0]*(p2[1]-pt[1]) + p2[0]*(pt[1] - p1[1]) + pt[0]*(p1[1] - p2[1]) == 0;
}
