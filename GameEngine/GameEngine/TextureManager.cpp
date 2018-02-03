#include "TextureManager.h"


std::map<TextureType, Texture*> TextureManager::textures;

void TextureManager::init() {
	addTexture(TextureType::TEXTURE_DEFAULT, "res/tex/default.png");
	addTexture(TextureType::TEXTURE_TEST, "res/tex/terraintest.png");

	addTexture(TextureType::TEXTURE_MELODY, "res/tex/melody.png");
	addTexture(TextureType::TEXTURE_MELODY_BOOK, "res/tex/melody_book.png");
	addTexture(TextureType::TEXTURE_MAVIS, "res/tex/mavis.png");
	addTexture(TextureType::TEXTURE_PANDORA, "res/tex/pandora.png");
	addTexture(TextureType::TEXTURE_NARCISSUS, "res/tex/narc.png");
	addTexture(TextureType::TEXTURE_ANUBIS, "res/tex/anubis.png");
	addTexture(TextureType::TEXTURE_HORUS, "res/tex/horus.png");
	addTexture(TextureType::TEXTURE_DAGON, "res/tex/dagon.png");
	addTexture(TextureType::TEXTURE_SLIME, "res/tex/slime.png");
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
