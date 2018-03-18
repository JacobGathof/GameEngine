#include "SpriteSheet.h"



SpriteSheet::SpriteSheet(char* filename, int r, int c) : Texture(filename)
{
	rows = r;
	columns = c;
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
