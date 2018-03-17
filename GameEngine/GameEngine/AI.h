#pragma once
class AnimatedObject;
class Object;
class MovableObject;
class LivingObject;

class AI
{
public:
	AI();
	~AI();

	virtual bool execute(Object * obj, float dt);
	virtual bool execute(AnimatedObject * obj, float dt);
	virtual bool execute(MovableObject * obj, float dt);
	virtual bool execute(LivingObject * obj, float dt);
};

