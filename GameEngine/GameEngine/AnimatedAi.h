#pragma once

class AnimatedObject;

class AnimatedAi
{
public:
	AnimatedAi();
	~AnimatedAi();

	virtual bool execute(AnimatedObject * obj, float dt);
};

