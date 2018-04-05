#pragma once

#include "../GameEngine/ComplexPolygon.h"

class ComplexPolygonTest : public ComplexPolygon
{
public:
	ComplexPolygonTest(std::initializer_list<Vector2f> vert);
	~ComplexPolygonTest();
};

