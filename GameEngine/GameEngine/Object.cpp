#include "Object.h"
#include "ResourceManager.h"


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
	for (auto ai : aiQueue) {
		delete ai;
	}
	delete defaultAI;
}

void Object::draw()
{	
	ShaderProgram* p = Res::get(ShaderType::ANIMATED_SHADER);
	SpriteSheet* sh = Res::get(texture);
	Model * m = Res::get(ModelType::MODEL_SQUARE_CENTERED);

	m->bind();
	sh->bind();

	p->bind();
	p->loadVector2f("translate", pos);
	p->loadVector2f("scale", scale);

	p->loadInteger("rows", 1);
	p->loadInteger("columns", 1);
	p->loadInteger("currentRow", 0);
	p->loadInteger("currentColumn", 0);

	p->loadInteger("selected", selected);
	p->loadFloat("rotation", rotation);

	m->draw();
	
}

void Object::drawEffects()
{
	for (Effect * eff : effects) {
		eff->draw();
	}
}

void Object::destroy(){
	alive = false;
}

bool Object::update(float dt)
{
	for (int i = 0; i < effects.size(); i++) {
		bool b = effects[i]->update(dt);
		if (!b) {
			delete effects[i];
			effects.removeIndex(i--);
		}
	}

	if (aiQueue.size() == 0) {
		if (defaultAI != 0) {
			executeAI(dt, defaultAI);
		}
	}
	else {
		if (executeAI(dt, aiQueue[0])) {
			//If the current AI is done, remove it
			AI * ai = aiQueue[0];
			aiQueue.removeIndex(0);
			delete ai;
		}
	}

	return alive;
}

bool Object::executeAI(float dt, AI * ai)
{
	return ai->execute(this, dt);
}


void Object::addEffect(Effect * eff)
{
	eff->setParent(this);
	effects.add(eff);
}

void Object::removeEffect(Effect * eff)
{
	effects.remove(eff);
}


