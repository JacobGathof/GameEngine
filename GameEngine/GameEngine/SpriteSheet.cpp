#include "SpriteSheet.h"



SpriteSheet::SpriteSheet(char* filename, int r, int c) : Texture(filename)
{
	rows = r;
	columns = c;
}

SpriteSheet::SpriteSheet(char * filename, int rows, int columns, std::vector<AnimationState> states, std::vector<AnimationStruct> structs) : SpriteSheet(filename, rows, columns)
{
	for (int i = 0; i < states.size(); i++) {
		addAnimation(states[i], structs[i]);
	}
}


SpriteSheet::~SpriteSheet()
{
}

void SpriteSheet::setDefault(AnimationState anim)
{
}

void SpriteSheet::addAnimation(AnimationState state, AnimationStruct anim)
{
	animations[state] = anim;
}
