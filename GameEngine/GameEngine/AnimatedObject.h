#pragma once

#include "Object.h"
#include "Timer.h"
#include "SpriteSheet.h"
#include "AnimatedAi.h"

class AnimatedObject : public Object
{
public:
	AnimatedObject(std::string name, TextureType t, Vector2f position, Vector2f sc);
	AnimatedObject();
	virtual ~AnimatedObject();

	Timer timer;
	int animationState;
	SpriteSheet::AnimationState currentAction;
	float animationSpeed;

	void setAction(SpriteSheet::AnimationState action);
	virtual void draw();
	virtual bool update(float delta_time);
	virtual bool collide(Object * o, Hitbox * h);

protected:
	
};

