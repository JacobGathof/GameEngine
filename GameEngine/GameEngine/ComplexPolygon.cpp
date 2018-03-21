#include "ComplexPolygon.h"



ComplexPolygon::ComplexPolygon(Vector2f vert[])
{
	for (int i = 0; i < sizeof(vert) / sizeof(Vector2f); i++) {
		vertices.add(vert[i]);
	}
}

ComplexPolygon::ComplexPolygon()
{
}

ComplexPolygon::~ComplexPolygon()
{
}

void ComplexPolygon::draw(float gt)
{
}

bool ComplexPolygon::contains(Vector2f & pt)
{
	return false;
}
