#pragma once
#include <map>
#include "Texture.h"


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

	SWORD_ICON,
	TERRAIN_SHEET,


};


class TextureManager
{
public:

	static void init();
	static void clean();
	static Texture* get(TextureType type);

private:

	static void addTexture(TextureType tex, char* filename);
	static std::map<TextureType, Texture*> textures;

};

