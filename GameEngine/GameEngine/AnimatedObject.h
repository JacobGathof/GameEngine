#pragma once

#include "Object.h"
#include "CharacterTimer.h"
#include "SpriteSheet.h"
#include "AI.h"

class AnimatedObject : public Object
{
public:
	AnimatedObject(TextureType t, Vector2f position, Vector2f sc);
	AnimatedObject();
	~AnimatedObject();

	CharacterTimer timer;
	int animationState;
	SpriteSheet::AnimationState currentAction;
	float animationSpeed;

	virtual void setAI(AI * ai);
	void setAction(SpriteSheet::AnimationState action);
	virtual void draw();
	virtual bool update(float delta_time);
	virtual bool collide(Object * o);

protected:
	AI * defaultAI;
	std::vector<AI *> aiQueue;
};

