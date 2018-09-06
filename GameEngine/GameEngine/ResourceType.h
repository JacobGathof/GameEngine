#pragma once


enum class GraphType {
	MAIN,
	SECONDARY,
	TERNARY,
};


enum class ShaderType {
	ANIMATED_SHADER,
	TEXT_SHADER,
	BASIC_SHADER,
	PARTICLE_SHADER,

	PARTICLE_COMPUTE_SHADER,
	PARTICLE_FAST_SHADER,
	UI_SOLID_SHADER,
	UI_IMAGE_SHADER,
	TERRAIN_SHADER,
	CIRCLE_SHADER,
	POST_PROCESS_SHADER,
	RECTANGLE_SHADER,
	LIGHT_SHADER,
	SHADOW_SHADER,

	WATER_SHADER,

	LINE_SHADER,

	TEXT_WORLD_SHADER,

	TEST_SHADER_1,
	TEST_SHADER_2,
	TEST_SHADER_3,
};

class TextureTypeT{
	static constexpr const char* DAGON = "Dagon";
};

enum class TextureType {
	TEXTURE_DEFAULT,
	T_SOLID_WHITE,


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
	SPRITESHEET_ECHO,

	SWORD_ICON,
	TERRAIN_SHEET,

	T_CARD_GHOST,
	T_CARD_ACE,
	T_CARD_2,
	T_CARD_3,
	T_CARD_4,
	T_CARD_5,
	T_CARD_WATER_WORKS,


	TEXTURE_SKYBOX,
	PERLIN_NOISE,

	//Start new Textures
	MAIN_TREE_PINK_3,
	MUSHROOM,
	FLOWER,
	FLOWER_2,
	FLOWER_3,
	FALLEN_TREE,

	//End new Textures

	TS_TILESET,
	TEXTURE_TEST,
	TEXTURE_TEST_2,
	TEXTURE_TEST_3,
	TEXTURE_TEST_4,

	ARROW_TEXTURE,
	T_SIGN_POST,
	T_MUSIC_NOTE,


	T_UI_DECOR,
	TEXTURE_TEST_5,
	TEXTURE_TEST_6,
	TEXTURE_TEST_7,
	TEXTURE_TEST_8,

};


enum class FramebufferType {
	DEFAULT,
	UI_BUFFER,
	EFFECTS_BUFFER,
	OBJECT_BUFFER,
	TERRAIN_BUFFER,
	EXTRA_BUFFER_1,
};





enum class FontType {
	DEFAULT,
	ITALIC
};


enum class ModelType {
	MODEL_SQUARE,
	MODEL_SQUARE_CENTERED,
};

enum class AudioType {
	SOUND_A_NOTE,
	SOUND_A_SHARP_NOTE,

	SONG_FMAB_AGAIN,
	SONG_1,
	SONG_2,
};


enum class CardType {
	FIREBALL,
	ICECYCLE,
	UNLIMITED_WATERWORKS,
	SHOCK,
	LIGHTNING,
	STORM,
	SHADOW_STEP,
	PLANE_WALK,
	TRANSMISSION,
	MOONLIGHT,
	TWILIGHT,
	DAWN,
	EXCALIBUR,
	BOULDER
};

enum class DeckType {
	TEST,
};


enum class ArmorType {
	BASIC_HELMET,
	BASIC_BOOTS,
	BASIC_LEGGINGS,
	BASIC_CHEST,
};

enum class KeyItemType {
	PANDORA_SOUL
};

enum class WeaponType {
	BOW,
	SWORD,
	SPEAR,
};