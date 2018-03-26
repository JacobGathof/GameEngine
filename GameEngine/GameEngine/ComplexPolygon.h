#pragma once
#include "Shape.h"
#include "List.h"
#include "Vector2f.h"
#include "ResourceManager.h"

class ComplexPolygon : public Shape
{
public:
	ComplexPolygon(std::initializer_list<Vector2f> vert);
	ComplexPolygon();
	~ComplexPolygon();

	unsigned int vao;
	unsigned int vbo;

	List<Vector2f> vertices;
	List<Vector2f> normals;
	Vector2f base = Vector2f(0, 0);

	void draw();
	virtual bool contains(Vector2f& pt);
	List<Vector2f> getVertices();
};

