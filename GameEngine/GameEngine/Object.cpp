#include "Object.h"


Object::Object()
{
}

Object::Object(TextureType t)
{
	texture = t;
}


Object::~Object()
{
}

void Object::draw()
{
	ShaderProgram* p = Res::get(ShaderType::BASIC_SHADER);
	p->bind();
	p->loadVector2f("translate", Vector2f(0, 0));
	p->loadVector2f("scale", Vector2f(.25, .25));
	Model * m = Res::get(ModelType::MODEL_SQUARE_CENTERED);
	m->bind();
	Res::get(texture)->bind();

	m->draw();
	for (Effect eff : effects) {
		eff.draw();
	}
}

bool Object::update(float delta_time)
{
	for (Effect eff : effects) {
		eff.update(delta_time);
	}
	return alive;
}

bool Object::collide(Object * o)
{
	return false;
}
