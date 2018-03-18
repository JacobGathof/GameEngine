#include "TextureManager.h"


std::map<TextureType, SpriteSheet*> TextureManager::textures;

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
	addTexture(TextureType::grass2, "res/tex/TestTex/za-Grass/grass2.png");
	addTexture(TextureType::grass2, "res/tex/TestTex/za-Grass/grass2.png");
	addTexture(TextureType::grass4, "res/tex/TestTex/za-Grass/grass4.png");
	addTexture(TextureType::grass7, "res/tex/TestTex/za-Grass/grass7.png");
	addTexture(TextureType::grass3, "res/tex/TestTex/za-Grass/grass3.png");
	addTexture(TextureType::grass8, "res/tex/TestTex/za-Grass/grass8.png");
	addTexture(TextureType::grass5, "res/tex/TestTex/za-Grass/grass5.png");
	addTexture(TextureType::grass6, "res/tex/TestTex/za-Grass/grass6.png");
	addTexture(TextureType::grass1, "res/tex/TestTex/za-Grass/grass1.png");
	addTexture(TextureType::grass9, "res/tex/TestTex/za-Grass/grass9.png");
	addTexture(TextureType::zc_cliffright, "res/tex/TestTex/zc-cliff right.png");
	addTexture(TextureType::zc_watergrassbottom, "res/tex/TestTex/zc-water grass bottom.png");
	addTexture(TextureType::zc_watergrasstopright, "res/tex/TestTex/zc-water grass top right.png");
	addTexture(TextureType::zc_water, "res/tex/TestTex/zc-water.png");
	addTexture(TextureType::zc_watergrassleft, "res/tex/TestTex/zc-water grass left.png");
	addTexture(TextureType::zc_watergrasstop, "res/tex/TestTex/zc-water grass top.png");
	addTexture(TextureType::ze_watergrasstopright, "res/tex/TestTex/ze-water grass top right.png");
	addTexture(TextureType::zc_watergrassright, "res/tex/TestTex/zc-water grass right.png");
	addTexture(TextureType::zc_clifftopmidback, "res/tex/TestTex/zc-cliff top mid back.png");
	addTexture(TextureType::zc_clifftoprightback, "res/tex/TestTex/zc-cliff top right back.png");
	addTexture(TextureType::zc_cliffmidfront, "res/tex/TestTex/zc-cliff mid front.png");
	addTexture(TextureType::zc_cliffmidright, "res/tex/TestTex/zc-cliff mid right.png");
	addTexture(TextureType::zc_cliffleftmid, "res/tex/TestTex/zc-cliff left mid.png");
	addTexture(TextureType::zc_cliffbottommidback, "res/tex/TestTex/zc-cliff bottom mid back.png");
	addTexture(TextureType::zc_cliffbottomrightback, "res/tex/TestTex/zc-cliff bottom right back.png");
	addTexture(TextureType::zb_topLeftGrassDirt, "res/tex/TestTex/zb-topLeftGrassDirt.png");
	addTexture(TextureType::grassTop2, "res/tex/TestTex/za-GrassPathTop/grassTop2.png");
	addTexture(TextureType::grassTop1, "res/tex/TestTex/za-GrassPathTop/grassTop1.png");
	addTexture(TextureType::grassTop3, "res/tex/TestTex/za-GrassPathTop/grassTop3.png");
	addTexture(TextureType::zc_clifftopleftback, "res/tex/TestTex/zc-cliff top left back.png");
	addTexture(TextureType::zd_waterfalltopleft, "res/tex/TestTex/zd-waterfall top left.png");
	addTexture(TextureType::zd_waterfalltopright, "res/tex/TestTex/zd-waterfall top right.png");
	addTexture(TextureType::grassLeft3, "res/tex/TestTex/za-GrassPathLeft/grassLeft3.png");
	addTexture(TextureType::dirt1, "res/tex/TestTex/za-Dirt/dirt1.png");
	addTexture(TextureType::dirt2, "res/tex/TestTex/za-Dirt/dirt2.png");
	addTexture(TextureType::dirt3, "res/tex/TestTex/za-Dirt/dirt3.png");
	addTexture(TextureType::dirt6, "res/tex/TestTex/za-Dirt/dirt6.png");
	addTexture(TextureType::dirt4, "res/tex/TestTex/za-Dirt/dirt4.png");
	addTexture(TextureType::dirt5, "res/tex/TestTex/za-Dirt/dirt5.png");
	addTexture(TextureType::zc_cliffmidleft, "res/tex/TestTex/zc-cliff mid left.png");
	addTexture(TextureType::zd_waterfallmidleft, "res/tex/TestTex/zd-waterfall mid left.png");
	addTexture(TextureType::zd_waterfallmiddleright, "res/tex/TestTex/zd-waterfall middle right.png");
	addTexture(TextureType::grassLeft1, "res/tex/TestTex/za-GrassPathLeft/grassLeft1.png");
	addTexture(TextureType::ze_dirtgrasstopleft, "res/tex/TestTex/ze-dirt grass top left.png");
	addTexture(TextureType::grassBottom1, "res/tex/TestTex/za-GrassBottomPath/grassBottom1.png");
	addTexture(TextureType::grassBottom2, "res/tex/TestTex/za-GrassBottomPath/grassBottom2.png");
	addTexture(TextureType::grassBottom3, "res/tex/TestTex/za-GrassBottomPath/grassBottom3.png");
	addTexture(TextureType::grassRight2, "res/tex/TestTex/za-GrassRightPath/grassRight2.png");
	addTexture(TextureType::grassLeft2, "res/tex/TestTex/za-GrassPathLeft/grassLeft2.png");
	addTexture(TextureType::grassRight1, "res/tex/TestTex/za-GrassRightPath/grassRight1.png");
	addTexture(TextureType::zc_cliffbottomleftback, "res/tex/TestTex/zc-cliff bottom left back.png");
	addTexture(TextureType::zd_waterfallbottomleft, "res/tex/TestTex/zd-waterfall bottom left.png");
	addTexture(TextureType::zd_waterfallbottomright, "res/tex/TestTex/zd-waterfall bottom right.png");
	addTexture(TextureType::grassRight3, "res/tex/TestTex/za-GrassRightPath/grassRight3.png");
	addTexture(TextureType::ze_dirtgrassbottomright, "res/tex/TestTex/ze-dirt grass bottom right.png");
	addTexture(TextureType::zb_bottomRightGrassDirt, "res/tex/TestTex/zb-bottomRightGrassDirt.png");


}

void TextureManager::clean() {
	for (auto pair : textures) {
		delete pair.second;
	}
}

SpriteSheet * TextureManager::get(TextureType type)
{
	return textures[type];
}

void TextureManager::addTexture(TextureType tex, char * filename, int rows, int columns) {
	SpriteSheet * t = new SpriteSheet(filename, rows, columns);
	textures[tex] = t;
}
