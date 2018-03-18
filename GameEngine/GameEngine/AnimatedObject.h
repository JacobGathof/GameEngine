#pragma once

#include "Object.h"
#include "Timer.h"
#include "SpriteSheet.h"
#include "AnimatedAi.h"

class AnimatedObject : public Object
{
public:
	AnimatedObject(std::string name, TextureType t, Vector2f position, Vector2f sc);
	~AnimatedObject();

	Timer timer;
	Timer animationTimer;

	int animationState;
	int animationRow = 3;
	int animationColumn = 0;

	SpriteSheet::AnimationState currentAction;
	float animationSpeed;

	void setAction(SpriteSheet::AnimationState action);
	virtual void draw();
	virtual bool update(float delta_time);
	virtual bool collide(Object * o);
	virtual void interact();

protected:
	
};

