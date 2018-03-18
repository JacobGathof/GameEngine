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
	grass2,
	grass4,
	grass7,
	grass3,
	grass8,
	grass5,
	grass6,
	grass1,
	grass9,
	zc_cliffright,
	zc_watergrassbottom,
	zc_watergrasstopright,
	zc_water,
	zc_watergrassleft,
	zc_watergrasstop,
	ze_watergrasstopright,
	zc_watergrassright,
	zc_clifftopmidback,
	zc_clifftoprightback,
	zc_cliffmidfront,
	zc_cliffmidright,
	zc_cliffleftmid,
	zc_cliffbottommidback,
	zc_cliffbottomrightback,
	zb_topLeftGrassDirt,
	grassTop2,
	grassTop1,
	grassTop3,
	zc_clifftopleftback,
	zd_waterfalltopleft,
	zd_waterfalltopright,
	grassLeft3,
	dirt1,
	dirt2,
	dirt3,
	dirt6,
	dirt4,
	dirt5,
	zc_cliffmidleft,
	zd_waterfallmidleft,
	zd_waterfallmiddleright,
	grassLeft1,
	ze_dirtgrasstopleft,
	grassBottom1,
	grassBottom2,
	grassBottom3,
	grassRight2,
	grassLeft2,
	grassRight1,
	zc_cliffbottomleftback,
	zd_waterfallbottomleft,
	zd_waterfallbottomright,
	grassRight3,
	ze_dirtgrassbottomright,
	zb_bottomRightGrassDirt,


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

