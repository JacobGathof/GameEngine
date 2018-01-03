#include "FontManager.h"

std::map<FontType, Font*> FontManager::fonts;

void FontManager::init(){
	addFont(FontType::DEFAULT, "res_test/font.fnt", "res_test/font.png");
}

void FontManager::clean(){
	for (auto f : fonts) {
		delete f.second;
	}
}

Font * FontManager::get(FontType type)
{
	return fonts[type];
}

void FontManager::addFont(FontType ft, char* fnt, char* png){
	Font * font = new Font(fnt, png);
	fonts[ft] = font;
}
