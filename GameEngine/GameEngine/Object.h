#pragma once

#include "Vector2f.h"
#include "Effect.h"
#include "List.h"
#include "Screen.h"
#include "AI.h"
#include "Hitbox.h"
#include "AbstractAction.h"

#include "TextureManager.h"

enum class Weight {
	VERY_LIGHT,
	LIGHT,
	PLAYER,
	HEAVY,
	VERY_HEAVY,
	UNMOVABLE,
	GHOST
};

class Object
{
public:
	Object();
	Object(std::string& n, TextureType t, Vector2f& position, Vector2f& sc);
	~Object();

	Weight weight = Weight::UNMOVABLE;
	bool persistent = false;
	bool isStatic = false;
	Vector2f pos;
	Vector2f scale;
	Vector2f forward = Vector2f(0, -1);
	TextureType texture;
	bool alive = true;
	List<Effect *> effects;
	bool stalled = false;
	std::string name;
	bool colliding = false;
	AbstractAction * interactObj = new AbstractAction();
	List<Hitbox *> hitboxes;
	AI * defaultAI;

	virtual void draw();
	virtual void drawEffects();
	virtual void drawHitboxes();

	virtual bool update(float delta_time);
	virtual void updateHitbox();
	virtual bool collide(Object * o, Hitbox * h);
	virtual void interact();
	virtual void setAI(AI * ai);
	virtual void setInteraction(AbstractAction * i);

	void addEffect(Effect * eff);
	int numHitboxes();
	void addHitbox(Hitbox * h);
	Hitbox * getHitbox(int i);

protected:
	List<AI *> aiQueue;
};

