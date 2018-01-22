#include "AnimatedObject.h"



AnimatedObject::AnimatedObject(TextureType t, Vector2f position, Vector2f sc)
{
	Object(t, position, sc);
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
	return Object::update(delta_time);
}

bool AnimatedObject::collide(Object * o)
{
	return false;
}
