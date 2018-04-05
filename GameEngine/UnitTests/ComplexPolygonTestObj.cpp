#include "stdafx.h"
#include "ComplexPolygonTestObj.h"


ComplexPolygonTest::ComplexPolygonTest(std::initializer_list<Vector2f> vert)
{
	vertices.addAll(vert);
	vboSet = false;
	for (int i = 1; i <= vertices.size(); i++) {
		Vector2f p1 = vertices.get(i % vertices.size());
		Vector2f p2 = vertices.get(i - 1);
		Vector2f vec((p1[0] - p2[0]), (p1[1] - p2[1]));
		Vector2f norm(vec[1], -vec[0]);
		normals.add(norm.normalize());
	}
}

ComplexPolygonTest::~ComplexPolygonTest()
{
}
