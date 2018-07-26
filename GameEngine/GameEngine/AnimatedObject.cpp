#include "AnimatedObject.h"


AnimatedObject::AnimatedObject(ObjectData& data) : CollidableObject(data)
{
	animationTimer.setTickLength(0.25f);
}

AnimatedObject::~AnimatedObject()
{
}

void AnimatedObject::setAction(SpriteSheet::AnimationState action)
{
	if (action != animationState) {
		animationState = action;
		SpriteSheet * sh = Res::get(texture);
		SpriteSheet::AnimationStruct str = sh->animations[action];
		animationRow = str.row;
		animationLoop = str.loop;
		animationColumn = 0;
		animationCurrentColumns = str.numColumns;

		animationTimer.setTickLength(0.25f / str.animSpeed);
		//TODO speed
	}

}

void AnimatedObject::draw()
{
	CollidableObject::draw();
}


bool AnimatedObject::update(float delta_time)
{
	timer.update(delta_time);
	animationTimer.update(delta_time);

	if (animationTimer.tick()) {

		animationColumn = (animationColumn + 1) % animationCurrentColumns;
		if (animationColumn == 0 && !(animationLoop--) && animationState != SpriteSheet::AnimationState::NONE) {
			setAction(SpriteSheet::AnimationState::IDLE);
		}
	}

	return CollidableObject::update(delta_time);
}

bool AnimatedObject::finishedAnimation()
{
	return animationState == SpriteSheet::AnimationState::NONE || animationState == SpriteSheet::AnimationState::IDLE;
}

