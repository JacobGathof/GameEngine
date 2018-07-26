#include "LivingObject.h"
#include "LivingAi.h"

/*
LivingObject::LivingObject(std::string& name, TextureType t, Vector2f& position, Vector2f& sc, int hp, int luc) : MovableObject(name, t,position, sc)
{
	health = hp;
	lucidium = luc;
	hand = new Hand();
}

LivingObject::LivingObject(std::string name, TextureType t, Vector2f position, Vector2f sc, int hp, int luc, Deck * d) : MovableObject(name, t, position, sc)
{
	deck = d;
	hand = new Hand();
}

LivingObject::~LivingObject()
{
	delete hand;
}

bool LivingObject::update(float delta_time)
{	
	if (stalled) {
		return false;
	}

	if (aiQueue.size() == 0) {
		
		if (defaultAI != nullptr && defaultAI != 0) {
			
			defaultAI->execute(this, delta_time);
		}
	}
	else {
		
		if (aiQueue.get(0)->execute(this, delta_time)) {
			AI * ai = aiQueue.get(0);
			aiQueue.removeIndex(0);
			delete ai;
		}
	}
	return MovableObject::update(delta_time);
}

bool LivingObject::collide(Object * o, Hitbox * h)
{
	return false;
}

bool LivingObject::activateCard(int i)
{
	//setAI(hand->getCard(i)->use());
	hand->getCard(i)->use();
	hand->removeCard(i);
	drawCards();
	return true;
}

void LivingObject::takeDamage(int damage)
{
	health -= damage;
	std::cout << name << " took " << damage << " damage, current health is " << health << std::endl;
}

void LivingObject::giveDeck(Deck * d)
{
	deck = d;
}

void LivingObject::shuffle()
{
	deck->shuffle();
}

void LivingObject::drawCards(int amount)
{
	for (int i = 0; i < amount; i++) {
		Card * c = deck->draw();
		if (c == nullptr) {
			
			deck->reset();
			deck->shuffle();
			c = deck->draw();
		}
		hand->addCard(c);
		std::cout << "Drew Card: " << c->getName() << std::endl;
	}
}

*/

LivingObject::LivingObject(ObjectData& data) : InteractableObject(data)
{
}

LivingObject::~LivingObject()
{
}

bool LivingObject::update(float dt)
{
	return InteractableObject::update(dt);
}

bool LivingObject::collide(Object * o, Hitbox * h)
{
	return false;
}

bool LivingObject::executeAI(float dt, AI * ai)
{
	return ai->execute(this, dt);
}
