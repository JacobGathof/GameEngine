#pragma once
#include "SpriteSheet.h"
#include "IManager.h"
#include "ResourceType.h"


class TextureManager : public IManager<SpriteSheet, TextureType>
{
public:
	virtual void init();

private:
	void addTexture(TextureType tex, char* filename, int rows = 1, int columns = 1);
	void addSpriteSheet(TextureType tex, char* filename, int rows, int columns, std::vector<SpriteSheet::AnimationState> states, std::vector<SpriteSheet::AnimationStruct> structs);
	void initSpritesheets();
};

