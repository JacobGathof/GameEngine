#pragma once

#include "Vector2f.h"
#include "Effect.h"
#include "Light.h"
#include "List.h"
#include "Screen.h"
#include "Hitbox.h"
#include "AbstractAction.h"

#include "TextureManager.h"

#include "AI.h"

struct ObjectData {
	std::string name;
	Vector2f position;
	Vector2f scale;
	TextureType tex;
};

class Object
{
public:
	Object(std::string& n, TextureType t, Vector2f& position, Vector2f& sc);
	Object(ObjectData& data);
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
	void activateEffects(bool b);
	void drawEffects();

	void addLight(Light* l);
	void removeLight(Light* l);
	void drawLights();

	Vector2f pos;
	Vector2f scale;
	TextureType texture;
	std::string name;
	Color color = Color::White;

	float rotation;
	float height = 0;
	bool uniformDepth = false;

	static int numCreated;
	static int numDeleted;

	void drawInverted();
	void drawNegative();

protected:
	List<AI *> aiQueue;

	List<Effect *> effects;
	List<Light *> lights;


	// Variables from AnimatedObject, but if we put them here, we can reduce duplicated code in the draw method
	// Also allows us to eventually index into a spritesheet if need be
	int animationRow = 0;
	int animationColumn = 0;

};

