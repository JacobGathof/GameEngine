#pragma once

#include <map>
#include "Sprite.h"

class SpriteSheet
{
public:

	struct AnimationStruct {
		int row;
		int numColumns;
		float AnimSpeed;
		bool loop;
		Sprite sprite;
	};

	enum AnimationState
	{
		IDLE,
		MOVERIGHT,
		MOVELEFT,
		MOVEUP,
		MOVEDOWN,
		ATTACK
	};

	SpriteSheet();
	~SpriteSheet();
	std::map<AnimationState, AnimationStruct> animations;
	AnimationState state = IDLE;

	void setDefault(AnimationState anim);
	void addAnimation(AnimationState state, AnimationStruct anim);
};

