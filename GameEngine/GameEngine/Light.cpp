#include "Light.h"
#include "Object.h"

Light::Light(Vector2f & off, Color & c)
{
	offset = off;
	color = c;

}

Light::~Light()
{
}

void Light::draw()
{
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	ShaderProgram* p = Res::get(ShaderType::LIGHT_SHADER);
	p->bind();
	p->loadVector2f("translate", parent->pos + offset);
	p->loadVector2f("scale", 2 * Vector2f(512, 512));
	p->loadColor("color", color);
	Model * m = Res::get(ModelType::MODEL_SQUARE_CENTERED);
	m->bind();

	m->draw();
}

bool Light::update(float dt)
{
	return true;
}
