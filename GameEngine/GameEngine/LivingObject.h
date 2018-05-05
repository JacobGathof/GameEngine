#pragma once

#include "MovableObject.h"
#include "LivingAi.h"
#include "List.h"
#include "Deck.h"
#include "Hand.h"

class LivingObject : public MovableObject
{
public:
	LivingObject(std::string& name, TextureType t, Vector2f& position, Vector2f& sc, int hp, int luc);
	LivingObject(std::string name, TextureType t, Vector2f position, Vector2f sc, int hp, int luc, Deck * d);
	virtual ~LivingObject();

	int health;
	int lucidium;

	virtual bool update(float delta_time);
	virtual bool collide(Object * o, Hitbox * h);
	virtual bool activateCard(int i);
	virtual void takeDamage(int damage);
	virtual void giveDeck(Deck * deck);
	virtual void shuffle();
	virtual void drawCards(int amout = 1);

private:
	Deck * deck;
	Hand * hand = 0;
};


