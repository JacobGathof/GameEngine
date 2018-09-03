#include "TextureManager.h"


void TextureManager::init() {
	addTexture(TextureType::TEXTURE_DEFAULT, "res/tex/default.png");
	addTexture(TextureType::T_SOLID_WHITE, "res/tex/solid_white.png");

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
	addTexture(TextureType::T_CARD_5, "res/tex/Melody_Faces.png", 4, 4);
	addTexture(TextureType::T_CARD_3, "res/tex/Echo_Faces.png", 4, 4);

	addTexture(TextureType::TEXTURE_SKYBOX, "res/tex/Skybox.png");
	addTexture(TextureType::PERLIN_NOISE, "res/tex/perlin_displacement.png");

	addTexture(TextureType::TS_TILESET, "res/tex/test.png");

	addTexture(TextureType::TEXTURE_TEST, "res/tex/clearing_bottom.png");
	addTexture(TextureType::TEXTURE_TEST_2, "res/tex/clearing_middle.png");
	addTexture(TextureType::TEXTURE_TEST_3, "res/tex/clearing_top.png");
	addTexture(TextureType::TEXTURE_TEST_4, "res/tex/clearing_water.png");

	addTexture(TextureType::T_UI_DECOR, "res/tex/UIDecoration.png", 4, 4);

	addTexture(TextureType::ARROW_TEXTURE, "res/tex/Arrow.png");
	addTexture(TextureType::T_MUSIC_NOTE, "res/tex/MusicNote.png");


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

	states = { a::IDLE};
	structs = { aa{ 0,4,2, -1}};
	addSpriteSheet(TextureType::T_CARD_4, "res/tex/torch.png", 1, 4, states, structs);

	states = { a::IDLE };
	structs = { aa{ 0,4,2, -1 } };
	addSpriteSheet(TextureType::SPRITESHEET_ECHO, "res/tex/Echo_SS.png", 1, 3, states, structs);
}


