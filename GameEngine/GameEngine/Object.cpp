#include "Object.h"


Object::Object()
{
	texture = TextureType::TEXTURE_DEFAULT;
	pos = Vector2f(0,0);
	scale = Vector2f(.25,.25);
}

Object::Object(TextureType t, Vector2f position, Vector2f sc)
{
	texture = t;
	pos = position;
	scale = sc;
}


Object::~Object()
{
	for (Effect * eff : effects) {
		delete eff;
	}
}

void Object::draw()
{
	if (texture == TextureType::TEXTURE_MELODY) {
		std::cout << "Melody";
	}
	
	ShaderProgram* p = Res::get(ShaderType::BASIC_SHADER);
	p->bind();
	p->loadVector2f("translate", pos);
	p->loadVector2f("scale", scale);
	Model * m = Res::get(ModelType::MODEL_SQUARE_CENTERED);
	m->bind();
	Res::get(texture)->bind();

	m->draw();
	for (Effect * eff : effects) {
		eff->draw();
	}
}

bool Object::update(float delta_time)
{
	for (Effect * eff : effects) {
		eff->update(delta_time);
	}
	return alive;
}

bool Object::collide(Object * o)
{
	return false;
}

void Object::addEffect(Effect * eff)
{
	effects.push_back(eff);
}
