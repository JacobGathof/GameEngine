#pragma once
#include <map>
#include "SpriteSheet.h"


enum class TextureType {
	TEXTURE_DEFAULT,
	TEXTURE_TEST,

	TEXTURE_MELODY,
	TEXTURE_MELODY_BOOK,

	TEXTURE_MAVIS,
	TEXTURE_PANDORA,
	TEXTURE_NARCISSUS,
	TEXTURE_ANUBIS,
	TEXTURE_HORUS,
	TEXTURE_DAGON,
	TEXTURE_SLIME,

	SPRITESHEET_MELODY,

	SWORD_ICON,
	TERRAIN_SHEET,


};


class TextureManager
{
public:

	static void init();
	static void clean();
	static SpriteSheet* get(TextureType type);

private:

	static void addTexture(TextureType tex, char* filename, int rows = 1, int columns = 1);
	static std::map<TextureType, SpriteSheet*> textures;

};

