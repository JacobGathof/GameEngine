#pragma once
#include <map>
#include "Texture.h"


enum class TextureType {
	TEXTURE_DEFAULT,
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

