#pragma once

#include "Object.h"
#include "Timer.h"
#include "SpriteSheet.h"

#include "CollidableObject.h"

class AnimatedObject : public CollidableObject
{
public:
	AnimatedObject(ObjectData& data);
	virtual ~AnimatedObject();

	void setAction(SpriteSheet::AnimationState action);
	virtual void draw();
	virtual bool update(float dt);

	bool finishedAnimation();

protected:
	Timer timer;
	Timer animationTimer;

	int animationState = 0;
	int animationLoop = true;
	int animationCurrentColumns = 1;

	float animationSpeed;

};

