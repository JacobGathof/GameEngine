#include "Rectangle.h"



Rect::Rect()
{
}


Rect::Rect(Vector2f pos, Vector2f size)
{
	center = pos;
	scale = size;

	Vector2f topRight = Vector2f(center[0] + scale[0] / 2.0f, center[1] + scale[1] / 2.0f);
	Vector2f bottomLeft = Vector2f(center[0] - scale[0] / 2.0f, center[1] - scale[1] / 2.0f);
	Vector2f topLeft = Vector2f(center[0] - scale[0] / 2.0f, center[1] + scale[1] / 2.0f);
	Vector2f bottomRight = Vector2f(center[0] + scale[0] / 2.0f, center[1] - scale[1] / 2.0f);

	vertices.add(topRight);
	vertices.add(topLeft);
	vertices.add(bottomLeft);
	vertices.add(bottomRight);
}

Rect::~Rect()
{
}

bool Rect::contains(Vector2f & pt)
{
	return false;
}

void Rect::draw()
{
	
	ShaderProgram* p = Res::get(ShaderType::RECTANGLE_SHADER);
	p->bind();
	p->loadVector2f("translate", center);
	p->loadVector2f("scale", scale);
	Model * m = Res::get(ModelType::MODEL_SQUARE_CENTERED);
	m->bind();
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	m->draw();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

List<Vector2f>& Rect::getVertices()
{
	//TODO:  Refactor this to get rid of the ret variable here and in ComplexPolygon.  Not hard, just don't have time now
	ret.clear();

	Vector2f topRight = Vector2f(center[0] + scale[0] / 2.0f, center[1] + scale[1] / 2.0f);
	Vector2f bottomLeft = Vector2f(center[0] - scale[0] / 2.0f, center[1] - scale[1] / 2.0f);
	Vector2f topLeft = Vector2f(center[0] - scale[0] / 2.0f, center[1] + scale[1] / 2.0f);
	Vector2f bottomRight = Vector2f(center[0] + scale[0] / 2.0f, center[1] - scale[1] / 2.0f);

	ret.add(topRight);
	ret.add(topLeft);
	ret.add(bottomLeft);
	ret.add(bottomRight);

	return ret;
}
