#include "AnimatedComponent.h"
#include "ResourceManager.h"
#include "Object.h"

AnimatedComponent AnimatedComponent::comp;

AnimatedComponent::AnimatedComponent(){
	animationTimer.setTickLength(0.125f);
}

AnimatedComponent::~AnimatedComponent()
{
}

AnimatedComponent * AnimatedComponent::getComponent()
{
	return &comp;
}




bool AnimatedComponent::update(float dt)
{
	timer.update(dt);
	animationTimer.update(dt);

	if (animationTimer.tick()) {

		animationColumn = (animationColumn + 1) % animationCurrentColumns;
		if (animationColumn == 0 && !(animationLoop--) && animationState != SpriteSheet::AnimationState::NONE) {
			setAction(SpriteSheet::AnimationState::IDLE);
		}
	}

	return true;
}

void AnimatedComponent::setAction(SpriteSheet::AnimationState action)
{
	if (action != animationState) {
		animationState = action;
		SpriteSheet * sh = Res::get(parent->texture);
		SpriteSheet::AnimationStruct str = sh->animations[action];
		animationRow = str.row;
		animationLoop = str.loop;
		animationColumn = 0;
		animationCurrentColumns = str.numColumns;

		animationTimer.setTickLength(0.125f / str.animSpeed);
		//TODO speed
	}

}

bool AnimatedComponent::finishedAnimation()
{
	return animationState == SpriteSheet::AnimationState::NONE || animationState == SpriteSheet::AnimationState::IDLE;
}
