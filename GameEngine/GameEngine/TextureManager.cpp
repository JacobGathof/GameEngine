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
	addTexture(TextureType::BRIDGEHORIZ, "res/tex/ImageFiles/bridgeHoriz.png");
	addTexture(TextureType::LARGE_TREE, "res/tex/ImageFiles/large tree.png");
	addTexture(TextureType::PINK_FLOWERS_2, "res/tex/ImageFiles/pink flowers 2.png");
	addTexture(TextureType::BLUE_FLOWERS_2, "res/tex/ImageFiles/blue flowers 2.png");
	addTexture(TextureType::PINK_FLOWERS, "res/tex/ImageFiles/Pink Flowers.png");
	addTexture(TextureType::SMALL_LEAF_SHRUB, "res/tex/ImageFiles/small leaf shrub.png");
	addTexture(TextureType::TALL_GRASS, "res/tex/ImageFiles/Tall Grass.png");
	addTexture(TextureType::ROCK, "res/tex/ImageFiles/rock.png");
	addTexture(TextureType::MUSHROOMS, "res/tex/ImageFiles/mushrooms.png");
	addTexture(TextureType::LOG, "res/tex/ImageFiles/Log.png");
	addTexture(TextureType::BLUE_FLOWERS, "res/tex/ImageFiles/blue flowers.png");

	addTexture(TextureType::CARD_GHOST, "res/tex/Card_Ghost.png");
	addTexture(TextureType::CARD_ACE, "res/tex/Card_Ace.png");

	addTexture(TextureType::TEXTURE_SKYBOX, "res/tex/Skybox.png");
	addTexture(TextureType::PERLIN_NOISE, "res/tex/perlin_displacement.png");

}

void TextureManager::addTexture(TextureType tex, char * filename, int rows, int columns) {
	SpriteSheet * t = new SpriteSheet(filename, rows, columns);
	elements[tex] = t;
}
