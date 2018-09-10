#include "Light.h"
#include "Object.h"
#include "World.h"


Light::Light(Vector2f & off, Color & c, Vector2f& sc)
{
	offset = off;
	color = c;
	scale = sc;
	decay = 1;
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
	p->loadVector2f("scale", scale*decay);
	p->loadColor("color", color);
	Model * m = Res::get(ModelType::MODEL_SQUARE_CENTERED);
	m->bind();
	m->draw();

	//glBlendFunc(GL_ONE, GL_ZERO);
	//World::getInstance()->eraseProjection(parent->pos + offset, scale[0], parent);
}

bool Light::update(float dt)
{
	decay += dt*direction;
	decay = max(0, min(1, decay));

	return true;
}

void Light::setActive(bool b)
{
	active = b;
	direction = -1 + active * 2;
}

void Light::setScale(Vector2f & s)
{
	scale = s;
}
