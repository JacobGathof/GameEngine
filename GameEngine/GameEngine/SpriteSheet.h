#pragma once

#include <map>
#include "Texture.h"

class SpriteSheet : public Texture
{
public:

	struct AnimationStruct {
		int row;
		int numColumns;
		float AnimSpeed;
		bool loop;
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

