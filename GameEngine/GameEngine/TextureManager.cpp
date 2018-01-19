#include "TextureManager.h"


std::map<TextureType, Texture*> TextureManager::textures;

void TextureManager::init() {
	addTexture(TextureType::TEXTURE_DEFAULT, "res_test/default.png");
	addTexture(TextureType::TEXTURE_MELODY, "res_test/melody.png");
}

void TextureManager::clean() {
	for (auto pair : textures) {
		delete pair.second;
	}
}

Texture * TextureManager::get(TextureType type)
{
	return textures[type];
}

void TextureManager::addTexture(TextureType tex, char * filename) {
	Texture * t = new Texture(filename);
	textures[tex] = t;
}
