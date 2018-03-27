#include "TextureManager.h"


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

	addTexture(TextureType::SPRITESHEET_MELODY, "res/tex/Melody_SS.png", 4, 3);

	addTexture(TextureType::SWORD_ICON, "res/tex/sword_icon.png");
	addTexture(TextureType::TERRAIN_SHEET, "res/tex/terrainSheet.png");


	addTexture(TextureType::CARD_GHOST, "res/tex/Card_Ghost.png");
	addTexture(TextureType::CARD_ACE, "res/tex/Card_Ace.png");

}

void TextureManager::addTexture(TextureType tex, char * filename, int rows, int columns) {
	SpriteSheet * t = new SpriteSheet(filename, rows, columns);
	elements[tex] = t;
}
