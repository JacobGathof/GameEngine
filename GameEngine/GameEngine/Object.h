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

class AbstractObjectComponent;

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
	void eraseProjection(Vector2f& center, float radius);
	void eraseHelper(Vector2f& first, Vector2f& second, Vector2f& center, float radius);

protected:
	List<AI *> aiQueue;

	List<Effect *> effects;
	List<Light *> lights;



	std::map<AbstractObjectComponent*, AbstractObjectComponent*> map;

public:
	template<class T> T* getComponent();
	template<class T> bool hasTrait();
	template<class T> void addComponent(T* t);
};

template<class T>
inline T * Object::getComponent()
{
	return (T*)map[T::getComponent()];
}

template<class T>
inline bool Object::hasTrait()
{
	return map.find(T::getComponent()) != map.end();
}

template<class T>
inline void Object::addComponent(T * t)
{
	if (hasTrait<T>()) {
		delete getComponent<T>();
	}
	map[T::getComponent()] = t;
	t->setParent(this);
}




