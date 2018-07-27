#include "Light.h"
#include "Object.h"

Light::Light(Vector2f & off, Color & c, Vector2f& sc)
{
	offset = off;
	color = c;
	scale = sc;

}

Light::~Light()
{
}

void Light::draw()
{
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);

	ShaderProgram* p = Res::get(ShaderType::LIGHT_SHADER);
	p->bind();
	p->loadVector2f("translate", parent->pos + offset);
	p->loadVector2f("scale", scale);
	p->loadColor("color", color);
	Model * m = Res::get(ModelType::MODEL_SQUARE_CENTERED);
	m->bind();
	m->draw();
}

bool Light::update(float dt)
{
	return true;
}

void Light::setScale(Vector2f & s)
{
	scale = s;
}
