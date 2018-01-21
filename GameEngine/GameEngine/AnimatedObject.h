#pragma once

#include "Object.h"
#include "CharacterTimer.h"
#include "SpriteSheet.h"

class AnimatedObject : public Object
{
public:

	AnimatedObject();
	~AnimatedObject();

	CharacterTimer timer;
	int animationState;
	SpriteSheet::AnimationState currentAction;
	float animationSpeed;

	void setAction(SpriteSheet::AnimationState action);
	virtual void draw();
	virtual bool update(float delta_time);
	virtual bool collide(Object * o);
};

