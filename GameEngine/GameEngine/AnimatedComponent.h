#pragma once
#include "Timer.h"
#include "SpriteSheet.h"
#include "AbstractObjectComponent.h"

class AnimatedComponent : public AbstractObjectComponent
{
public:
	AnimatedComponent();
	~AnimatedComponent();

	static AnimatedComponent comp;
	static AnimatedComponent* getComponent();

	virtual bool update(float dt);
	void setAction(SpriteSheet::AnimationState action);
	bool finishedAnimation();


	int animationRow = 0;
	int animationColumn = 0;

protected:
	Timer timer;
	Timer animationTimer;

	int animationState = 0;
	int animationLoop = true;
	int animationCurrentColumns = 1;

	float animationSpeed;

};

