#include "FontManager.h"


void FontManager::init(){
	addFont(FontType::DEFAULT, "res/fonts/font.fnt", "res/fonts/font.png");
	addFont(FontType::ITALIC, "res/fonts/ifont.fnt", "res/fonts/ifont.png");
}


void FontManager::addFont(FontType ft, char* fnt, char* png){
	Font * font = new Font(fnt, png);
	elements[ft] = font;
}
