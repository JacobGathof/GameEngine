#include "AnimatedObject.h"


AnimatedObject::AnimatedObject(std::string name, TextureType t, Vector2f position, Vector2f sc) : Object(name, t, position, sc)
{
	
}

AnimatedObject::AnimatedObject()
{
}


AnimatedObject::~AnimatedObject()
{
}

void AnimatedObject::setAction(SpriteSheet::AnimationState action)
{
}

void AnimatedObject::draw()
{
	Object::draw();
}


bool AnimatedObject::update(float delta_time)
{
	//timer.tick(delta_time);
	bool isFinished = Object::update(delta_time);
	if (aiQueue.size() == 0) {
		if (defaultAI != 0) {
			defaultAI->execute(this, delta_time);
		}
	}
	else {
		if (aiQueue.get(0)->execute(this, delta_time)) {
			//If the current AI is done, remove it
			AI * ai = aiQueue.get(0);
			aiQueue.removeIndex(0);
			delete ai;
		}
	}
	return isFinished;
}

bool AnimatedObject::collide(Object * o, Hitbox * h)
{
	return false;
}
