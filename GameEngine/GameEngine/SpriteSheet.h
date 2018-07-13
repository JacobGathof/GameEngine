#pragma once

#include <map>
#include "Texture.h"

class SpriteSheet : public Texture
{
public:

	enum AnimationState
	{
		NONE,
		IDLE,
		MOVE_RIGHT,
		MOVE_LEFT,
		MOVE_UP,
		MOVE_DOWN,
		ATTACK
	};

	struct AnimationStruct {
		int row;
		int numColumns;
		float animSpeed;
		int loop;
		AnimationState next = NONE;
	};

	SpriteSheet(char* filename, int rows, int columns);
	SpriteSheet(char* filename, int rows, int columns, std::vector<AnimationState> states, std::vector<AnimationStruct> structs);
	virtual ~SpriteSheet();

	int rows, columns;

	std::map<AnimationState, AnimationStruct> animations;
	AnimationState state = NONE;

	void setDefault(AnimationState anim);
	void addAnimation(AnimationState state, AnimationStruct anim);
};

