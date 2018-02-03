#include "FontManager.h"

std::map<FontType, Font*> FontManager::fonts;

void FontManager::init(){
	addFont(FontType::DEFAULT, "res/fonts/font.fnt", "res/fonts/font.png");
	addFont(FontType::ITALIC, "res/fonts/ifont.fnt", "res/fonts/ifont.png");
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
