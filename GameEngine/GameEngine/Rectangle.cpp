#include "Rectangle.h"



Rect::Rect()
{
}


Rect::Rect(Vector2f pos, Vector2f size)
{
	center = pos;
	scale = size;
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
