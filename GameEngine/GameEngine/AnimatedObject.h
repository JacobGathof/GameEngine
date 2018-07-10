#pragma once

#include "Object.h"
#include "Timer.h"
#include "SpriteSheet.h"

#include "CollidableObject.h"

class AnimatedObject : public CollidableObject
{
public:
	AnimatedObject(std::string& name, TextureType t, Vector2f& position, Vector2f& sc);
	virtual ~AnimatedObject();

	void setAction(SpriteSheet::AnimationState action);
	virtual void draw();
	virtual bool update(float dt);

protected:
	Timer timer;
	Timer animationTimer;

	int animationState;
	int animationLoop = true;
	int animationCurrentColumns = 1;

	SpriteSheet::AnimationState currentAction;
	float animationSpeed;

};

