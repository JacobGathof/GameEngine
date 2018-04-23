#include "Object.h"
#include "ResourceManager.h"

Object::Object()
{
	texture = TextureType::TEXTURE_DEFAULT;
	pos = Vector2f(0,0);
	scale = Vector2f(.25,.25);
}

Object::Object(std::string& n, TextureType t, Vector2f& position, Vector2f& sc)
{
	texture = t;
	pos = position;
	scale = sc;
	name = n;
}


Object::~Object()
{
	for (auto eff : effects) {
		delete eff;
	}
	for (auto hit : hitboxes) {
		delete hit;
	}
	for (auto ai : aiQueue) {
		delete ai;
	}
	delete defaultAI;
	delete interactObj;
}

void Object::draw()
{	
	ShaderProgram* p = Res::get(ShaderType::BASIC_SHADER);
	p->bind();
	p->loadVector2f("translate", pos);
	p->loadVector2f("scale", scale);
	Model * m = Res::get(ModelType::MODEL_SQUARE_CENTERED);
	m->bind();
	Res::get(texture)->bind();
	
	m->draw();
	
}

void Object::drawEffects()
{
	for (Effect * eff : effects) {
		eff->draw();
	}
}

void Object::drawHitboxes()
{
	for (Hitbox * h : hitboxes) {
		h->draw();
	}
}

bool Object::update(float delta_time)
{
	for (Effect * eff : effects) {
		eff->update(delta_time);
	}
	updateHitbox();
	return alive;
}

void Object::updateHitbox()
{
	for (Hitbox * hit : hitboxes) {
		hit->updatePos(pos);
	}
}

bool Object::collide(Object * o, Hitbox * h)
{
	return true;
}

void Object::interact()
{
	if (stalled) {
		return;
	}
	interactObj->run();
}

void Object::setAI(AI * a)
{
	if (stalled) {
		return;
	}
	if (aiQueue.size() == 0 && defaultAI == nullptr) {
		defaultAI = a;
	}
	else {
		aiQueue.add(a);
	}
}

void Object::setInteraction(AbstractAction * i)
{
	delete interactObj;
	
	interactObj = i;
}

void Object::addEffect(Effect * eff)
{
	effects.add(eff);
}

int Object::numHitboxes()
{
	return hitboxes.size();
}

void Object::addHitbox(Hitbox * h)
{
	hitboxes.add(h);
}

Hitbox * Object::getHitbox(int i)
{
	return hitboxes.get(i);
}
