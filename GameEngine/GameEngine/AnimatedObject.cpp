#include "AnimatedObject.h"


AnimatedObject::AnimatedObject(TextureType t, Vector2f position, Vector2f sc) : Object(t, position, sc)
{
	
}

AnimatedObject::AnimatedObject()
{
}


AnimatedObject::~AnimatedObject()
{
}

void AnimatedObject::setAI(AnimatedAi * ai)
{
	if (aiQueue.size() == 0 && defaultAI == nullptr) {
		defaultAI = ai;
	}
	else {
		aiQueue.push_back(ai);
	}
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
		defaultAI->execute(this);
	}
	else {
		if (!aiQueue.at(0)->execute(this)) {
			//If the current AI is done, remove it
			aiQueue.erase(aiQueue.begin());
		}
	}
	return isFinished;
}

bool AnimatedObject::collide(Object * o)
{
	return false;
}

void AnimatedObject::interact()
{
}
