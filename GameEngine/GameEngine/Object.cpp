#include "Object.h"
#include "ResourceManager.h"

int Object::numCreated = 0;
int Object::numDeleted = 0;

Object::Object(std::string& n, TextureType t, Vector2f& position, Vector2f& sc)
{
	texture = t;
	pos = position;
	scale = sc;
	name = n;

	numCreated++;
}

Object::Object(ObjectData & data)
{
	texture = data.tex;
	pos = data.position;
	scale = data.scale;
	name = data.name;

	numCreated++;
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

	numDeleted++;
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
	p->loadColor("color", color);

	p->loadInteger("rows", sh->rows);
	p->loadInteger("columns", sh->columns);
	p->loadInteger("currentRow", animationRow);
	p->loadInteger("currentColumn", animationColumn);

	p->loadInteger("selected", selected);
	p->loadFloat("rotation", rotation);
	p->loadFloat("height", height);
	p->loadInteger("uniformDepth", uniformDepth);

	m->draw();
	
}

void Object::drawEffects()
{
	for (Effect * eff : effects) {
		eff->draw();
	}
}

void Object::drawInverted()
{
	Vector2f oPos = pos;
	Vector2f oScale = scale;

	pos -= Vector2f(0, scale[1]);
	scale *= Vector2f(1, -1);

	draw();

	pos = oPos;
	scale = oScale;

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

void Object::addAI(AI * a)
{
	if (stalled) {
		return;
	}
	if (defaultAI == 0) {
		defaultAI = a;
	}
	else {
		aiQueue.add(a);
	}
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

void Object::activateEffects(bool b)
{
	for (Effect * eff : effects) {
		eff->setActive(b);
	}
}


