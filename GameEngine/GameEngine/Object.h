#pragma once

#include "Vector2f.h"
#include "Effect.h"
#include "List.h"
#include "Screen.h"
#include "Hitbox.h"
#include "AbstractAction.h"

#include "TextureManager.h"

#include "AI.h"

class Object
{
public:
	Object(std::string& n, TextureType t, Vector2f& position, Vector2f& sc);
	virtual ~Object();

	bool persistent = false;
	bool isStatic = false;
	bool alive = true;


	bool stalled = false;
	bool colliding = false;
	
	
	AI * defaultAI;
	bool selected = false;

	virtual void draw();
	virtual void destroy();
	virtual bool update(float dt);

	virtual bool executeAI(float dt, AI* ai);
	virtual void addAI(AI * ai);
		
	void addEffect(Effect * eff);
	void removeEffect(Effect* eff);
	void drawEffects();

	Vector2f pos;
	Vector2f scale;
	TextureType texture;
	std::string name;
	Color color = Color::White;
	float rotation;
	float depthPercentage;
	bool uniformDepth = true;

	static int numCreated;
	static int numDeleted;

protected:
	List<AI *> aiQueue;

	List<Effect *> effects;


	// Variables from AnimatedObject, but if we put them here, we can reduce duplicated code in the draw method
	int animationRow = 0;
	int animationColumn = 0;

};

