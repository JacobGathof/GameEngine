#pragma once

#include "InteractableObject.h"

class LivingAi;

class LivingObject : public InteractableObject
{
public:
	LivingObject(ObjectData& data);
	//LivingObject(std::string name, TextureType t, Vector2f position, Vector2f sc, int hp, int luc, Deck * d);
	virtual ~LivingObject();

	//int health;
	//int lucidium;

	float moveSpeed = 1.0f;

	virtual bool update(float dt);
	virtual bool collide(Object * o, Hitbox * h);
	virtual bool executeAI(float dt, AI* ai);
	//virtual bool activateCard(int i);
	//virtual void takeDamage(int damage);
	//virtual void giveDeck(Deck * deck);
	//virtual void shuffle();
	//virtual void drawCards(int amout = 1);

private:
	//Deck * deck;
	//Hand * hand = 0;
};


