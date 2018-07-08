#include "TextureManager.h"


void TextureManager::init() {
	addTexture(TextureType::TEXTURE_DEFAULT, "res/tex/default.png");

	addTexture(TextureType::TEXTURE_MELODY, "res/tex/melody.png");
	addTexture(TextureType::TEXTURE_MELODY_BOOK, "res/tex/melody_book.png");
	addTexture(TextureType::TEXTURE_MAVIS, "res/tex/mavis.png");
	addTexture(TextureType::TEXTURE_PANDORA, "res/tex/pandora.png");
	addTexture(TextureType::TEXTURE_NARCISSUS, "res/tex/narc.png");
	addTexture(TextureType::TEXTURE_ANUBIS, "res/tex/anubis.png");
	addTexture(TextureType::TEXTURE_HORUS, "res/tex/horus.png");
	addTexture(TextureType::TEXTURE_DAGON, "res/tex/dagon.png");
	addTexture(TextureType::TEXTURE_SLIME, "res/tex/slime.png");
	
	addTexture(TextureType::SWORD_ICON, "res/tex/sword_icon.png");
	//addTexture(TextureType::TERRAIN_SHEET, "res/tex/terrainSheet.png");
	//Start old textures
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
	//End old textures

	//Start new Textures
	addTexture(TextureType::FALLEN_TREE, "res/tex/ObjectImages/fallen_Tree.png");
	addTexture(TextureType::FLOWER, "res/tex/ObjectImages/flower.png");
	addTexture(TextureType::FLOWER_2, "res/tex/ObjectImages/flower_2.png");
	addTexture(TextureType::FLOWER_3, "res/tex/ObjectImages/flower_3.png");
	addTexture(TextureType::MUSHROOM, "res/tex/ObjectImages/mushroom.png");
	addTexture(TextureType::MAIN_TREE_PINK_3, "res/tex/ObjectImages/main_tree_pink_3.png");
	//End old Textures
	
	addTexture(TextureType::T_CARD_GHOST, "res/tex/Card_Ghost.png");
	addTexture(TextureType::T_CARD_ACE, "res/tex/Card_Ace.png");

	addTexture(TextureType::TEXTURE_SKYBOX, "res/tex/Skybox.png");
	addTexture(TextureType::PERLIN_NOISE, "res/tex/perlin_displacement.png");

	addTexture(TextureType::TS_TILESET, "res/tex/test.png");

	addTexture(TextureType::TEXTURE_TEST, "res/tex/clearing_bottom.png");
	addTexture(TextureType::TEXTURE_TEST_2, "res/tex/clearing_middle.png");
	addTexture(TextureType::TEXTURE_TEST_3, "res/tex/clearing_top.png");

	addTexture(TextureType::ARROW_TEXTURE, "res/tex/Arrow.png");
	
	addTexture(TextureType::ZH_WARDROBE, "res/tex/Table.png");
	addTexture(TextureType::ZF_GILGAMESH, "res/tex/ImageFiles/zf-Gilgamesh.png");
	addTexture(TextureType::ZI_ZMELODY_BOOK, "res/tex/ImageFiles/zi_zMelody_Book.png");
	addTexture(TextureType::ZH_HORIZONTAL_TABLE, "res/tex/ImageFiles/zh-horizontal table.png");
	addTexture(TextureType::ZH_NIGHT_WINDOW_LARGE, "res/tex/ImageFiles/zh-night window large.png");
	addTexture(TextureType::ZH_TOMATO_BASKET, "res/tex/ImageFiles/zh-tomato basket.png");
	addTexture(TextureType::ZH_WATER_GLASS, "res/tex/ImageFiles/zh-water glass.png");
	addTexture(TextureType::ZH_BREAD_BASKET, "res/tex/ImageFiles/zh-bread basket.png");
	addTexture(TextureType::ZH_CANDLE_POST, "res/tex/ImageFiles/zh-candle post.png");


	initSpritesheets();
}

void TextureManager::addTexture(TextureType tex, char * filename, int rows, int columns) {
	SpriteSheet * t = new SpriteSheet(filename, rows, columns);
	elements[tex] = t;
}

void TextureManager::addSpriteSheet(TextureType tex, char * filename, int rows, int columns, std::vector<SpriteSheet::AnimationState> states, std::vector<SpriteSheet::AnimationStruct> structs)
{
	SpriteSheet * t = new SpriteSheet(filename, rows, columns, states, structs);
	elements[tex] = t;
}

void TextureManager::initSpritesheets()
{
	typedef SpriteSheet::AnimationState a;
	typedef SpriteSheet::AnimationStruct aa;
	std::vector<SpriteSheet::AnimationState> states =	{a::IDLE,		a::MOVE_RIGHT,	a::MOVE_LEFT,	a::MOVE_UP,		a::MOVE_DOWN};
	std::vector<SpriteSheet::AnimationStruct> structs = { aa{3,3,1,-1},	aa{ 0,3,1,-1 },	aa{ 1,3,1,-1 } ,	aa{ 2,3,1,-1 } , aa{ 3,3,1,-1 } };

	addSpriteSheet(TextureType::SPRITESHEET_MELODY, "res/tex/Melody_SS.png", 4, 3, states, structs);
}

