#pragma once

class Object;
class CollidableObject;
class InteractableObject;
class AnimatedObject;
class LivingObject;
class Player;


class AI
{
public:
	virtual bool execute(Object * obj, float dt) { return false; };
	virtual bool execute(CollidableObject * obj, float dt) { return false; };
	virtual bool execute(InteractableObject * obj, float dt) { return false; };
	virtual bool execute(AnimatedObject * obj, float dt) { return false; };
	virtual bool execute(LivingObject * obj, float dt) { return false; };
	virtual bool execute(Player * obj, float dt) { return false; };
};

